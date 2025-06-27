/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-27 12:20:43 by antabord          #+#    #+#             */
/*   Updated: 2025-06-27 12:20:43 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(char *av)
{
	int i;
	int sign;
	int res;

	i = 0;
	sign = 1;
	res = 0;
	if (av[i] == '-')
		sign = -1;
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9' || av[i] != 32)
			return (ft_err(void));
		else
			res = res * 10 + av[i] - '0';
		i++;
	}
	return (sign * res);
}