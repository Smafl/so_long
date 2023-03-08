/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:35:58 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/08 13:46:38 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_H
# define PRIVATE_H

# include "so_long.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"

# ifndef STEP
#  define STEP 32
# endif

typedef enum e_map_component
{
	SPACE,
	WALL,
	COLLECTIBLE,
	PLAYER,
	EXIT,
	OPEN_EXIT,
	ERROR
}	t_map_component;

typedef struct s_map_render
{
	mlx_t			*mlx;
	mlx_texture_t	*floor_texture;
	mlx_texture_t	*exit_texture;
	mlx_texture_t	*open_exit_texture;
	mlx_texture_t	*collectible_texture;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*p_stand_texture;
	mlx_image_t		*floor;
	mlx_image_t		*exit;
	mlx_image_t		*open_exit;
	mlx_image_t		*collectible;
	mlx_image_t		*wall;
	mlx_image_t		*p_stand;
}	t_map_render;

typedef struct s_map_params
{
	t_map_component	*map;
	t_map_component	component;
	size_t			map_capacity;
	size_t			count;
	int				width;
	int				height;
	int				collectibles;
	int				collected;
	int				exit;
	int				exit_x;
	int				exit_y;
	int				player;
	int				player_x;
	int				player_y;
	int				steps_counter;
	bool			*visited;
	t_map_render	*map_render;
}	t_map_params;

// read_map.c
// read a map from FD and call functions for verify map's components
bool					read_map(t_map_params *map_params, int fd);
bool					read_bytes_check(
							t_map_params *map_params,
							int *read_bytes, int *width, char c);
bool					map_verify(t_map_params *map_params);

// read_map_utils.c
int						map_init(t_map_params *self);
bool					map_fill_in(
							t_map_params *map_params,
							char c, int *read_bytes, int *width);
t_map_component			convert_char(
							t_map_params *map_params, char c, int *width);
void					map_push(t_map_params *map_params);
void					map_extend(t_map_params *map_params);

// map_check.c
// functions for verify map's components
bool					map_component_check(t_map_params *map_params);
bool					map_up_down_wall_check(t_map_params *map_params);
bool					map_left_right_wall_check(t_map_params *map_params);
t_map_component			get_cell(t_map_params *map_params, int x, int y);
int						get_index(t_map_params *map_params, int x, int y);

// path_in_map_check.c
// verify a valid path in a map
bool					path_exists(t_map_params *map_params);

// start_game.c
int						start_game(t_map_params *map_params, int fd);
void					initialize_game_images(t_map_params *map_params);
void					render_map(t_map_params *map_params);

// put_images.c
void					put_images(t_map_params *map_params, int *x, int *y);
void					put_player(t_map_params *map_params, int *x, int *y);
void					put_exit(t_map_params *map_params, int *x, int *y);
void					put_collectible(
							t_map_params *map_params, int *x, int *y);
void					put_floor(t_map_params *map_params, int *x, int *y);

// go_player.c
void					my_keyhook(
							mlx_key_data_t keydata, t_map_params *map_params);
void					go_right(
							mlx_key_data_t keydata, t_map_params *map_params);
void					go_left(
							mlx_key_data_t keydata, t_map_params *map_params);
void					go_down(
							mlx_key_data_t keydata, t_map_params *map_params);
void					go_up(mlx_key_data_t keydata, t_map_params *map_params);

// move_player.c
void					movement_right(t_map_params *map_params);
void					movement_left(t_map_params *map_params);
void					movement_down(t_map_params *map_params);
void					movement_up(t_map_params *map_params);

// end_game.c
void					take_collectibles(t_map_params *map_params);
void					end_game(t_map_params *map_params);

// free_map.c
void					free_map(t_map_params *map_params);
void					free_visited(t_map_params *map_params);
void					free_map_render(t_map_params *map_params);

#endif
