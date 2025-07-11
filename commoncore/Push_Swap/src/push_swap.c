/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:51:49 by marvin            #+#    #+#             */
/*   Updated: 2025/06/29 18:51:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**args;
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc <= 1)
		ft_err();
	args = join_args(argc, argv);
	parser(&stack_a, args);
	ft_isduplicate(stack_a);
	add_index(stack_a);
	if (check_if_sorted(stack_a))
		return (0);
	check_if_3(stack_a);
	freedom(args);
	freedom_stack(&stack_a);
	return (0);
}
