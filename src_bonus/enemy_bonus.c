/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:30:45 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/10 13:33:19 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_bonus.h"
#include <math.h>

void	loop(void *param)
{
	t_map_params	*map_params;
	int				new_y;

	map_params = param;
	if (map_params->sprite_index % 16 == 0)
		draw_sprite(
			map_params->map_render->enemy,
			map_params->map_render->enemy_texture,
			(map_params->sprite_index / 16) % 9);
	map_params->sprite_index++;
	map_params->map_render->enemy->instances[0].x += 1;
	map_params->enemy_x += 1;
	if (map_params->map_render->enemy->instances[0].x
		>= map_params->width * STEP)
	{
		map_params->map_render->enemy->instances[0].x = -STEP;
		map_params->enemy_x = -STEP;
		new_y = (rand() % (map_params->height - 2) + 1) * STEP;
		map_params->map_render->enemy->instances[0].y = new_y;
		map_params->enemy_y = new_y;
	}
	touch_enemy(map_params);
}

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

void	touch_enemy(t_map_params *map_params)
{
	if (map_params->player_x == map_params->enemy_x
		&& map_params->player_y == map_params->enemy_y)
	{
		end_game(map_params);
	}
}
