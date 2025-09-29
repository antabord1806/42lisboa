/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-29 10:43:45 by antabord          #+#    #+#             */
/*   Updated: 2025-09-29 10:43:45 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	map->player_x = 0;
	map->player_y = 0;
	map->coins_map = 0;
	map->coins_found = 0;
	return (map);
}


t_player    *player_init(void)
{
    t_player *player = malloc(sizeof(t_player));
    if (!player)
        return (NULL);
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

void	find_p_x(t_map *map)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (map->grid[y][x] == 'P')
			{
				map->player_x = x;
			}
			x++;
		}
		x = 0;
		y++;
	}
}
void	find_p_y(t_map *map)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (map->grid[y][x] == 'P')
			{
				map->player_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
}