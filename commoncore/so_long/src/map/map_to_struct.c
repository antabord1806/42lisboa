/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025-09-27 15:26:58 by antabord          #+#    #+#             */
/*   Updated: 2025-09-27 15:26:58 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../a_fun.h"
#include "../a_structs.h"


t_map	*create_map(t_map **map, char **line, int height)
{
	ft_memset(map, 0, sizeof(t_map));
	map->grid = line;
 	map->width = ft_strlen(line[0]);
	map->height = height;
	if (!is_square(line, height))
	{
		ft_puterr("Error: The map is not rectangular\n");
		return (NULL);
	}
	if (!check_counts(line))
		return (NULL);
	printf("before top bottom\n");
/* 	if (!top_bottom_walls(line[0], line[map->height - 1]))
		return (NULL); */
	find_p_x(&map);
	find_p_y(&map);
	while (height > 0)
	{
		printf("%s\n", (*map)->grid[height - 1]);
		height--;
	}
	printf("map created\n");
	return (map);
}

int	coin_count(t_map *map)
{
	int x;
	int y;
	int coins;

	coins = 0;
	x = 0;
	y = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (map->grid[y][x] == 'C')
				coins++;
			x++;
		}
		x = 0;
		y++;
	}
	map->coins_map = coins;
	if (coins != map->coins_found)
	{
		ft_puterr("Invalid coin placement\n");
		return (0);
	}
	return (1);
}
