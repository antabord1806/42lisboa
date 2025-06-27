/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-27 15:07:18 by antabord          #+#    #+#             */
/*   Updated: 2025-06-27 15:07:18 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	push_swap(int ac, char *av)
{
	int i;

	i = 1;
	if (ac <= 1)
		return (ft_err(void));
	while (i < ac)
	{
		if (!parsing(av[i]))
			return (ft_err(void));
		
	}
}