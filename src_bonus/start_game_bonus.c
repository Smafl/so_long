/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:38:50 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/08 15:49:44 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_bonus.h"

int	start_game(t_map_params *map_params, int fd)
{
	if (!read_map(map_params, fd))
	{
		free_map(map_params);
		free_visited(map_params);
		return (1);
	}
	initialize_game_images(map_params);
	mlx_key_hook(
		map_params->map_render->mlx, (mlx_keyfunc) my_keyhook, map_params);
	mlx_loop(map_params->map_render->mlx);
	end_game(map_params);
	return (0);
}

static void	initialize_texture(t_map_params *map_params)
{
	map_params->map_render->floor_texture = mlx_load_png("img/floor_32.png");
	map_params->map_render->exit_texture = mlx_load_png("img/exit_32.png");
	map_params->map_render->open_exit_texture = mlx_load_png(
			"img/open_exit_32.png");
	map_params->map_render->collectible_texture = mlx_load_png(
			"img/collectible_32.png");
	map_params->map_render->wall_texture = mlx_load_png("img/wall_32.png");
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

void	render_map(t_map_params *map_params)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x != map_params->width * STEP)
	{
		while (y != map_params->height * STEP)
		{
			put_images(map_params, &x, &y);
			y += STEP;
		}
		y = 0;
		put_images(map_params, &x, &y);
		x += STEP;
	}
}
