/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1st_push_cycle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-23 10:08:06 by antabord          #+#    #+#             */
/*   Updated: 2025-09-23 10:08:06 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void double_rotation_check(t_stack *node_a, t_stack **stack_a,
		t_stack **stack_b, int nbr)
{
	int move_rr;
	int	move_rrr;

	move_rr = 0;
	move_rrr = 0;
	if (nbr == 0)
	{
		if (node_a->idx >= lst_size(stack_a) / 2 && node_a->target->idx >= lst_size(stack_b) / 2)
		{
			if ((lst_size(stack_a) - node_a->idx) < lst_size(stack_b) - node_a->target->idx)
				move_rrr = lst_size(stack_a) - node_a->idx;
			else
				move_rrr = lst_size(stack_b) - node_a->target->idx;
		}
		else if (node_a->idx < lst_size(stack_a) / 2 && node_a->target->idx < lst_size(stack_b) / 2)
		{
			if (node_a->idx < node_a->target->idx)
				move_rr = node_a->idx;
			else
				move_rr = node_a->target->idx;
		}
		node_a->rr = move_rr;
		node_a->rrr = move_rrr;
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
	while ((*stack_a) != node_a)
	{
		while (node_a->rr-- > 0)
			rr(stack_a, stack_b);
		while (node_a->rrr-- > 0)
			rrr(stack_a, stack_b);
		add_index(stack_a);
		add_index(stack_b);
		if (node_a->idx >= lst_size(stack_a) / 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
	while ((*stack_b) != node_a->target)
	{
		add_index(stack_a);
		add_index(stack_b);
		if (node_a->target->idx >= lst_size(stack_b) / 2)
			rrb(stack_b);
		else
			rb(stack_b);
	}
	pb(stack_a, stack_b);
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

	if (!ptr || !ptr->target)
		return 0;
	double_rotation_check(ptr, stack_a, stack_b, 0);
	if (ptr->idx >= lst_size(stack_a) / 2)
		cost_a = lst_size(stack_a) - (ptr->rrr) - (ptr->idx);
	else
		cost_a = ptr->idx - ptr->rr;
	if (ptr->target->idx >= lst_size(stack_b) / 2)
		cost_b = lst_size(stack_b) - ptr->target->rrr - (ptr->target->idx);
	else
		cost_b = ptr->target->idx - ptr->target->rr;
	return (cost_a + cost_b);
}

void	push_loop_1(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *ptr;
	t_stack *node_a;
	int cheapest;
	int	cost;

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
			cost = cost_analysis(ptr, stack_a, stack_b);
			if (cost < cheapest)
			{
				cheapest = cost;
				node_a = ptr;
			}
			ptr = ptr->next;
		}
		if (node_a)
			move_cheapest_node(node_a, stack_a, stack_b);
	}
	double_rotation_check(node_a, stack_a, stack_b, 2);
}
