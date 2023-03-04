/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 10:47:48 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/04 10:49:03 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

t_map_component	get_cell(t_map_params *map_params, int x, int y)
{
	int	index;

	index = y * map_params->width + x;
	return (map_params->map[index]);
}

int	get_index(t_map_params *map_params, int x, int y)
{
	return (y * map_params->width + x);
}
