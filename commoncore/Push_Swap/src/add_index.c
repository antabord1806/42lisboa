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

void	add_index(t_stack **stack)
{
	int index;
	t_stack *curr;

	index = 0;
	curr = *stack;
	while (curr->next)
	{
		curr->idx = index;
		curr = curr->next;
		index++;
	}
}
int		check_if_sorted(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	if (tmp->next == NULL)
		return (1);
	while (tmp->number < tmp->next->number)
	{
		if (tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
