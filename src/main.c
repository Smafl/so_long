/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:14:58 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/08 12:27:59 by ekulichk         ###   ########.fr       */
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
		start_game(&map_params, fd);
	else
		ft_printf("Error\nwrong file, expected a map in format *.ber\n");
	close(fd);
	return (0);
}
// system("leaks so_long");
