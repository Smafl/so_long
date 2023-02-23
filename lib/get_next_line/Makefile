CC = cc
NAME = get_next_line.a
BONUS_NAME = get_next_line_bonus.a

SRC = get_next_line.c\
get_next_line_utils.c
BONUS_SRC = get_next_line_bonus.c\
get_next_line_utils_bonus.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g

all: $(NAME)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BONUS_NAME) $(BONUS_OBJ)
	ar -rcs $(BONUS_NAME) $(BONUS_OBJ)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(BONUS_NAME): $(BONUS_OBJ)
	ar -rcs $(BONUS_NAME) $(BONUS_OBJ)

.PHONY: all clean fclean re bonus

# all - compile starter (execute other rules)

# CFLAGS is used automatically

# ar -rcs adds files in archve and replace them
# if they have already been there
# (if the library already exists)
# c creates the library if there is no one
# s creates a sorted index
# that's why we can call ar -rcs again and add there bonus obj files
