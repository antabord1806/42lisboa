/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:26:05 by antabord          #+#    #+#             */
/*   Updated: 2025/09/27 23:28:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_fun.h"
#include "a_structs.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	map = main_parser(argc, argv);
	mlx = mlx_init();
	win = mlx_new_window(mlx, map->width * TILE_SIZE, map->height * TILE_SIZE,
			"so_long");
	map->ground = mlx_xpm_file_to_image(mlx, "assets/map/AnyConv.com__ground.xpm", &x, &y);
	//map->ground_water = mlx_xpm_file_to_image(mlx, "ground_water.xpm", &x, &y);
	map->wall = mlx_xpm_file_to_image(mlx, "assets/map/AnyConv.com__water.xpm", &x, &y);
	map->player = mlx_xpm_file_to_image(mlx, "assets/player/idle/iloveimg-resized/image_part_001.xpm", &x, &y);
	map->exit = mlx_xpm_file_to_image(mlx, "assets/exit/AnyConv.com__Tower.xpm", &x, &y);
	map_render(mlx, win, map);
	mlx_loop(mlx);
}

void	map_render(void *mlx, void *win, t_map *map)
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
}