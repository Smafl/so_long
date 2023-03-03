/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:41:54 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/02 11:52:39 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include <stdio.h>
#include <stdbool.h>

bool	read_bytes_check(
	t_map_params *map_params, int *read_bytes, int *width, char c)
{
	if (*read_bytes == -1)
	{
		perror("read() failed");
		return (false);
	}
	else if (*width == 0 && c == '\n')
	{
		ft_printf("Error: wrong map\n");
		return (false);
	}
	else
	{
		if (!map_fill_in(map_params, c, read_bytes, width))
			return (false);
	}
	return (true);
}

bool	map_component_check(t_map_params *map_params)
{
	if (map_params->collectibles < 1)
		return (false);
	if (!(map_params->exit == 1))
		return (false);
	if (!(map_params->player == 1))
		return (false);
	return (true);
}

bool	map_up_down_wall_check(t_map_params *map_params)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < map_params->width)
	{
		if (get_cell(map_params, x, y) != WALL)
			return (false);
		x++;
	}
	x = 1;
	y = map_params->height - 1;
	while (x < map_params->width)
	{
		if (get_cell(map_params, x, y) != WALL)
			return (false);
		x++;
	}
	return (true);
}

bool	map_left_right_wall_check(t_map_params *map_params)
{
	int	x;
	int	y;

	x = map_params->width;
	y = 0;
	while (y < map_params->height - 1)
	{
		if (get_cell(map_params, x, y) != WALL)
			return (false);
		y++;
	}
	y = 1;
	while (y < map_params->height - 1)
	{
		if (get_cell(map_params, x - 1, y) != WALL)
			return (false);
		y++;
	}
	return (true);
}

t_map_component	get_cell(t_map_params *map_params, int x, int y)
{
	int	index;

	index = y * map_params->width + x;
	ft_printf("index %d\n", index);
	return (map_params->map[index]);
}
