/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-29 10:43:24 by antabord          #+#    #+#             */
/*   Updated: 2025-09-29 10:43:24 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_fun.h"
#include "a_structs.h"

int	move_check(t_game *game, int new_y, int new_x, char key)
{
	if (game->map->grid[new_y][new_x] == '1')
		return (0);
	else if (game->map->grid[new_y][new_x] == 'E')
	{
		
		ft_puterr("fim do jogo\n");
		exit(0);
	}
	else
	{
		move_player(game, new_y, new_x);
		write(1, &key, 1);
		write(1, "\n", 1);
	}
	return (0);
}

void	move_player(t_game *game, int new_y, int new_x)
{
	int	old_y;
	int	old_x;

	old_y = game->map->player_y;
	old_x = game->map->player_x;
	game->map->grid[old_y][old_x] = '0';
	game->map->grid[new_y][new_x] = 'P';
	game->map->player_x = new_x;
	game->map->player_y = new_y;
	map_render(game);
}