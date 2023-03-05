/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:16:09 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/05 14:03:13 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

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
