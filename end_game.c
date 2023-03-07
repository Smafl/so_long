/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:03:51 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/07 21:17:59 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

void	take_collectibles(t_map_params *map_params)
{
	int				i;
	mlx_instance_t	*temp;

	i = 0;
	map_params->map[get_index(map_params, map_params->player_x / STEP,
			map_params->player_y / STEP)] = SPACE;
	temp = map_params->map_render->collectible->instances;
	while (i < map_params->map_render->collectible->count)
	{
		if (temp[i].x == map_params->player_x
			&& temp[i].y == map_params->player_y)
			map_params->map_render->collectible->instances[i].z = 0;
		i++;
	}
	map_params->collected++;
	check_collectibles(map_params);
}

void	check_collectibles(t_map_params *map_params)
{
	if (map_params->collectibles == map_params->collected)
	{
		map_params->map_render->exit->instances->z = 1;
		mlx_image_to_window(
			map_params->map_render->mlx, map_params->map_render->floor,
			map_params->exit_x, map_params->exit_y);
		mlx_set_instance_depth(&map_params->map_render->floor->instances[
			map_params->map_render->floor->count - 1], 2);
		map_params->map_render->open_exit->instances->z = 3;
	}
	end_game(map_params);
}

void	end_game(t_map_params *map_params)
{
	if (map_params->player_x == map_params->exit_x
		&& map_params->player_y == map_params->exit_y)
	{
		free_map(map_params);
		free_visited(map_params);
		free_map_render(map_params);
		mlx_terminate(map_params->map_render->mlx);
	}
}
