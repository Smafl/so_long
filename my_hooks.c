/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:32:40 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/07 18:13:04 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

// void	my_loop_hook(void *param)
// {
// 	mlx_t			*mlx;
// 	t_map_params	*map_params;

// 	map_params = (t_map_params *)param;
// 	mlx = map_params->map_render->mlx;
// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(map_params->map_render->mlx);
// }

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	mlx_t			*mlx;
	t_map_params	*map_params;

	map_params = (t_map_params *)param;
	mlx = map_params->map_render->mlx;
	// if (map_params->collectibles == map_params->collected)
	// {
	// 	mlx_image_to_window(
	// 		map_params->map_render->mlx, map_params->map_render->floor,
	// 		map_params->exit_x, map_params->exit_y);
	// 	mlx_set_instance_depth(&map_params->map_render->floor->instances[
	// 		map_params->map_render->floor->count - 1], 1);
	// 	mlx_image_to_window(
	// 		map_params->map_render->mlx, map_params->map_render->open_exit,
	// 		map_params->exit_x, map_params->exit_y);
	// }
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(mlx);
	if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		go_right(keydata, param);
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		go_left(keydata, param);
	if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		go_down(keydata, param);
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		go_up(keydata, param);
}
