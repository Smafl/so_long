/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:50:23 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/26 00:58:04 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>


bool	read_map(t_params *params, int fd)
{
	int				width;
	int				read_bytes;
	char			c;
	t_map_component	component;

	width = 0;
	map_init(params);
	read_bytes = 1;
	while (read_bytes == 1)
	{
		read_bytes = read(fd, &c, 1);
		if (read_bytes == -1)
		{
			perror("read() failed");
			return (false);
		}
		if (read_bytes != 0 && c != '\n')
		{
			component = convert_char(c);
			if (component == ERROR)
			{
				printf("Error: wrong map component\n");
				return (false);
			}
			push(params, component);
			width += 1;
		}
		else
		{
			params->height += 1;
			if (params->width == 0)
				params->width = width;
			else if (params->width != width)
			{
				printf("Error: map is not rectangular\n");
				return (false);
			}
			width = 0;
		}
	}
	return (true);
}

t_map_component	convert_char(char c)
{
	if (c == '0')
		return (SPACE);
	else if (c == '1')
		return (WALL);
	else if (c == 'C')
		return (COLLECTIBLE);
	else if (c == 'E')
		return (EXIT);
	else if (c == 'P')
		return (PLAYER);
	else
		return (ERROR);
}

// check empty strings
