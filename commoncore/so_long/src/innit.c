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

t_game	*game_init(t_map *map, t_player *player)
{
	t_game *game;

	game = ft_memset(&game, 0, sizeof(t_game));
	game->map = map;
	game->player = player;
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