/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
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
	if (!top_bottom_walls(line[0], line[map->height - 1]) || !e_p_finder(line,
		height - 1, map->width - 1))
		return (free_grid(map), NULL);
	printf("map created\n");
	return (map);
}
