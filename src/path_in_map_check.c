/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_in_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:56:31 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/05 14:06:24 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include <stdio.h>
#include <stdbool.h>

static void	visited_init(t_map_params *map_params)
{
	map_params->visited = malloc(
			sizeof(bool) * map_params->width * map_params->height);
	if (map_params->visited == NULL)
	{
		free_map(map_params);
		free_visited(map_params);
		perror("Error\nmalloc() failed:");
	}
	ft_bzero(
		map_params->visited, sizeof(
			bool) * map_params->width * map_params->height);
}

static bool	is_visited(t_map_params *map_params, int x, int y)
{
	return (map_params->visited[get_index(map_params, x, y)]);
}

static void	set_visited(t_map_params *map_params, int x, int y)
{
	map_params->visited[get_index(map_params, x, y)] = 1;
}

static void	dfs(t_map_params *map_params, int x, int y)
{
	if (get_cell(map_params, x, y) == WALL)
		return ;
	if (is_visited(map_params, x, y))
		return ;
	set_visited(map_params, x, y);
	dfs(map_params, x, y + 1);
	dfs(map_params, x + 1, y);
	dfs(map_params, x, y - 1);
	dfs(map_params, x - 1, y);
}

bool	path_exists(t_map_params *map_params)
{
	int	index;

	index = 0;
	visited_init(map_params);
	dfs(map_params, map_params->player_x, map_params->player_y);
	while (index < map_params->width * map_params->height)
	{
		if (map_params->map[index] == EXIT
			|| map_params->map[index] == COLLECTIBLE)
		{
			if (!map_params->visited[index])
				return (false);
		}
		index++;
	}
	return (true);
}
