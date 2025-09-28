#ifndef A_STRUCTS_H
#define A_STRUCTS_H

#ifdef __KEY_HOOKS__
#else
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <fcntl.h>

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include "a_fun.h"

//assets
typedef struct s_map {
    char    **grid;
    int     width;
    int     height;
    void    *player;
    void    *wall;
    void    *ground;
    void    *ground_water;
    void    *exit;
}   t_map;

typedef struct s_player {
    int     x;
    int     y;
    int     moves;
    void    *sprite;
    void    *walking;
}   t_player;


typedef struct s_game {
    void    *win;
    void    *mlx;
    t_player    *player;
    t_map       *map;
}   t_game;

#endif