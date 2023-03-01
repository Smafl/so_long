/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:35:58 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/01 20:50:12 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_H
# define PRIVATE_H

# include "so_long.h"
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/ft_printf/ft_printf.h"
# include "lib/libft/libft.h"

# define UP_WALL			0b0000001
# define DOWN_WALL			0b0000010
# define LEFT_WALL			0b0000100
# define RIGHT_WALL			0b0001000
# define FLAG_EXIT 			0b0010000
# define FLAG_PLAYER		0b0100000
# define FLAG_COLLECTIBLE	0b1000000

typedef enum e_map_component
{
	SPACE,
	WALL,
	COLLECTIBLE,
	EXIT,
	PLAYER,
	ERROR
}	t_map_component;

typedef struct s_map_params
{
	t_map_component	*map;
	t_map_component	component;
	int				flags;
	int				width;
	int				height;
	int				collectibles;
	int				exit;
	int				player;
	size_t			map_capacity;
	size_t			count;
}	t_map_params;

// map_check.c
bool					read_bytes_check(
							t_map_params *map_params,
							int *read_bytes, int *width, char c);
// bool					map_wall_check(t_map_params *map_params);
bool					map_up_down_wall_check(t_map_params *map_params);
bool					map_left_right_wall_check(t_map_params *map_params);
t_map_component			get_cell(t_map_params *map_params, int x, int y);
bool					map_component_check(t_map_params *map_params);

// read_map.c
bool					read_map(t_map_params *map_params, int fd);

// read_map_utils.c
bool					map_fill_in(
							t_map_params *map_params,
							char c, int *read_bytes, int *width);
t_map_component			convert_char(t_map_params *map_params, char c);
void					map_extend(t_map_params *map_params);
void					map_push(t_map_params *map_params);
void					map_init(t_map_params *self);

#endif
