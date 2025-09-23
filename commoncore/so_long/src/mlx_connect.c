#include "structs.h"

int     main(void)
{
    t_game  game;

    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, 1920, 1080, "so_long");

}