#include "a_fun.h"
#include "a_structs.h"

int     handle_keypress()
{

}

int handle_keypress(int key, t_game *game)
{
    if (key == 17)
    {
        ft_puterr("Game closed!");
        exit(0);
    }
    else if (key == KEY_W)
        game->player->y += 1;
    else if (key == KEY_A)
        game->player->x -= 1;
    else if (key == KEY_S)
        game->player->y -= 1;
    else if (key == KEY_D)
        game->player->x += 1;
    map_render(game->mlx, game->win, game->map);
    return (0);
}
