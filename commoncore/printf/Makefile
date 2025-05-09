CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

NAME = libftprintf.all

SRC = ft_printf.c ft_printf_aux.c \

OBJ = $(SRC: .c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR): $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re