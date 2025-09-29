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


t_map	*create_map(char **line, int height)
{
	t_map *map;

	map = init_grid();
	if (!map)
		return (NULL);
	map->width = ft_strlen(line[0]);
	map->grid = line;
	map->height = height;
	if (!is_square(line, height))
	{
		ft_puterr("Error: The map is not rectangular\n");
		return (free_grid(map), NULL);
	}
	if (!check_counts(line))
		return (free_grid(map), NULL);
	if (!top_bottom_walls(line[0], line[map->height - 1]))
		return (free_grid(map), NULL);
	if (!coin_count(map))
		return (NULL);
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
