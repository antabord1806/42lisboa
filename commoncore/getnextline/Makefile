CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c get_next_line_bonus.c \
      get_next_line_utils_bonus.c \

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

run: all
	./$(NAME)

re: fclean all

.PHONY: all clean fclean re