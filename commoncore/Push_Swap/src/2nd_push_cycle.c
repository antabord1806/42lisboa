/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2nd_push_cycle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-23 10:08:15 by antabord          #+#    #+#             */
/*   Updated: 2025-09-23 10:08:15 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void move_target_to_top_or_push_b(t_stack *target, t_stack **stack_a, t_stack **stack_b, int nbr)
{   
    if (nbr == 1)
    {
        while (*stack_a != target)
        {
            //printf("staring\n");
            if (target->idx >= lst_size(stack_a) / 2)
                rra(stack_a);
            else
                ra(stack_a);
            add_index(stack_a, stack_b);
        }
        pa(stack_b, stack_a);
        add_index(stack_a, stack_b);
    }
    else
    {
        pb(stack_a, stack_b);
        if (check_if_3(stack_a))
            push_loop_2(stack_a, stack_b);
        pb(stack_a, stack_b);
        add_index(stack_a, stack_b);
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
    target = no_target_min(stack_a);
    move_target_to_top_or_push_b(target, stack_a, stack_b, 1);
    return ;
}

void finalize_stack_a(t_stack **stack_a)
{
    t_stack *min_node;
    int size;

    if (!stack_a || !*stack_a)
        return;

    size = lst_size(stack_a); // Tamanho da stack

    // Encontra o menor elemento na stack
    min_node = no_target_min(stack_a);

    // Roda a stack até que o menor elemento esteja no topo
    while (*stack_a != min_node)
    {
        if (min_node->idx >= size / 2)
            rra(stack_a);  // Rotação reversa se estiver na metade inferior
        else
            ra(stack_a);   // Rotação direta se estiver na metade superior
    }
    return ;
}