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

void move_cheapest_node(t_stack *node_a, t_stack **stack_a, t_stack **stack_b)
{
    int size_a;
    int size_b;

    size_a = lst_size(stack_a);
    size_b = lst_size(stack_b);
    while ((*stack_a) != node_a)
    {
        if (node_a->idx >= size_a / 2)
            reverse_rotate_a(stack_a);
        else
            rotate_a(stack_a);
    }
    while ((*stack_b) != node_a->target)
    {
        if (node_a->target->idx >= size_b / 2)
            reverse_rotate_b(stack_b);
        else
            rotate_b(stack_b);
    }
    push_b(stack_a, stack_b);
    add_index(stack_a);
    add_index(stack_b);
}

t_stack *find_target_in_b(t_stack *node_a, t_stack **stack_b)
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
    return target;
}

int cost_analysis(t_stack *ptr, t_stack **stack_a, t_stack **stack_b)
{
    int cost_a;
    int cost_b;
    int size_b;
    int size_a;

    size_a = lst_size(stack_a);
    size_b = lst_size(stack_b);
    if (ptr->idx >= size_a / 2)
        cost_a = size_a - (ptr->idx);
    else
        cost_a = ptr->idx;
    if (ptr->target->idx >= size_b / 2)
        cost_b = size_b - (ptr->target->idx);
    else
        cost_b = ptr->target->idx;
    return (cost_a + cost_b);
}

void push_loop_1(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *ptr;
    t_stack *node_a;
    int cheapest;

    move_target_to_top_or_push_b(*stack_a, stack_a, stack_b, 0);
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
    push_loop_1_v2(stack_a, stack_b);
}

void push_loop_1_v2(t_stack **stack_a, t_stack **stack_b)
{
    stack_is_3(stack_a);
    push_loop_2(stack_a, stack_b);
}
