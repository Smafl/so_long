/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:16:09 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/08 15:11:05 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_bonus.h"

void	free_map(t_map_params *map_params)
{
	free(map_params->map);
	map_params->map = NULL;
}

void	free_visited(t_map_params *map_params)
{
	free(map_params->visited);
	map_params->visited = NULL;
}

static void	free_texture(t_map_params *map_params)
{
	mlx_delete_texture(map_params->map_render->floor_texture);
	mlx_delete_texture(map_params->map_render->exit_texture);
	mlx_delete_texture(map_params->map_render->open_exit_texture);
	mlx_delete_texture(map_params->map_render->collectible_texture);
	mlx_delete_texture(map_params->map_render->wall_texture);
	mlx_delete_texture(map_params->map_render->p_stand_texture);
}

static void	free_image(t_map_params *map_params)
{
	mlx_delete_image
		(map_params->map_render->mlx, map_params->map_render->floor);
	mlx_delete_image(map_params->map_render->mlx, map_params->map_render->exit);
	mlx_delete_image(
		map_params->map_render->mlx, map_params->map_render->open_exit);
	mlx_delete_image(
		map_params->map_render->mlx, map_params->map_render->collectible);
	mlx_delete_image(map_params->map_render->mlx, map_params->map_render->wall);
	mlx_delete_image(
		map_params->map_render->mlx, map_params->map_render->p_stand);
}

void	free_map_render(t_map_params *map_params)
{
	free_texture(map_params);
	free_image(map_params);
	free(map_params->map_render);
	map_params->map_render = NULL;
}
