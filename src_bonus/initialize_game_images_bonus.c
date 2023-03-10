/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game_images_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:01:35 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/10 13:33:32 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_bonus.h"

static void	initialize_texture(t_map_params *map_params)
{
	map_params->map_render->floor_texture = mlx_load_png("img/floor_32.png");
	map_params->map_render->exit_texture = mlx_load_png("img/exit_32.png");
	map_params->map_render->open_exit_texture = mlx_load_png(
			"img/open_exit_32.png");
	map_params->map_render->collectible_texture = mlx_load_png(
			"img/collectible_32.png");
	map_params->map_render->wall_texture = mlx_load_png("img/wall_32.png");
	map_params->map_render->p_down_texture = mlx_load_png(
			"img/p_down_32.png");
	map_params->map_render->p_up_texture = mlx_load_png(
			"img/p_up_32.png");
	map_params->map_render->p_right_texture = mlx_load_png(
			"img/p_right_32.png");
	map_params->map_render->p_left_texture = mlx_load_png(
			"img/p_left_32.png");
	map_params->map_render->enemy_texture = mlx_load_png(
			"img/enemy_32.png");
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
	map_params->map_render->p_down = mlx_texture_to_image(
			map_params->map_render->mlx,
			map_params->map_render->p_down_texture);
	map_params->map_render->p_up = mlx_texture_to_image(
			map_params->map_render->mlx,
			map_params->map_render->p_up_texture);
	map_params->map_render->p_right = mlx_texture_to_image(
			map_params->map_render->mlx,
			map_params->map_render->p_right_texture);
	map_params->map_render->p_left = mlx_texture_to_image(
			map_params->map_render->mlx,
			map_params->map_render->p_left_texture);
}

static void	initialize_image_bonus(t_map_params *map_params)
{
	map_params->map_render->enemy = mlx_new_image(
			map_params->map_render->mlx, 32, 32);
}

void	initialize_game_images(t_map_params *map_params)
{
	map_params->map_render = malloc(sizeof(t_map_render));
	map_params->map_render->mlx = mlx_init(map_params->width * STEP,
			map_params->height * STEP, "Welcome to Kupchino", true);
	initialize_texture(map_params);
	initialize_image(map_params);
	initialize_image_bonus(map_params);
	render_map(map_params);
	mlx_image_to_window(
		map_params->map_render->mlx, map_params->map_render->enemy,
		map_params->enemy_x, map_params->enemy_y);
}
