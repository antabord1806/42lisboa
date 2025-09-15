/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/07/13 13:08:59 by marvin            #+#    #+#             */
/*   Updated: 2025/07/13 13:08:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void double_rotation_check(t_stack *node_a, t_stack **stack_a,
		t_stack **stack_b, int nbr)
{
	node_a->double_rot = 0;
	node_a->double_revrse = 0;

	if (nbr == 0)
	{
		while (
			node_a->idx - node_a->double_rot > 0 &&
			node_a->target->idx - node_a->double_rot > 0 &&
			(node_a->idx - node_a->double_rot) <= lst_size(stack_a) / 2 &&
			(node_a->target->idx - node_a->double_rot) <= lst_size(stack_b) / 2
		)
			node_a->double_rot++;
		while (
			node_a->idx + node_a->double_revrse < lst_size(stack_a) &&
			node_a->target->idx + node_a->double_revrse < lst_size(stack_b) &&
			(node_a->idx + node_a->double_revrse) > lst_size(stack_a) / 2 &&
			(node_a->target->idx + node_a->double_revrse) > lst_size(stack_b) / 2
		)
			node_a->double_revrse++;
	}
    else
    {
        check_if_3(stack_a);
        push_loop_2(stack_a, stack_b);
    }
}


void	move_cheapest_node(t_stack *node_a, t_stack **stack_a,
		t_stack **stack_b)
{
	int size_a;
	int size_b;

	size_a = lst_size(stack_a);
	size_b = lst_size(stack_b);
	while ((*stack_a) != node_a)
		double_rotation_check(node_a, stack_a, stack_b, 0);
	{
		if (node_a->idx >= size_a / 2)
			reverse_rotate_a(stack_a);
		else
			rotate_a(stack_a);
		add_index(stack_a);
		add_index(stack_b);
	}
	while ((*stack_b) != node_a->target)
	{
		if (node_a->target->idx >= size_b / 2)
			reverse_rotate_b(stack_b);
		else
			rotate_b(stack_b);
		add_index(stack_a);
		add_index(stack_b);
	}
	push_b(stack_a, stack_b);
}

t_stack	*find_target_in_b(t_stack *node_a, t_stack **stack_b)
{
	t_stack *ptr;
	t_stack *target;
	int diff;

	target = NULL;
	ptr = *stack_b;
	while (ptr)
	{
		diff = node_a->number - ptr->number;
		if (diff > 0 && (!target || diff < node_a->number - target->number))
			target = ptr;
		ptr = ptr->next;
	}
	if (!target)
		target = no_target_max(stack_b);
	node_a->target = target;
	return (target);
}

int	cost_analysis(t_stack *ptr, t_stack **stack_a, t_stack **stack_b)
{
	int cost_a;
	int cost_b;
	int size_b;
	int size_a;

	size_a = lst_size(stack_a);
	size_b = lst_size(stack_b);
	double_rotation_check(ptr, stack_a, stack_b, 0);
	if (ptr->idx >= size_a / 2)
		cost_a = size_a - (ptr->double_revrse) - (ptr->idx);
	else
		cost_a = ptr->idx - ptr->double_rot;
	if (ptr->target->idx >= size_b / 2)
		cost_b = size_b - ptr->target->double_revrse - (ptr->target->idx);
	else
		cost_b = ptr->target->idx - ptr->target->double_revrse;
	return (cost_a + cost_b);
}

void	push_loop_1(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *ptr;
	t_stack *node_a;
	int cheapest;

	ptr = *stack_a;
	move_target_to_top_or_push_b(ptr, stack_a, stack_b, 0);
	while (*stack_a && !check_if_3(stack_a))
	{
		node_a = NULL;
		cheapest = INT_MAX;
		ptr = *stack_a;
		while (ptr)
		{
			find_target_in_b(ptr, stack_b);
			if (cost_analysis(ptr, stack_a, stack_b) < cheapest)
			{
				cheapest = cost_analysis(ptr, stack_a, stack_b);
				node_a = ptr;
			}
			ptr = ptr->next;
		}
		if (node_a)
			move_cheapest_node(node_a, stack_a, stack_b);
	}
	double_rotation_check(node_a, stack_a, stack_b, 2);
}
