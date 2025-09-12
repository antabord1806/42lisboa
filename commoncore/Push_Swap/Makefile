CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap

SRC = src/adding_to_lst.c src/ft_err.c src/push_swap.c src/add_index.c src/check_stack.c \
      src/rotate.c src/push.c src/reverse_rotate.c src/swap.c src/1st_push_cycle.c src/2nd_push_cycle.c \
      src/ft_split.c src/ft_strjoin.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
