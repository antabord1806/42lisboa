#include "a_structs.h"
#include "a_fun.h"

t_map	*init_grid(void)
{
	t_map *map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = NULL;
	map->height = 0;
	map->width = 0;
	return (map);
}


t_player    *player_init(void)
{
    t_player *player = malloc(sizeof(t_player));
    if (!player)
        return (NULL);
    player->x = 0;
    player->y = 0;
    player->moves = 0;
    player->sprite = NULL;
    player->walking = NULL;
    return (player);
}

t_game	*game_init(t_map *map, t_player *player)
{
	t_game *game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->win = NULL;
	game->mlx = NULL;
	game->player = player;
    game->map = map; 
	return (game);
}
