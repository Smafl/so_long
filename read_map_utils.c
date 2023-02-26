/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 00:47:48 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/26 00:58:00 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

void	map_extend(t_params *params)
{
	t_map_component	*new_map;
	size_t			new_capacity;

	new_capacity = params->map_capacity * 2;
	new_map = malloc(sizeof(t_map_component) * new_capacity);
	ft_memcpy(
		new_map, params->map, sizeof(t_map_component) * params->map_capacity);
	params->map = new_map;
	params->map_capacity = new_capacity;
}

void	map_push(t_params *params, t_map_component component)
{
	if (params->map_capacity == params->count)
		map_extend(params);
	params->map[params->count] = component;
	params->count += 1;
}

void	map_init(t_params *params)
{
	params->height = 0;
	params->width = 0;
	params->map_capacity = 1;
	params->count = 0;
	params->map = malloc(sizeof(t_map_component) * params->map_capacity);
}
