/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:25:57 by antabord          #+#    #+#             */
/*   Updated: 2025/09/28 19:49:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_fun.h"
#include "a_structs.h"

void	map_render(t_game *game)
{
	int x;
	int y;
	void *img_draw;

	x = 0;
	y = 0;
	while (y < game->map->height)
	{
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == '0')
				img_draw = game->map->ground;
			else if (game->map->grid[y][x] == '1')
				img_draw = game->map->wall;
			else if (game->map->grid[y][x] == 'P')
				img_draw = img_drawing(game, y, x);
			else if (game->map->grid[y][x] == 'C')
				img_draw = game->map->coins;
			else if (game->map->grid[y][x] == 'E')
				img_draw = game->map->exit;
			else
				img_draw = game->map->wall;
			mlx_put_image_to_window(game->mlx, game->win, img_draw, TILE_SIZE * x, TILE_SIZE * y);
			x++;
		}
		y++;
		x = 0;
	}
}

void	*img_drawing(t_game *game, int y, int x)
{
	void *img;

	img = game->map->player;
	game->map->player_x = x;
	game->map->player_y = y;
	return (img);
}

/*void	*rendering_ground(int y, t_map *map)
{
	void	*img_draw;
	
	if (y == 0)
		img_draw = map->ground_water;
	else
		img_draw = map->ground;
	return (img_draw);
}*/