/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:50:23 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/25 15:44:59 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include <stdio.h>
#include <stdbool.h>

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

void	push(t_params *params, t_map_component component)
{
	if (params->map_capacity == params->count)
		extend(params);
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

bool	read_map(t_params *params, int fd)
{
	int				width;
	int				read_bytes;
	char			c;
	t_map_component	component;

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
				printf("Wring map\n");
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
				printf("Wrong map\n");
				return (false);
			}
			width = 0;
		}
	}
	return (true);
}

// check empty strings