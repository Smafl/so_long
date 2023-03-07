/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:41:57 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/07 19:14:33 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

void	go_right(mlx_key_data_t keydata, t_map_params *param)
{
	if (keydata.action == MLX_RELEASE)
	{
		if (get_cell(param, param->player_x / STEP + 1,
				param->player_y / STEP) == WALL)
				;
		else if (get_cell(param, param->player_x / STEP + 1,
				param->player_y / STEP) == OPEN_EXIT)
				;
		else if (get_cell(param, param->player_x / STEP,
				param->player_y / STEP) == COLLECTIBLE)
		{
			param->collected++;
			movement_right(param);
		}
		else
			movement_right(param);
	}
}

void	go_left(mlx_key_data_t keydata, t_map_params *param)
{
	if (keydata.action == MLX_RELEASE)
	{
		if (get_cell(param, param->player_x / STEP - 1,
				param->player_y / STEP) == WALL)
				;
		else if (get_cell(param, param->player_x / STEP - 1,
				param->player_y / STEP) == OPEN_EXIT)
				;
		else if (get_cell(param, param->player_x / STEP,
				param->player_y / STEP) == COLLECTIBLE)
		{
			param->collected++;
			movement_left(param);
		}
		else
			movement_left(param);
	}
}

void	go_down(mlx_key_data_t keydata, t_map_params *param)
{
	if (keydata.action == MLX_RELEASE)
	{
		if (get_cell(param, param->player_x / STEP,
				param->player_y / STEP + 1) == WALL)
				;
		else if (get_cell(param, param->player_x / STEP,
				param->player_y / STEP + 1) == OPEN_EXIT)
				;
		else if (get_cell(param, param->player_x / STEP,
				param->player_y / STEP) == COLLECTIBLE)
		{
			param->collected++;
			movement_down(param);
		}
		else
			movement_down(param);
	}
}

void	go_up(mlx_key_data_t keydata, t_map_params *param)
{
	if (keydata.action == MLX_RELEASE)
	{
		if (get_cell(param, param->player_x / STEP,
				param->player_y / STEP - 1) == WALL)
				;
		else if (get_cell(param, param->player_x / STEP,
				param->player_y / STEP - 1) == OPEN_EXIT)
				;
		else if (get_cell(param, param->player_x / STEP,
				param->player_y / STEP) == COLLECTIBLE)
		{
			param->collected++;
			movement_up(param);
		}
		else
			movement_up(param);
	}
}
