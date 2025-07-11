/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-11 13:53:34 by antabord          #+#    #+#             */
/*   Updated: 2025-07-11 13:53:34 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_is_2(t_stack *stack)
{
	if (stack < stack->next)
		check_if_sorted(stack);
	else
		rotate_a;
}
void	stack_is_3(t_stack *stack)
{
	while (stack->number < stack->next->number)
	{
		if (stack->number > stack->next->number)
	}

}

void	check_if_3(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 1;
	while (stack_a->next)
	{
		stack_a = stack_a->next;
		i++;
	}
	if (i == 1)
		check_if_sorted(stack_a);
	else if(i == 2)
		stack_is_2(stack_a);
	else if(i == 3)
		stack_is_3(stack_a);
	else
		push_loop(stack_a, stack_b);
}
