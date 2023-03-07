/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:10:52 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/07 13:41:59 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

static void	initialize_texture(t_map_params *map_params)
{
	map_params->map_render->floor_texture = mlx_load_png("img/floor_32.png");
	map_params->map_render->exit_texture = mlx_load_png("img/exit_32.png");
	map_params->map_render->open_exit_texture = mlx_load_png(
			"img/open_exit_32.png");
	map_params->map_render->collectible_texture = mlx_load_png(
			"img/collectible_32.png");
	map_params->map_render->wall_texture = mlx_load_png("img/wall2_32.png");
	map_params->map_render->p_stand_texture = mlx_load_png(
			"img/p_stand_32.png");
}

static void	initialize_image(t_map_params *map_params)
{
	map_params->map_render->floor = mlx_texture_to_image(
			map_params->map_render->mlx, map_params->map_render->floor_texture);
	map_params->map_render->exit = mlx_texture_to_image(
			map_params->map_render->mlx, map_params->map_render->exit_texture);
	map_params->map_render->open_exit = mlx_texture_to_image(
			map_params->map_render->mlx,
			map_params->map_render->open_exit_texture);
	map_params->map_render->collectible = mlx_texture_to_image(
			map_params->map_render->mlx,
			map_params->map_render->collectible_texture);
	map_params->map_render->wall = mlx_texture_to_image(
			map_params->map_render->mlx, map_params->map_render->wall_texture);
	map_params->map_render->p_stand = mlx_texture_to_image(
			map_params->map_render->mlx,
			map_params->map_render->p_stand_texture);
}

void	initialize_game_images(t_map_params *map_params)
{
	map_params->map_render = malloc(sizeof(t_map_render));
	map_params->map_render->mlx = mlx_init(map_params->width * STEP,
			map_params->height * STEP, "Welcome to Kupchino", true);
	initialize_texture(map_params);
	initialize_image(map_params);
	render_map(map_params);
}
