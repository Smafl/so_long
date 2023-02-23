/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:35:58 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/23 03:15:24 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_H
# define PRIVATE_H

# include "so_long.h"
# include "lib/get_next_line/get_next_line.h"
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/libft/libft.h"

typedef struct s_params
{
	char	**map;
}	t_params;

// read_map.c
void	read_map(int fd, t_params *params);

#endif
