/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:35:58 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/04 10:49:01 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_H
# define PRIVATE_H

# include "so_long.h"
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/ft_printf/ft_printf.h"
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

typedef struct s_map_params
{
	t_map_component	*map;
	t_map_component	component;
	size_t			map_capacity;
	size_t			count;
	int				width;
	int				height;
	int				collectibles;
	int				exit;
	int				player;
	int				player_x;
	int				player_y;
	bool			*visited;
}	t_map_params;

// read_map.c
// read a map from FD and call functions for verify map's components
bool					read_map(t_map_params *map_params, int fd);

// read_map_utils.c
void					map_init(t_map_params *self);
bool					map_fill_in(
							t_map_params *map_params,
							char c, int *read_bytes, int *width);
t_map_component			convert_char(
							t_map_params *map_params, char c, int *width);
void					map_push(t_map_params *map_params);
void					map_extend(t_map_params *map_params);

// map_check.c
// functions for verify map's components
bool					read_bytes_check(
							t_map_params *map_params,
							int *read_bytes, int *width, char c);
bool					map_component_check(t_map_params *map_params);
bool					map_up_down_wall_check(t_map_params *map_params);
bool					map_left_right_wall_check(t_map_params *map_params);

// map_check_utils.c
t_map_component			get_cell(t_map_params *map_params, int x, int y);
int						get_index(t_map_params *map_params, int x, int y);

// path_in_map_check.c
// verify a valid path in a map
bool					path_exists(t_map_params *map_params);

#endif
