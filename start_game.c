/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:38:50 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/07 21:43:49 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

void	start_game(t_map_params *map_params)
{
	initialize_game_images(map_params);
	// mlx_loop_hook(
	// 	map_params->map_render->mlx, &my_loop_hook, map_params);
	mlx_key_hook(
		map_params->map_render->mlx, (mlx_keyfunc) my_keyhook, map_params);
	mlx_loop(map_params->map_render->mlx);
}
