/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_player_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:41:57 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/10 14:58:21 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_bonus.h"

void	my_keyhook(mlx_key_data_t keydata, t_map_params *map_params)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(map_params->map_render->mlx);
		return ;
	}
	if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		go_right(keydata, map_params);
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		go_left(keydata, map_params);
	if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		go_down(keydata, map_params);
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		go_up(keydata, map_params);
}

void	go_right(mlx_key_data_t keydata, t_map_params *map_params)
{
	if (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS)
	{
		if (get_cell(map_params, map_params->player_x / STEP + 1,
				map_params->player_y / STEP) == WALL)
				;
		else if (get_cell(map_params, map_params->player_x / STEP + 1,
				map_params->player_y / STEP) == COLLECTIBLE)
		{
			movement_right(map_params);
			take_collectibles(map_params);
		}
		else
			movement_right(map_params);
	}
}

void	go_left(mlx_key_data_t keydata, t_map_params *map_params)
{
	if (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS)
	{
		if (get_cell(map_params, map_params->player_x / STEP - 1,
				map_params->player_y / STEP) == WALL)
				;
		else if (get_cell(map_params, map_params->player_x / STEP - 1,
				map_params->player_y / STEP) == COLLECTIBLE)
		{
			movement_left(map_params);
			take_collectibles(map_params);
		}
		else
			movement_left(map_params);
	}
}

void	go_down(mlx_key_data_t keydata, t_map_params *map_params)
{
	if (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS)
	{
		if (get_cell(map_params, map_params->player_x / STEP,
				map_params->player_y / STEP + 1) == WALL)
				;
		else if (get_cell(map_params, map_params->player_x / STEP,
				map_params->player_y / STEP + 1) == COLLECTIBLE)
		{
			movement_down(map_params);
			take_collectibles(map_params);
		}
		else
			movement_down(map_params);
	}
}

void	go_up(mlx_key_data_t keydata, t_map_params *map_params)
{
	if (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS)
	{
		if (get_cell(map_params, map_params->player_x / STEP,
				map_params->player_y / STEP - 1) == WALL)
				;
		else if (get_cell(map_params, map_params->player_x / STEP,
				map_params->player_y / STEP - 1) == COLLECTIBLE)
		{
			movement_up(map_params);
			take_collectibles(map_params);
		}
		else
			movement_up(map_params);
	}
}
