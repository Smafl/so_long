/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:14:58 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/27 17:56:41 by ekulichk         ###   ########.fr       */
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

	if (argc <= 1)
	{
		ft_printf("Expected one more argument\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		perror("open() failed");
	else if (sl_map_path_check(argv[1]))
	{
		// delete print
		ft_printf("ok\n");
		read_map(&map_params, fd);
	}
	else
	{
		ft_printf("Wrong file, expected .ber\n");
	}
	close(fd);
	// system("leaks a.out");
	return (0);
}
