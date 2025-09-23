NAME = so_long
CC = gcc
RM = rm -f

MLX_PATH = minilibx-linux
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lX11 -lXext -lm

CFLAGS = -Wall -Wextra -Werror -I$(MLX_PATH) -Iinclude

SRC = mlx_connect.c player.c \

OBJ = $(SRC:.c=.o)

mlx:
	$(MAKE) -C $(MLX_PATH)

all: mlx $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) -o ./$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(MLX_PATH) fclean

.PHONY: all clean fclean

