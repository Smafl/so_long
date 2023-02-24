/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:35:58 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/24 18:21:55 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_H
# define PRIVATE_H

# include "so_long.h"
# include "lib/get_next_line/get_next_line.h"
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/libft/libft.h"

typedef enum e_map_component
{
	SPACE = 0,
	WALL = 1,
	COLLECTIBLE = 'C',
	EXIT = 'E',
	PLAYER = 'P',
}	t_map_component;

typedef struct s_params
{
	// t_map_component	**map;
	char			**map;
	size_t			map_capacity;
	size_t			count;
	int				len_line;
	int				flag;
}	t_params;

// read_map.c
void	read_map(int fd, t_params *params);
void	map_add_line(t_params *params, char *line);
void	map_extend(t_params *params);
void	map_init(t_params *self);
void	print_map(t_params *params);

#endif
