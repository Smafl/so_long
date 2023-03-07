/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:14:58 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/07 18:03:34 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int	file_path_check(char *argv)
{
	int		i;
	int		len;
	char	*ber;

	i = 0;
	ber = ".ber";
	len = ft_strlen(argv) - 4;
	while (i != 5)
	{
		if (argv[len + i] != ber[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int				fd;
	t_map_params	map_params;

	if (argc <= 1)
	{
		ft_printf("Error\nexpected a map in format *.ber\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (read(fd, NULL, 0) < 0)
		perror("Error\nread() failed");
	else if (file_path_check(argv[1]))
	{
		if (!read_map(&map_params, fd))
		{
			free_map(&map_params);
			free_visited(&map_params);
			close(fd);
			return (1);
		}
		start_game(&map_params);
		free_map(&map_params);
		free_visited(&map_params);
		free_map_render(&map_params);
	}
	else
		ft_printf("Error\nwrong file, expected a map in format *.ber\n");
	close(fd);
	// system("leaks so_long");
	return (0);
}
