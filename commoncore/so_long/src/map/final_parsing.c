/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-27 15:26:32 by antabord          #+#    #+#             */
/*   Updated: 2025-09-27 15:26:32 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../a_structs.h"
#include "../a_fun.h"

int	top_bottom_walls(char *st_line, char *lst_line)
{
	int	i;

	i = 0;
	while (st_line[i] && lst_line[i])
	{
		if (st_line[i] != '1' || lst_line[i] != '1')
		{
			ft_puterr("Error: Map walls invalid\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_way_out(char **str, int y, int x)
{
	if (str[y + 1][x] == '0' || str[y - 1][x] == '0' || str[y][x + 1] == '0' || str[y][x - 1] == '0')
		return 1;
	return (0);
}

int	e_p_finder(char **lines, int max_y, int max_x)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < max_y)
	{
		while (x < max_x)
		{
			if ((lines[y][x] == 'E' && !check_way_out(lines, y, x)) || (lines[y][x] == 'P' && !check_way_out(lines, y, x)))
			{
				ft_puterr("Error: exit or player blocked!\n");
				return (0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

