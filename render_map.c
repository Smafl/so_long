/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:55:16 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/05 19:11:29 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

static void	my_keyhook(void *param)
{
	mlx_t			*mlx;
	t_map_render	*map_render;

	map_render = (t_map_render *)param;
	mlx = map_render->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map_render->mlx);
}

static void	put_image(
	t_map_render *map_render, t_map_params *map_params, int *i)
{
	if (map_params->map[*i] == EXIT)
		mlx_image_to_window(map_render->mlx, map_render->exit, x, y);
	else if (map_params->map[*i] == SPACE)
		mlx_image_to_window(map_render->mlx, map_render->floor, x, y);
}

static void	render_map(t_map_render *map_render, t_map_params *map_params)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (x != map_params->width * STEP)
	{
		while (y != (map_params->height) * STEP)
		{
			put_image(map_render, map_params, &i);
			i++;
			y += STEP;
		}
		y = 0;
		put_image(map_render, map_params, &i);
		i++;
		x += STEP;
	}

}

void	initialize_image(t_map_render *map_render, t_map_params *map_params)
{
	map_render->mlx = mlx_init
		(map_params->width * STEP - STEP,
			map_params->height * STEP, "So__game", true);
	map_render->floor_texture = mlx_load_png("img/floor_32.png");
	map_render->floor = mlx_texture_to_image(
			map_render->mlx, map_render->floor_texture);
	map_render->exit_texture = mlx_load_png("img/exit_32.png");
	map_render->exit = mlx_texture_to_image(
			map_render->mlx, map_render->exit_texture);
	render_map(map_render, map_params);
	mlx_loop_hook(map_render->mlx, &my_keyhook, map_render);
	mlx_loop(map_render->mlx);
}
