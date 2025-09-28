/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:25:57 by antabord          #+#    #+#             */
/*   Updated: 2025/09/28 11:03:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_fun.h"
#include "a_structs.h"

void	map_render(void *mlx, void *win, t_map *map)
{
	int x;
	int y;
	void *img_draw;

	x = -1;
	y = -1;
	while (++y < map->height)
	{
		while (++x < map->width)
		{
			if (map->grid[y][x] == '0')
				img_draw = rendering_ground(y, x, map);
			else if (map->grid[y][x] == '1')
				img_draw = map->wall;
			else if (map->grid[y][x] == 'P')
				img_draw = map->player;
			else if (map->grid[y][x] == 'E')
				img_draw = map->exit;
			else
				img_draw = map->wall;
			mlx_put_image_to_window(mlx, win, img_draw, TILE_SIZE * x, TILE_SIZE * y);
		}
		x = 0;
	}
}

static void	*rendering_ground(int y, int x, t_map *map)
{
	void	*img_draw;
	
	if (y == 0)
		img_draw = map->ground_water;
	else
		img_draw = map->ground;
	return (img_draw);
}