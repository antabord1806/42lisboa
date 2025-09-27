/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-27 15:25:57 by antabord          #+#    #+#             */
/*   Updated: 2025-09-27 15:25:57 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_fun.h"
#include "a_structs.h"

void	map_render(void *mlx, void *win)
{
	int x;
	int y;
	void *img_draw;
	t_map *map;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (map->grid[y][x] == '0')
				img_draw = map->ground;
			if (map->grid[y][x] == '1')
				img_draw = map->wall;
			if (map->grid[y][x] == 'P')
				img_draw = map->player;
			if (map->grid[y][x] == 'E')
				img_draw = map->exit;
			else
				img_draw = map->wall;
		}
	}
	mlx_put_image_to_window(mlx, win, img_draw, TILE_SIZE * x, TILE_SIZE * y);
}