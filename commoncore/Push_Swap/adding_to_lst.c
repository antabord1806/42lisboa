/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_to_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 19:06:21 by marvin            #+#    #+#             */
/*   Updated: 2025/06/29 19:06:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**join_args(int ac, char **av)
{
	char	**tmp_str;
	char	**str;
	int		i;

	i = 0;
	str = NULL;
	while (++i < ac)
	{
		tmp_str = ft_split(av[i], ' ');
		if (!tmp_str)
		{
			freedom(str);
			ft_err();
		}
		str = ft_strjoin_mod(str, tmp_str);
		freedom(tmp_str);
		if (!str)
		{
			freedom(str);
			ft_err();
		}
	}
	return (str);
}
int	ft_isduplicate(t_stack *stack)
{
	t_stack	*current;
	t_stack	*checking;

	current = stack;
	while (current != NULL)
	{
		checking = current->next;
		while (checking != NULL)
		{
			if (current->number == checking->number)
				return (1);
			checking = checking->next;
		}
		current = current->next;
	}
	return (0);
}
void	filters(t_stack *stack)
{
	while (stack != NULL)
	{
		if (ft_isdigit(stack->number))
			ft_err();
		if (is_duplicate(stack))
			ft_err();
		stack = stack->next;
	}
}

void	parser(t_stack *stack, char *av[])
{
	int		i;
	size_t	len;
	t_stack	*new;

	len = 0;
	i = -1;
	while (av[++i])
		len++;
	i = 0;
	while (++i <= len)
	{
		new = malloc(sizeof(t_stack));
		if (!new)
			return ;
		new->number = ft_atoi(av[i]);
		new->next = NULL;
		ft_lstadd_back(&stack, new);
	}
}
