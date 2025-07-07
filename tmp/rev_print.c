/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-07 16:54:53 by antabord          #+#    #+#             */
/*   Updated: 2025-07-07 16:54:53 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *c)
{
	int	i = 0;
	while (c[i])
	{
		i++;
	}
	return (i);
}

void	rev_print(char *s)
{
	int	i = ft_strlen(s) - 1;

	while (i >= 0)
	{
		write (1, &s[i], 1);
		i--;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_print(av[1]);
	write(1, "\n", 1);
	return (0);
}