/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:32:40 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/06 18:47:43 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

void	keyhook(mlx_key_data_t keydata, void *param)
{
	mlx_t			*mlx;
	t_map_params	*map_params;

	map_params = (t_map_params *)param;
	mlx = map_params->map_render->mlx;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(mlx);
	// if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	// 	mlx_close_window(map_params->map_render->mlx);
	
}
