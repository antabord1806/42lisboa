CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

NAME = libftprintf.a

SRC = ft_printf.c ft_print_pointer.c ft_printhexa.c ft_printhexa_upper.c \
      ft_printint.c ft_printstr.c ft_printchar.c ft_printunsigned.c \

OBJ = $(SRC:.c=.o)  
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
