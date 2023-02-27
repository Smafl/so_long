/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:50:23 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/27 18:29:01 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

bool	read_map(t_map_params *map_params, int fd)
{
	int				width;
	int				read_bytes;
	char			c;

	width = 0;
	map_init(map_params);
	read_bytes = 1;
	while (read_bytes == 1)
	{
		read_bytes = read(fd, &c, 1);
		if (!read_bytes_check(map_params, &read_bytes, &width, c))
			return (false);
	}
	if (!map_component_check(map_params))
	{
		ft_printf("Error: not all components\n");
		return (false);
	}
	if (!map_wall_check(map_params))
		return (false);
	return (true);
}
