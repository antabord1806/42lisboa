
#include "push_swap.h"

long	ft_atol(char *str)
{
	long	result = 0;
	int		sign = 1;

	while ((*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	ft_lstadd_back_mod(t_stack **lst, t_stack *new)
{
	t_stack	*atual;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		atual = *lst;
		while (atual->next != NULL)
			atual = atual->next;
		atual->next = new;
	}
}

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
		str = ft_strjoin(str, tmp_str);
		if (!str)
			ft_err();
	}
	if (!ft_isdigit_mod(str))
	{
		freedom(str);
		ft_err();
	}	
	return (str);
}

int	ft_isduplicate(t_stack **stack)
{
	t_stack	*current;
	t_stack	*checking;

	current = *stack;
	while (current != NULL)
	{
		checking = current->next;
		while (checking != NULL)
		{
			if (current->number == checking->number)
				ft_err();
			checking = checking->next;
		}
		current = current->next;
	}
	return (1);
}
void	parser(t_stack **stack, char **av)
{
	int		i;
	long	value;
	t_stack	*new;

	i = 0;
	while (av[i])
	{
		new = malloc(sizeof(t_stack));
		if (!new)
			ft_err();
		value = ft_atol(av[i]);
		if (value > INT_MAX || value < INT_MIN || is_it_too_big(value))
		{
			freedom_stack(stack);
			free(new);
			freedom(av);
			ft_err();
		}	
		new->number = value;
		new->next = NULL;
		ft_lstadd_back_mod(stack, new);
		i++;
	}
}

