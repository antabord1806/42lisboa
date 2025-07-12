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

void	stack_is_2(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	if (tmp->number < tmp->next->number)
		check_if_sorted(stack);
	else
		swap_a(stack);
}
void	stack_is_3(t_stack **stack)
{
	int a = (*stack)->number;
	int b = (*stack)->next->number;
	int c = (*stack)->next->next->number;

	if (a > b && b < c && a < c)
		swap_a(stack);
	else if (a > b && b > c)
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stack);
	else if (a < b && b > c && a < c)
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate_a(stack);
	check_if_sorted(stack);
}

void	check_if_3(t_stack **stack_a)
{
	t_stack *tmp;
	int	i;

	i = 1;
	tmp = *stack_a;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	if (i == 1)
		check_if_sorted(stack_a);
	else if(i == 2)
		stack_is_2(stack_a);
	else if(i == 3)
		stack_is_3(stack_a);
/* 	else
		push_loop(stack_a, stack_b); */
}
