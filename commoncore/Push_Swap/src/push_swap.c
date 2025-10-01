/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-23 10:09:17 by antabord          #+#    #+#             */
/*   Updated: 2025-09-23 10:09:17 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	char	**args;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		ft_err();
	args = join_args(argc, argv);
	parser(&stack_a, args);
	ft_isduplicate(&stack_a);
	add_index(&stack_a);
	//printf("about to check if sorted \n");
	if (check_if_sorted(&stack_a, 1) || check_if_3(&stack_a))
	{
		freedom(args);
		freedom_stack(&stack_a);
		return (0);
	}
	//printf("about push 1\n");
	push_loop_1(&stack_a, &stack_b);

	freedom(args);
	freedom_stack(&stack_a);
	return (0);
}
