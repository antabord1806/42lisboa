/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:08:59 by marvin            #+#    #+#             */
/*   Updated: 2025/07/13 13:08:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move_cheapest_node(t_stack *cheapest_node, t_stack **stack_a, t_stack **stack_b)
{
    while (*stack_a != cheapest_node)
        rotate_a(stack_a);
    push_b(stack_a, stack_b);
}

t_stack *find_target(t_stack *node_a, t_stack *stack_b)
{
    t_stack *ptr = stack_b;
    t_stack *target = NULL;
    int diff;

    while (ptr)
    {
        diff = node_a->number - ptr->number;
        if (diff > 0 && (!target || diff < node_a->number - target->number))
            target = ptr;
        ptr = ptr->next;
    }
    if (!target)
    {
        max(stack_b);
        ptr = stack_b;
        target = ptr;
        while (ptr)
        {
            if (ptr->number > target->number)
                target = ptr;
            ptr = ptr->next;
        }
    }
    node_a->target = target;
    return target;
}
 
int	target_pos(int value_a, t_stack **stack_b)
{
	t_stack	*biggest;
    t_stack *ptr;
	t_stack	*target;

	target = find_target(value_a, stack_b);
    ptr = *stack_b;
    biggest = ptr;
	if (target)
		return (target->idx);
    while (ptr)
    {
        if (ptr->number > biggest->number)
            biggest = ptr;
        ptr = ptr->next;
    }
	return (biggest->idx);
}

int cost_analysis(t_stack *ptr, t_stack **stack_a, t_stack **stack_b)
{
    int total_cost;
    int target_cost;
    int stack_a_cost;
    int size;

    total_cost = 0;
    size = lst_size(stack_a);
    if (ptr->idx > size / 2)
        stack_a_cost = size - (ptr->idx);
    else
        stack_a_cost = (ptr->idx);
    if (target_pos(ptr->number, stack_b) > lst_size(stack_b) / 2)
        target_cost = lst_size(stack_b) - target_pos(ptr->number, stack_b);
    else
        target_cost = target_pos(ptr->number, stack_b);
    total_cost = stack_a_cost + target_cost;
    return (total_cost);
}


void    push_loop(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *ptr;
    t_stack *cheapest_node;
    int cheapest;
    int cost;

    push_b(stack_a, stack_b);
    if (check_if_3(stack_a, stack_b))
        stack_is_3(stack_a);
    push_b(stack_a, stack_b);
    while (*stack_a && !check_if_3(stack_a, stack_b))
    {
        cheapest_node = NULL;
        cheapest = INT_MAX;
        ptr = *stack_a;
        while (ptr)
        {
            cost = cost_analysis(ptr, stack_a, stack_b);
            if (cost < cheapest)
            {
                cheapest = cost;
                cheapest_node = ptr;
            }
            ptr = ptr->next;
        }
        if (cheapest_node)
            move_cheapest_node(cheapest_node, stack_a, stack_b);
    }
}