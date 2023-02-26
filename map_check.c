/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:41:54 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/26 16:56:30 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include <stdio.h>
#include <stdbool.h>

bool	read_bytes_check(
	t_map_params *map_params, int *read_bytes, int *width, char c)
{
	if (*read_bytes == -1)
	{
		perror("read() failed");
		return (false);
	}
	else if (*width == 0 && c == '\n')
	{
		printf("Error: wrong map\n");
		return (false);
	}
	else
	{
		if (!map_fill_in(map_params, c, read_bytes, width))
			return (false);
	}
	return (true);
}

// bool	map_wall_check(t_map_params *params)

bool	map_component_check(t_map_params *map_params)
{
	if (!(FLAG_COLLECTIBLE & map_params->flags))
		return (false);
	if (!(FLAG_EXIT & map_params->flags))
		return (false);
	if (!(FLAG_PLAYER & map_params->flags))
		return (false);
	return (true);
}
