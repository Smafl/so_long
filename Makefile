
CC = cc
NAME = so_long
SRC = main.c\
map_check_utils.c\
map_check.c\
path_in_map_check.c\
read_map.c\
read_map_utils.c

OBJ = $(SRC:.c=.o)
MLX42 := ./lib/MLX42
FT_PRINTF := ./lib/ft_printf
LIBFT := ./lib/libft
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g

all: mlx ft_printf libft $(NAME)

mlx:
	@$(MAKE) DEBUG=yes -C $(MLX42)

ft_printf:
	@$(MAKE) -C $(FT_PRINTF)

libft:
	@$(MAKE) -C $(LIBFT)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX42)/libmlx42.a $(FT_PRINTF)/ft_printf.a $(LIBFT)/libft.a -o $(NAME)

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(MLX42) clean
	@$(MAKE) -C $(FT_PRINTF) clean
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(MLX42) fclean
	@$(MAKE) -C $(FT_PRINTF) fclean
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re mlx ft_printf libft

# all - compile starter (execute other rules)

# CFLAGS is used automatically

# ar -rcs adds files in archve and replace them
# if they have already been there
# (if the library already exists)
# c creates the library if there is no one
# s creates a sorted index
# that's why we can call ar -rcs again and add there bonus obj files
