/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:52:31 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/07 17:52:43 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

void	movement_right(t_map_params *param)
{
	param->map_render->p_stand->instances->x += STEP;
	param->player_x += STEP;
	param->steps_counter++;
}

void	movement_left(t_map_params *param)
{
	param->map_render->p_stand->instances->x -= STEP;
	param->player_x -= STEP;
	param->steps_counter++;
}

void	movement_down(t_map_params *param)
{
	param->map_render->p_stand->instances->y += STEP;
	param->player_y += STEP;
	param->steps_counter++;
}

void	movement_up(t_map_params *param)
{
	param->map_render->p_stand->instances->y -= STEP;
	param->player_y -= STEP;
	param->steps_counter++;
}
