/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-07 16:18:40 by antabord          #+#    #+#             */
/*   Updated: 2025-07-07 16:18:40 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	repeat_alpha(char *s)
{
	int	i = 0;
	int	c;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			c = s[i] - 64;
			while (c != 0)
			{
					write(1, &s[i], 1);
					c--;
			}
			c = 0;
		}
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			c = s[i] - 96;
			while (c != 0)
			{
				write(1, &s[i], 1);
				c--;
			}
			c = 0;
		}
		else
			write(1, &s[i], 1);
		i++;
	}
		
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	repeat_alpha(av[1]);
	write(1, "\n", 1);
	return (0);
}