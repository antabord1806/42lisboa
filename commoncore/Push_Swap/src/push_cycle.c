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

int    cost_analysis(t_stack *ptr, t_stack **stack_a, t_stack **stack_b)
{
    int cost;
    int target_setup;

    while ((*stack_a) != ptr)
    {
        ptr = ptr->prev;
        cost++;
    }
    cost = cost + target_pos(stack_a, stack_b);
    cost++;
    return (cost);
}

void    push_loop(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *ptr;
    t_stack *cheapest_node;
    int cheapest;
    int cost;

    cheapest_node = NULL;
    cheapest = INT_MAX;
    ptr = *stack_a;
    push_b(stack_a, stack_b);
    if (check_if_3(stack_a, stack_b))
        stack_is_3(stack_a);
    push_b(stack_a, stack_b);

    while (ptr->next)
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