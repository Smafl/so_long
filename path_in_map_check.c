/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_in_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:56:31 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/03 20:25:04 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include <stdbool.h>

static bool	is_visited(t_map_params *map_params, int x, int y)
{
	int	index;

	index = y * map_params->width + x;
}

void	dfs(int x, int y)
{
	if (is_visited(x, y))
		return ;
	set_visited(x, y);
}

// static void	set_visited(int x, int y)
// {
// 	;
// }


bool	path_exists(t_map_params *map_params)
{
	visited_init(map_params);
	dfs(map_params->player_x, map_params->player_y);
	return (true);
}

void	visited_init(t_map_params *map_params)
{
	map_params->visited = malloc(
			sizeof(int *) * map_params->width * map_params->height);
	ft_bzero(map_params->visited, map_params->width * map_params->height);
}

/*
void dfs_visit(int x, int y) {
  if (is_visited(x, y)) {
    return;
  }  
  set_visited(x, y);
  for (x_next, y_next) in neighbors(x, y) {
    if (!is_wall(x_next, y_next)) {
      dfs_visit(x_next, y_next);
    }
  }
}

bool path_exists(int x, int y_start, int x_finish, int y_f {
  dfs_visit(x, y);
  return is_visited(x_finish, y_finish);
}
*/