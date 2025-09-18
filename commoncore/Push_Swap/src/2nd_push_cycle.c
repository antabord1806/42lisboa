/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cycle_ba.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:22:09 by marvin            #+#    #+#             */
/*   Updated: 2025/08/29 12:22:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move_target_to_top_or_push_b(t_stack *target, t_stack **stack_a, t_stack **stack_b, int nbr)
{
    if (nbr == 1)
    {
        while (*stack_a != target)
        {
            if (target->idx >= lst_size(stack_a) / 2)
                reverse_rotate_a(stack_a);
            else
                rotate_a(stack_a);
        }
        push_a(stack_b, stack_a);
        add_index(stack_a);
    }
    else if (lst_size(stack_a) == 4)
    {
        push_b(stack_a, stack_b);
        stack_is_3(stack_a);
    }
    else
    {
        push_b(stack_a, stack_b);
        push_b(stack_a, stack_b);
    }
}

t_stack *find_target_in_a(t_stack *node_b, t_stack **stack_a)
{
    t_stack *ptr;
    t_stack *target;
    int diff;

    target = NULL;
    ptr = *stack_a;
    while (ptr)
    {
        diff = ptr->number - node_b->number;
        if (diff > 0 && (!target || diff < target->number - node_b->number))
            target = ptr;
        ptr = ptr->next;
    }
    if (!target)
        target = no_target_min(stack_a);
    node_b->target = target;
    return target;
}

void push_loop_2(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *target;

    while (*stack_b)
    {
        target = find_target_in_a(*stack_b, stack_a);
        move_target_to_top_or_push_b(target, stack_a, stack_b, 1);
    }
    check_if_sorted(stack_a, 0);
}
