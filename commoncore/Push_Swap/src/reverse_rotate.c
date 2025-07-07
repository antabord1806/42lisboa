/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-07 14:10:07 by antabord          #+#    #+#             */
/*   Updated: 2025-07-07 14:10:07 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **head)
{
	t_stack		*tail;
	if (*head = NULL || (*head)->next==NULL)
		return ;
	while(tail->next != NULL)
		tail = tail->next;
	(*head)->prev = tail;
	tail = tail->prev;
	(*head)->prev->prev = NULL;
}
void	reverse_rotate_a(t_stack **head)
{
	reverse_rotate(head);
	write(1, "ra\n", 4);
}

void	reverse_rotate_b(t_stack **head)
{
	reverse_rotate(head);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_ab(t_stack **head_a, t_stack **head_b)
{
	reverse_rotate(head_a);
	reverse_rotate(head_b);
	write(1, "rrr\n", 5);
}