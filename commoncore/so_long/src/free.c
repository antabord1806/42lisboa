/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-27 15:26:11 by antabord          #+#    #+#             */
/*   Updated: 2025-09-27 15:26:11 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_structs.h"
#include "a_fun.h"

void	ft_free_all(char **arr_aloc)
{
	int	i;

	i = 0;
	while (arr_aloc[i])
	{
		free(arr_aloc[i]);
		i++;
	}
	free(arr_aloc);
}

void free_grid(t_map *map)
{
    if (!map)
        return;
    if (map->grid)
        ft_free_all(map->grid);
    free(map);
}
