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

/*void	map_render(void *mlx, void *win, t_map *map)
{
	int x;
	int y;
	void *img_draw;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (map->grid[y][x] == '0')
				img_draw = map->ground;
			else if (map->grid[y][x] == '1')
				img_draw = map->wall;
			else if (map->grid[y][x] == 'P')
				img_draw = map->player;
			else if (map->grid[y][x] == 'E')
				img_draw = map->exit;
			else
				img_draw = map->wall;
			mlx_put_image_to_window(mlx, win, img_draw, TILE_SIZE * x, TILE_SIZE * y);
			x++;
		}
		x = 0;
		y++;
	}
}*/

/*void	*rendering_ground(int y, t_map *map)
{
	void	*img_draw;
	
	if (y == 0)
		img_draw = map->ground_water;
	else
		img_draw = map->ground;
	return (img_draw);
}*/