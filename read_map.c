/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:50:23 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/23 03:19:48 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include <stdio.h>

void	read_map(int fd, t_params *params)
{
	int		len;
	char	*line;

	*params->map = get_next_line(fd);
	len = ft_strlen(line);
	printf("%s\n", *params->map);
}
