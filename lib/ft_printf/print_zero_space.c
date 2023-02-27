/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zero_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:05:31 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/27 16:57:24 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

int	ftp_zero(int width)
{
	int	printf_len;

	printf_len = 0;
	while (width != 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		width--;
		printf_len++;
	}
	return (printf_len);
}

int	ftp_space(int width)
{
	int	printf_len;

	printf_len = 0;
	while (width != 0)
	{
		if (write(1, " ", 1) == -1)
			return (-1);
		width--;
		printf_len++;
	}
	return (printf_len);
}
