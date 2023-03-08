/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:23:13 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/08 15:10:01 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_bonus.h"

void	put_images(t_map_params *map_params, int *x, int *y)
{
	int	index;

	index = get_index(map_params, *x / 32, *y / 32);
	if (map_params->map[index] == WALL)
		mlx_image_to_window(
			map_params->map_render->mlx, map_params->map_render->wall, *x, *y);
	else if (map_params->map[index] == SPACE)
		put_floor(map_params, x, y);
	else if (map_params->map[index] == EXIT)
		put_exit(map_params, x, y);
	else if (map_params->map[
			index] == COLLECTIBLE)
		put_collectible(map_params, x, y);
	else if (map_params->map[index] == PLAYER)
		put_player(map_params, x, y);
}

void	put_player(t_map_params *map_params, int *x, int *y)
{
	put_floor(map_params, x, y);
	mlx_image_to_window(map_params->map_render->mlx,
		map_params->map_render->p_stand, *x, *y);
	mlx_set_instance_depth(map_params->map_render->p_stand->instances, 3);
	map_params->player_x = *x;
	map_params->player_y = *y;
}

void	put_exit(t_map_params *map_params, int *x, int *y)
{
	put_floor(map_params, x, y);
	mlx_image_to_window(
		map_params->map_render->mlx, map_params->map_render->exit, *x, *y);
	mlx_set_instance_depth(map_params->map_render->exit->instances, 2);
	mlx_image_to_window(
		map_params->map_render->mlx, map_params->map_render->open_exit, *x, *y);
	mlx_set_instance_depth(map_params->map_render->open_exit->instances, 2);
	map_params->map_render->open_exit->instances->enabled = false;
	map_params->exit_x = *x;
	map_params->exit_y = *y;
}

void	put_collectible(t_map_params *map_params, int *x, int *y)
{
	put_floor(map_params, x, y);
	mlx_image_to_window(map_params->map_render->mlx,
		map_params->map_render->collectible, *x, *y);
	mlx_set_instance_depth(&map_params->map_render->collectible->instances[
		map_params->map_render->collectible->count - 1], 2);
}

void	put_floor(t_map_params *map_params, int *x, int *y)
{
	mlx_image_to_window(
		map_params->map_render->mlx, map_params->map_render->floor, *x, *y);
	mlx_set_instance_depth(&map_params->map_render->floor->instances[
		map_params->map_render->floor->count - 1], 1);
}
