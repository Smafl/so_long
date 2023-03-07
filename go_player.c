/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:41:57 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/07 20:20:33 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

static void	take_collectibles(t_map_params *map_params)
{
	int				i;
	mlx_instance_t	*temp;

	i = 0;
	map_params->map[get_index(map_params, map_params->player_x / STEP,
			map_params->player_y / STEP)] = SPACE;
	temp = map_params->map_render->collectible->instances;
	while (i < map_params->map_render->collectible->count)
	{
		if (temp[i].x == map_params->player_x
			&& temp[i].y == map_params->player_y)
			map_params->map_render->collectible->instances[i].z = 0;
		i++;
	}
	map_params->collected++;
}

void	go_right(mlx_key_data_t keydata, t_map_params *map_params)
{
	if (keydata.action == MLX_REPEAT || keydata.action == MLX_RELEASE)
	{
		if (get_cell(map_params, map_params->player_x / STEP + 1,
				map_params->player_y / STEP) == WALL)
				;
		else if (get_cell(map_params, map_params->player_x / STEP + 1,
				map_params->player_y / STEP) == OPEN_EXIT)
				;
		else if (get_cell(map_params, map_params->player_x / STEP,
				map_params->player_y / STEP) == COLLECTIBLE)
		{
			take_collectibles(map_params);
			movement_right(map_params);
		}
		else
			movement_right(map_params);
	}
}

void	go_left(mlx_key_data_t keydata, t_map_params *map_params)
{
	if (keydata.action == MLX_REPEAT || keydata.action == MLX_RELEASE)
	{
		if (get_cell(map_params, map_params->player_x / STEP - 1,
				map_params->player_y / STEP) == WALL)
				;
		else if (get_cell(map_params, map_params->player_x / STEP - 1,
				map_params->player_y / STEP) == OPEN_EXIT)
				;
		else if (get_cell(map_params, map_params->player_x / STEP,
				map_params->player_y / STEP) == COLLECTIBLE)
		{
			take_collectibles(map_params);
			movement_left(map_params);
		}
		else
			movement_left(map_params);
	}
}

void	go_down(mlx_key_data_t keydata, t_map_params *map_params)
{
	if (keydata.action == MLX_REPEAT || keydata.action == MLX_RELEASE)
	{
		if (get_cell(map_params, map_params->player_x / STEP,
				map_params->player_y / STEP + 1) == WALL)
				;
		else if (get_cell(map_params, map_params->player_x / STEP,
				map_params->player_y / STEP + 1) == OPEN_EXIT)
				;
		else if (get_cell(map_params, map_params->player_x / STEP,
				map_params->player_y / STEP) == COLLECTIBLE)
		{
			take_collectibles(map_params);
			movement_down(map_params);
		}
		else
			movement_down(map_params);
	}
}

void	go_up(mlx_key_data_t keydata, t_map_params *map_params)
{
	if (keydata.action == MLX_REPEAT || keydata.action == MLX_RELEASE)
	{
		if (get_cell(map_params, map_params->player_x / STEP,
				map_params->player_y / STEP - 1) == WALL)
				;
		else if (get_cell(map_params, map_params->player_x / STEP,
				map_params->player_y / STEP - 1) == OPEN_EXIT)
				;
		else if (get_cell(map_params, map_params->player_x / STEP,
				map_params->player_y / STEP) == COLLECTIBLE)
		{
			take_collectibles(map_params);
			movement_up(map_params);
		}
		else
			movement_up(map_params);
	}
}
