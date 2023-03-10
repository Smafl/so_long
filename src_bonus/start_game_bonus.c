/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:38:50 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/10 19:09:35 by ekulichk         ###   ########.fr       */
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
	mlx_loop_hook(map_params->map_render->mlx, loop, map_params);
	mlx_loop(map_params->map_render->mlx);
	end_game(map_params);
	return (0);
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

/*
Each pixel is 4 bytes.
The first three bytes represent the RGB colors values and
the fourth byte represents the alpha value.

Before setting the color, the function checks the alpha channel:
if it's zero then the pixel is fully transparent, the function
skips this pixel.
*/