/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:14:58 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/05 19:08:09 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	sl_map_path_check(char *argv)
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
	t_map_render	map_render;

	if (argc <= 1)
	{
		ft_printf("Error\nexpected a map in format *.ber\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (read(fd, NULL, 0) < 0)
		perror("Error\nread() failed");
	else if (sl_map_path_check(argv[1]))
	{
		// delete print
		ft_printf("ok\n");
		read_map(&map_params, fd);
		initialize_image(&map_render, &map_params);
	}
	else
	{
		ft_printf("Error\nwrong file, expected a map in format *.ber\n");
	}
	close(fd);
	free_map(&map_params);
	free_visited(&map_params);
	// system("leaks so_long");
	return (0);
}
