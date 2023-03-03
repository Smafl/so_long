/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:50:23 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/03 19:27:06 by ekulichk         ###   ########.fr       */
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
	if (!map_up_down_wall_check(map_params)
		|| !(map_left_right_wall_check(map_params)))
	{
		ft_printf("Error: wrong walls\n");
		return (false);
	}
	if (!path_exists(map_params))
		ft_printf("not visited list\n");
	return (true);
}
