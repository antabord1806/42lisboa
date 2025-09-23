#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include <mlx.h>
#include <libft.h>

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

//aux

typedef struct s_grid
{
    char    **lines;
    size_t  n_lines;
    size_t  n_collums;
}   t_grid;

#endif