
CC = cc
NAME = so_long
SRC = main.c

OBJ = $(SRC:.c=.o)
MLX42 := ./lib/MLX42
GNL := ./lib/get_next_line
LIBFT := ./lib/libft
CFLAGS = -Wall -Wextra -Werror

all: mlx gnl libft $(NAME)

mlx:
	@$(MAKE) -C $(MLX42)

gnl:
	@$(MAKE) -C $(GNL)

libft:
	@$(MAKE) -C $(LIBFT)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX42)/libmlx42.a $(GNL)/get_next_line.a $(LIBFT)/libft.a -o $(NAME)

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(MLX42) clean
	@$(MAKE) -C $(GNL) clean
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(MLX42) fclean
	@$(MAKE) -C $(GNL) fclean
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re mlx gnl

# all - compile starter (execute other rules)

# CFLAGS is used automatically

# ar -rcs adds files in archve and replace them
# if they have already been there
# (if the library already exists)
# c creates the library if there is no one
# s creates a sorted index
# that's why we can call ar -rcs again and add there bonus obj files
