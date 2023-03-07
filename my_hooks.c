/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:32:40 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/07 19:40:16 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

// void	my_loop_hook(void *param)
// {
// 	mlx_t			*map_params->map_render->mlx;
// 	t_map_params	*map_params;

// 	map_params = (t_map_params *)param;
// 	map_params->map_render->mlx = map_params->map_render->map_params->map_render->mlx;
// 	if (mlx_is_key_down(map_params->map_render->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(map_params->map_render->map_params->map_render->mlx);
// }

void	my_keyhook(mlx_key_data_t keydata, t_map_params *map_params)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(map_params->map_render->mlx);
	if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		go_right(keydata, map_params);
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		go_left(keydata, map_params);
	if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		go_down(keydata, map_params);
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		go_up(keydata, map_params);
}
