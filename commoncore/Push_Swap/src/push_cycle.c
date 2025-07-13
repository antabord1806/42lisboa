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

void    push_loop(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *ptr;

    ptr = *stack_a;
    push_b(stack_a, stack_b);
    if (check_if_3(stack_a, stack_b))
        stack_is_3(stack_a);
    push_b(stack_a, stack_b);

    while (ptr->next)
    {
        cost_analysis(stack_a);
        ptr = ptr->next;
    }
    
}