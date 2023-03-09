/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:52:31 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/09 14:34:31 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_bonus.h"

void	set_color(mlx_image_t *img, uint8_t r, uint8_t g, uint8_t b)
{
	uint32_t	i;

	i = img->width * img->height;
	while (i--)
	{
		if (img->pixels[i * 4 + 3] == 0)
			continue ;
		img->pixels[i * 4 + 0] = r;
		img->pixels[i * 4 + 1] = g;
		img->pixels[i * 4 + 2] = b;
	}
}

void	put_steps_counter(t_map_params *map_params)
{
	char	*steps_str;

	steps_str = ft_itoa(map_params->steps_counter);
	if (map_params->steps_counter > 0)
		mlx_delete_image(map_params->map_render->mlx,
			map_params->map_render->steps);
	map_params->map_render->steps = mlx_put_string(
			map_params->map_render->mlx, steps_str, 0, 0);
	set_color(map_params->map_render->steps, 255, 255, 0);
	mlx_image_to_window(map_params->map_render->mlx,
		map_params->map_render->steps, 0, 0);
	mlx_set_instance_depth(map_params->map_render->steps->instances, 1);
	free(steps_str);
}

void	movement_right(t_map_params *map_params)
{
	map_params->map_render->p_down->instances->x += STEP;
	map_params->map_render->p_up->instances->x += STEP;
	map_params->map_render->p_right->instances->x += STEP;
	map_params->map_render->p_left->instances->x += STEP;
	map_params->map_render->p_down->instances->enabled = false;
	map_params->map_render->p_up->instances->enabled = false;
	map_params->map_render->p_right->instances->enabled = true;
	map_params->map_render->p_left->instances->enabled = false;
	map_params->player_x += STEP;
	map_params->steps_counter++;
	if (map_params->map[get_index(map_params, map_params->exit_x / STEP,
				map_params->exit_y / STEP)] == OPEN_EXIT)
	{
		if (map_params->player_x == map_params->exit_x
			&& map_params->player_y == map_params->exit_y)
			end_game(map_params);
	}
	put_steps_counter(map_params);
}

void	movement_left(t_map_params *map_params)
{
	map_params->map_render->p_down->instances->x -= STEP;
	map_params->map_render->p_up->instances->x -= STEP;
	map_params->map_render->p_right->instances->x -= STEP;
	map_params->map_render->p_left->instances->x -= STEP;
	map_params->map_render->p_down->instances->enabled = false;
	map_params->map_render->p_up->instances->enabled = false;
	map_params->map_render->p_right->instances->enabled = false;
	map_params->map_render->p_left->instances->enabled = true;
	map_params->player_x -= STEP;
	map_params->steps_counter++;
	if (map_params->map[get_index(map_params, map_params->exit_x / STEP,
				map_params->exit_y / STEP)] == OPEN_EXIT)
	{
		if (map_params->player_x == map_params->exit_x
			&& map_params->player_y == map_params->exit_y)
			end_game(map_params);
	}
	put_steps_counter(map_params);
}

void	movement_down(t_map_params *map_params)
{
	map_params->map_render->p_down->instances->y += STEP;
	map_params->map_render->p_up->instances->y += STEP;
	map_params->map_render->p_right->instances->y += STEP;
	map_params->map_render->p_left->instances->y += STEP;
	map_params->map_render->p_down->instances->enabled = true;
	map_params->map_render->p_up->instances->enabled = false;
	map_params->map_render->p_right->instances->enabled = false;
	map_params->map_render->p_left->instances->enabled = false;
	map_params->player_y += STEP;
	map_params->steps_counter++;
	if (map_params->map[get_index(map_params, map_params->exit_x / STEP,
				map_params->exit_y / STEP)] == OPEN_EXIT)
	{
		if (map_params->player_x == map_params->exit_x
			&& map_params->player_y == map_params->exit_y)
			end_game(map_params);
	}
	put_steps_counter(map_params);
}

void	movement_up(t_map_params *map_params)
{
	map_params->map_render->p_down->instances->y -= STEP;
	map_params->map_render->p_up->instances->y -= STEP;
	map_params->map_render->p_right->instances->y -= STEP;
	map_params->map_render->p_left->instances->y -= STEP;
	map_params->map_render->p_down->instances->enabled = false;
	map_params->map_render->p_up->instances->enabled = true;
	map_params->map_render->p_right->instances->enabled = false;
	map_params->map_render->p_left->instances->enabled = false;
	map_params->player_y -= STEP;
	map_params->steps_counter++;
	if (map_params->map[get_index(map_params, map_params->exit_x / STEP,
				map_params->exit_y / STEP)] == OPEN_EXIT)
	{
		if (map_params->player_x == map_params->exit_x
			&& map_params->player_y == map_params->exit_y)
			end_game(map_params);
	}
	put_steps_counter(map_params);
}
