/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-27 14:55:57 by antabord          #+#    #+#             */
/*   Updated: 2025-06-27 14:55:57 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_err(void)
{
	fprintf(stderr, "Error\n");
	exit(EXIT_FAILURE);
}
void	freedom(char **arr)
{
	int	i = 0;

	if (!arr)
		return;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
void	freedom_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

int	min_max(t_stack **stack, int value)
{
	t_stack *ptr;
	int		max;
	int		min;

	max = 0;
	min = 0;
	ptr = *stack;
		while (ptr)
		{
			if (ptr->number > max)
				max = ptr->number;
			ptr = ptr->next;
		}
		return (max);
}

int	ft_isdigit_mod(char **nbr)
{
	int	i;
	int	j;

	if (!nbr || !nbr[0])
		return (0);
	i = 0;
	while (nbr[i])
	{
		j = 0;
		if (nbr[i][j] == '+' || nbr[i][j] == '-')
			j++;
		if (!nbr[i][j])
			return (0);
		while (nbr[i][j])
		{
			if (nbr[i][j] < '0' || nbr[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
