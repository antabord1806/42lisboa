CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -fclean

SRC = ft_err.c push_swap.c parsing.c 
NAME = push

OBJ = $(SRC:.c=.o)

all:
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re