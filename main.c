/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:14:58 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/19 15:14:13 by ekulichk         ###   ########.fr       */
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

	len = ft_strlen(argv) - 4;
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*result;

	if (argc <= 0)
		printf("no arguments was given, expected one\n");
	else
	{
		if (sl_map_path_check(argv))
			printf("correct path or file\n");
		else
			printf("incorrect path or file\n");
	}
	fd = open(argv[1], O_RDONLY);
	result = get_next_line(fd);
	close(fd);
	printf("%s", result);
	// system("leaks a.out");
	return (0);
}
