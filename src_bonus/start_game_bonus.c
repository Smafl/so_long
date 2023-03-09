/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:38:50 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/09 17:14:49 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_bonus.h"

void	draw_sprite(mlx_image_t *img, mlx_texture_t *tex, int offset)
{
	int	x;
	int	y;
	int	index_img;
	int	index_tex;

	y = 0;
	while (y < STEP)
	{
		x = 0;
		while (x < STEP)
		{
			index_img = (y * STEP + x) * 4;
			index_tex = (y * STEP * 9 + x + offset * STEP) * 4;
			img->pixels[index_img + 0] = tex->pixels[index_tex + 0];
			img->pixels[index_img + 1] = tex->pixels[index_tex + 1];
			img->pixels[index_img + 2] = tex->pixels[index_tex + 2];
			img->pixels[index_img + 3] = tex->pixels[index_tex + 3];
			x++;
		}
		y++;
	}
}

void	loop(void *param)
{
	t_map_params	*map_params;

	map_params = param;
	(void) map_params;
	if (map_params->sprite_index % 16 == 0)
		draw_sprite(
			map_params->map_render->enemy,
			map_params->map_render->enemy_texture,
			(map_params->sprite_index / 16) % 9);
	map_params->sprite_index++;
}

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
	mlx_loop_hook(map_params->map_render->mlx, loop, map_params);
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
	// render_map(map_params);
	mlx_image_to_window(map_params->map_render->mlx, map_params->map_render->enemy, 0, 32);
	mlx_set_instance_depth(map_params->map_render->enemy->instances, 0);
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
	put_steps_counter(map_params);
}
