/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:41:54 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/01 20:54:04 by ekulichk         ###   ########.fr       */
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

// bool	map_wall_check(t_map_params *map_params)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (x < map_params->width)
// 	{
// 		if (get_cell(map_params, x, y) != WALL)
// 		{
// 			ft_printf("Error: wall up");
// 			// return (false);
// 		}
// 		x++;
// 	}
// 	while (y < map_params->height - 1)
// 	{
// 		if (get_cell(map_params, x, y) != WALL)
// 		{
// 			ft_printf("Error: wall left");
// 			// return (false);
// 		}
// 		y++;
// 	}
// 	x = 1;
// 	while (x < map_params->width)
// 	{
// 		if (get_cell(map_params, x, y) != WALL)
// 		{
// 			ft_printf("Error: wall down");
// 			// return (false);
// 		}
// 		x++;
// 	}
// 	y = 1;
// 	while (y < map_params->height - 1)
// 	{
// 		if (get_cell(map_params, x - 1, y) != WALL)
// 		{
// 			ft_printf("Error: wall right");
// 			// return (false);
// 		}
// 		y++;
// 	}
// 	return (true);
// }

// bool	map_wall_check(t_map_params *map_params)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (x <= map_params->width && y < map_params->height - 1)
// 	{
// 		if (get_cell(map_params, x, y) != WALL)
// 		{
// 			ft_printf("Error: wall up/left");
// 			return (false);
// 		}
// 		if (x == map_params->width && y < map_params->height - 1)
// 		{
// 			if (get_cell(map_params, x - 1, y) != WALL)
// 			{
// 				ft_printf("Error: wall right");
// 				return (false);
// 			}
// 		}
// 		if (x < map_params->width)
// 			x++;
// 		else
// 			y++;
// 	}
// 	x = 1;
// 	while (x < map_params->width)
// 	{
// 		if (get_cell(map_params, x, y) != WALL)
// 		{
// 			ft_printf("Error: wall down");
// 			return (false);
// 		}
// 		x++;
// 	}
// 	return (true);
// }

bool	map_up_down_wall_check(t_map_params *map_params)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < map_params->width)
	{
		if (get_cell(map_params, x, y) != WALL)
		{
			ft_printf("Error: wall up");
			return (false);
		}
		x++;
	}
	x = 1;
	y = map_params->height - 1;
	while (x < map_params->width)
	{
		if (get_cell(map_params, x, y) != WALL)
		{
			ft_printf("Error: wall down");
			return (false);
		}
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
		{
			ft_printf("Error: wall left");
			return (false);
		}
		y++;
	}
	y = 1;
	while (y < map_params->height - 1)
	{
		if (get_cell(map_params, x - 1, y) != WALL)
		{
			ft_printf("Error: wall right");
			return (false);
		}
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

/*
-index 0
-index 1
-index 2
-index 3
-index 4
-index 8
-index 12
-index 13
-index 14
-index 15
-index 7
-index 11

up x: 0, y: 0
index 0
up x: 1, y: 0
index 1
up x: 2, y: 0
index 2
up x: 3, y: 0
index 3

left x: 4, y: 0
index 4
left x: 4, y: 1
index 8
left x: 4, y: 2
index 12

down x: 1, y: 3
index 13
down x: 2, y: 3
index 14
down x: 3, y: 3
index 15

right x: 4, y: 1
index 7
right x: 4, y: 2
index 11

1 x: 0, y: 0
index 0
1 x: 1, y: 0
index 1
1 x: 2, y: 0
index 2
1 x: 3, y: 0
index 3
1 x: 4, y: 0
index 4
1 x: 4, y: 1
index 8
1 x: 4, y: 2
index 12

2 x: 1, y: 3
index 13
2 x: 2, y: 3
index 14
2 x: 3, y: 3
index 15

3 x: 4, y: 1
index 7
3 x: 4, y: 2
index 11
*/