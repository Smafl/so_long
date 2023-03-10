/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:50:23 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/11 12:18:07 by ekulichk         ###   ########.fr       */
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
	if (!map_verify(map_params))
		return (false);
	return (true);
}

bool	read_bytes_check(
	t_map_params *map_params, int *read_bytes, int *width, char c)
{
	if (*read_bytes == -1)
	{
		perror("Error\nread() failed");
		return (false);
	}
	else if (*width == 0 && c == '\n')
	{
		ft_printf("Error\nthere is an empty line in a map\n");
		return (false);
	}
	else
	{
		if (!map_fill_in(map_params, c, read_bytes, width))
			return (false);
	}
	return (true);
}

bool	map_verify(t_map_params *map_params)
{
	if (!map_component_check(map_params))
	{
		ft_printf("Error\nwrong components in a map\n");
		return (false);
	}
	if (!map_up_down_wall_check(map_params)
		|| !(map_left_right_wall_check(map_params)))
	{
		ft_printf("Error\nwall is broken\n");
		return (false);
	}
	if (!path_exists(map_params))
	{
		ft_printf("Error\nthere is no valid path in a map for player\n");
		return (false);
	}
	return (true);
}
