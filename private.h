/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:35:58 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/26 00:57:57 by ekulichk         ###   ########.fr       */
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
	SPACE,
	WALL,
	COLLECTIBLE,
	EXIT,
	PLAYER,
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
t_map_component	convert_char(char c);
bool			read_map(t_params *params, int fd);

// read_map_utils.c
void			map_extend(t_params *params);
void			map_push(t_params *params, t_map_component component);
void			map_init(t_params *self);


#endif
