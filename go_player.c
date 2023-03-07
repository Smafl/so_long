/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:41:57 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/07 21:03:49 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

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
