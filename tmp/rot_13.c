/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-07 17:21:09 by antabord          #+#    #+#             */
/*   Updated: 2025-07-07 17:21:09 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rot13(char *s)
{
	int	i = 0;
	int c;

	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			c = s[i] + 13;
			if (c > 'z')
			{
				c = s[i] - 13;
				write(1, &c, 1);
			}
			else
				write(1, &c, 1);
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			c = s[i] + 13;
			if (c > 'Z')
			{
				c = s[i] - 13;
				write(1, &c, 1);
			}
			else
				write(1, &c, 1);
		}
		else
			write(1, &s[i], 1);
		i++;
	}
}
int	main(int ac, char **av)
{
	if (ac == 2)
		rot13(av[1]);
	write(1, "\n", 1);
	return (0);
}