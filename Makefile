
CC = cc
NAME = so_long
NAME_BNS = so_long_bonus

SRC = src/end_game.c\
src/free_map.c\
src/go_player.c\
src/main.c\
src/map_check.c\
src/move_player.c\
src/path_in_map_check.c\
src/put_images.c\
src/read_map_utils.c\
src/read_map.c\
src/start_game.c

SRC_BNS = src_bonus/end_game_bonus.c\
src_bonus/free_map_bonus.c\
src_bonus/go_player_bonus.c\
src_bonus/main_bonus.c\
src_bonus/map_check_bonus.c\
src_bonus/move_player_bonus.c\
src_bonus/path_in_map_check_bonus.c\
src_bonus/put_images_bonus.c\
src_bonus/read_map_bonus.c\
src_bonus/read_map_utils_bonus.c\
src_bonus/start_game_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BNS = $(SRC_BNS:.c=.o)
MLX42 := ./lib/MLX42
FT_PRINTF := ./lib/ft_printf
LIBFT := ./lib/libft
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g
LDFLAGS = -L../LeakSanitizer -llsan -lc++ -Wno-gnu-include-next -I ../LeakSanitize
FSANFLAG += -fsanitize=address -Ofast

all: mlx ft_printf libft $(NAME)

bonus: mlx ft_printf libft $(NAME_BNS)

mlx:
	@$(MAKE) DEBUG=yes -C $(MLX42)

ft_printf:
	@$(MAKE) -C $(FT_PRINTF)

libft:
	@$(MAKE) -C $(LIBFT)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FSANFLAG) $(LDFLAGS) $(MLX42)/libmlx42.a $(FT_PRINTF)/ft_printf.a $(LIBFT)/libft.a -I include -lglfw -L "/Users/ekulichk/.brew/opt/glfw/lib/" -o $(NAME)

$(NAME_BNS): $(OBJ_BNS)
	$(CC) $(OBJ) $(FSANFLAG) $(LDFLAGS) $(MLX42)/libmlx42.a $(FT_PRINTF)/ft_printf.a $(LIBFT)/libft.a -I include -lglfw -L "/Users/ekulichk/.brew/opt/glfw/lib/" -o $(NAME)

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(MLX42) clean
	@$(MAKE) -C $(FT_PRINTF) clean
	@$(MAKE) -C $(LIBFT) clean

clean_bonus:
	rm -f $(OBJ_BNS)
	@$(MAKE) -C $(MLX42) clean
	@$(MAKE) -C $(FT_PRINTF) clean
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(MLX42) fclean
	@$(MAKE) -C $(FT_PRINTF) fclean
	@$(MAKE) -C $(LIBFT) fclean

fclean_bonus: clean_bonus
	rm -f $(NAME_BNS)
	@$(MAKE) -C $(MLX42) fclean
	@$(MAKE) -C $(FT_PRINTF) fclean
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re mlx ft_printf libft bonus clean_bonus fclean_bonus

# all - compile starter (execute other rules)

# CFLAGS is used automatically

# ar -rcs adds files in archve and replace them
# if they have already been there
# (if the library already exists)
# c creates the library if there is no one
# s creates a sorted index
# that's why we can call ar -rcs again and add there bonus obj files
