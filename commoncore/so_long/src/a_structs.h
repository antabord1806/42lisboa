#ifndef A_STRUCTS_H
#define A_STRUCTS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <fcntl.h>

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include "a_fun.h"

//aux
typedef struct s_grid
{
    char    **lines;
    int     n_lines;
    int     n_columns;
}   t_grid;

//assets
typedef struct s_player {
    int     x;
    int     y;
    int     moves;
    void    *sprite;
    void    *walking;
}   t_player;

typedef struct s_map {
    int     width;
    int     height;
    void    *wall;
    void    *ground;
    void    *exit;
    t_grid     grid;
}   t_map;

typedef struct s_game {
    void    *win;
    void    *mlx;
    t_player    player;
    t_map       map;
}   t_game;


#endif