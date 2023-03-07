/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:03:51 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/07 21:52:38 by ekulichk         ###   ########.fr       */
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
			map_params->map_render->collectible->instances[i].enabled = false;
		i++;
	}
	map_params->collected++;
	check_collectibles(map_params);
}

void	check_collectibles(t_map_params *map_params)
{
	if (map_params->collectibles == map_params->collected)
	{
		map_params->map_render->exit->instances->enabled = false;
		map_params->map_render->open_exit->instances->enabled = true;
	}
}

void	end_game(t_map_params *map_params)
{
	mlx_terminate(map_params->map_render->mlx);
	free_map(map_params);
	free_visited(map_params);
	free_map_render(map_params);
	exit(EXIT_SUCCESS);
}
