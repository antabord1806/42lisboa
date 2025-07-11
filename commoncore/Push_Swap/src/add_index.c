/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-11 12:46:47 by antabord          #+#    #+#             */
/*   Updated: 2025-07-11 12:46:47 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_index(t_stack *stack)
{
	int index;
	t_stack *curr;

	index = 0;
	curr = stack;
	while (curr->next != NULL)
	{
		curr->idx = index;
		curr = curr->next;
		index++;
	}
}
int		check_if_sorted(t_stack *stack)
{
	if (stack->next == NULL)
		return (1);
	while (stack->number < stack->next->number)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}
