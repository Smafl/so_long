/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:55:16 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/06 18:33:06 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

void	put_image(t_map_params *map_params, int *x, int *y)
{
	int	index;

	index = get_index(map_params, *x / 32, *y / 32);
	if (map_params->map[index] == WALL)
	{
		mlx_image_to_window(
			map_params->map_render->mlx, map_params->map_render->floor, *x, *y);
		mlx_image_to_window(
			map_params->map_render->mlx, map_params->map_render->wall, *x, *y);
	}
	else if (map_params->map[index] == SPACE)
		mlx_image_to_window(
			map_params->map_render->mlx, map_params->map_render->floor, *x, *y);
	else if (map_params->map[index] == EXIT)
	{
		mlx_image_to_window(
			map_params->map_render->mlx, map_params->map_render->floor, *x, *y);
		mlx_image_to_window(
			map_params->map_render->mlx, map_params->map_render->exit, *x, *y);
	}
	else if (map_params->map[index] == COLLECTIBLE)
	{
		mlx_image_to_window(
			map_params->map_render->mlx, map_params->map_render->floor, *x, *y);
		mlx_image_to_window(
			map_params->map_render->mlx,
			map_params->map_render->collectible, *x, *y);
	}
	else if (map_params->map[index] == PLAYER)
	{
		mlx_image_to_window(
			map_params->map_render->mlx, map_params->map_render->floor, *x, *y);
		mlx_image_to_window(
			map_params->map_render->mlx,
			map_params->map_render->p_stand, *x, *y);
	}
}

void	render_map(t_map_params *map_params)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x != map_params->width * STEP)
	{
		while (y != map_params->height * STEP)
		{
			put_image(map_params, &x, &y);
			y += STEP;
		}
		y = 0;
		put_image(map_params, &x, &y);
		x += STEP;
	}
}
