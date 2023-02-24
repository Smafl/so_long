/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:50:23 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/24 18:26:39 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include <stdio.h>

void	read_map(int fd, t_params *params)
{
	char	*line;

	map_init(params);
	line = get_next_line(fd);
	params->len_line = ft_strlen(line);
	params->flag = 0;
	while (params->flag == 0)
	{
		line = get_next_line(fd);
		if (ft_strlen(line) != params->len_line)
		{
			printf("Wrong map\n");
			return (0);
		}
		else if (line == NULL)
			params->flag = 1;
	}
	map_add_line(params, line);
	print_map(params);
}

void	map_add_line(t_params *params, char *line)
{
	if (params->map_capacity == params->count)
		map_extend(params);
	params->map[params->count] = line;
	params->count += 1;
}

void	map_extend(t_params *params)
{
	char	**new_map;
	size_t	new_capacity;

	new_capacity = params->map_capacity * 2;
	new_map = malloc(sizeof(char *) * new_capacity);
	ft_memcpy(new_map, params->map, params->map_capacity);
	params->map = new_map;
	params->map_capacity = new_capacity;
}

void	map_init(t_params *params)
{
	params->map_capacity = 1;
	params->count = 0;
	params->map = malloc(sizeof(char *) * params->map_capacity);
}

void	print_map(t_params *params)
{
	printf("%s", params->map[0]);
	// printf("%s", params->map[1]);
	// printf("%s", params->map[2]);
}
