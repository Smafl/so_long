/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:35:58 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/25 14:59:20 by ekulichk         ###   ########.fr       */
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
	ERROR
}	t_map_component;

typedef struct s_params
{
	t_map_component	*map;
	int				width;
	int				height;
	size_t			map_capacity;
	size_t			count;
}	t_params;

// read_map.c
void			map_extend(t_params *params);
void			push(t_params *params, t_map_component component);
void			map_init(t_params *self);
t_map_component	convert_char(char c);
bool			read_map(t_params *params, int fd);
// void	map_add_line(t_params *params, char *line);
// void	print_map(t_params *params);

#endif
