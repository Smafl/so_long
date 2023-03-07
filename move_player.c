/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:52:31 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/07 21:46:01 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

void	movement_right(t_map_params *map_params)
{
	map_params->map_render->p_stand->instances->x += STEP;
	map_params->player_x += STEP;
	map_params->steps_counter++;
	ft_printf("Number of movements: %d\n", map_params->steps_counter);
	if (map_params->player_x == map_params->exit_x
		&& map_params->player_y == map_params->exit_y)
		end_game(map_params);
}

void	movement_left(t_map_params *map_params)
{
	map_params->map_render->p_stand->instances->x -= STEP;
	map_params->player_x -= STEP;
	map_params->steps_counter++;
	ft_printf("Number of movements: %d\n", map_params->steps_counter);
	if (map_params->player_x == map_params->exit_x
		&& map_params->player_y == map_params->exit_y)
		end_game(map_params);
}

void	movement_down(t_map_params *map_params)
{
	map_params->map_render->p_stand->instances->y += STEP;
	map_params->player_y += STEP;
	map_params->steps_counter++;
	ft_printf("Number of movements: %d\n", map_params->steps_counter);
	if (map_params->player_x == map_params->exit_x
		&& map_params->player_y == map_params->exit_y)
		end_game(map_params);
}

void	movement_up(t_map_params *map_params)
{
	map_params->map_render->p_stand->instances->y -= STEP;
	map_params->player_y -= STEP;
	map_params->steps_counter++;
	ft_printf("Number of movements: %d\n", map_params->steps_counter);
	if (map_params->player_x == map_params->exit_x
		&& map_params->player_y == map_params->exit_y)
		end_game(map_params);
}
