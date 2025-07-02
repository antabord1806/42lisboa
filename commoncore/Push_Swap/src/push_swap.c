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
	t_stack	*stack;

	stack = NULL;
	if (argc <= 1)
		ft_err();
	args = join_args(argc, argv);
	parser(&stack, args);
	filters(stack);
	while (stack)
	{
		printf("%d\n", stack->number);
		stack = stack->next;
	}
	return (0);
}
