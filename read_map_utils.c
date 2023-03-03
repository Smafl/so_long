/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:42:13 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/03 19:54:12 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include <stdio.h>
#include <stdbool.h>

void	map_init(t_map_params *map_params)
{
	map_params->map_capacity = 1;
	map_params->count = 0;
	map_params->map = malloc(
			sizeof(t_map_component) * map_params->map_capacity);
	map_params->height = 0;
	map_params->width = 0;
	map_params->collectibles = 0;
	map_params->exit = 0;
	map_params->player = 0;
}

bool	map_fill_in(
	t_map_params *map_params, char c, int *read_bytes, int *width)
{
	if (*read_bytes != 0 && c != '\n')
	{
		map_params->component = convert_char(map_params, c, width);
		if (map_params->component == ERROR)
		{
			ft_printf("Error: wrong map components\n");
			return (false);
		}
		map_push(map_params);
		*width += 1;
	}
	else
	{
		map_params->height += 1;
		if (map_params->width == 0)
			map_params->width = *width;
		else if (map_params->width != *width)
		{
			ft_printf("Error: map is not rectangular\n");
			return (false);
		}
		*width = 0;
	}
	return (true);
}

t_map_component	convert_char(t_map_params *map_params, char c, int *width)
{
	if (c == '0')
		return (SPACE);
	else if (c == '1')
		return (WALL);
	else if (c == 'C')
	{
		map_params->collectibles += 1;
		return (COLLECTIBLE);
	}
	else if (c == 'E')
	{
		map_params->exit += 1;
		return (EXIT);
	}
	else if (c == 'P')
	{
		map_params->player += 1;
		map_params->player_x = *width;
		map_params->player_y = map_params->height;
		return (PLAYER);
	}
	else
		return (ERROR);
}

void	map_push(t_map_params *map_params)
{
	if (map_params->map_capacity == map_params->count)
		map_extend(map_params);
	map_params->map[map_params->count] = map_params->component;
	map_params->count += 1;
}

void	map_extend(t_map_params *map_params)
{
	t_map_component	*new_map;
	size_t			new_capacity;

	new_capacity = map_params->map_capacity * 2;
	new_map = malloc(sizeof(t_map_component) * new_capacity);
	ft_memcpy(
		new_map, map_params->map,
		sizeof(t_map_component) * map_params->map_capacity);
	map_params->map = new_map;
	map_params->map_capacity = new_capacity;
}
