/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-07 17:46:48 by antabord          #+#    #+#             */
/*   Updated: 2025-07-07 17:46:48 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 #include <unistd.h>

 void	rotone(char *s)
 {
	int	i = 0;
	int	c;

	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			c = s[i] + 1;
			if (c > 'z')
			{
				c = s[i] - 1;
				write(1, &c, 1);
			}
			else
				write(1, &c, 1);
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			c = s[i] + 1;
			if (c > 'Z')
			{
				c = s[i] - 1;
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
		rotone(av[1]);
	write(1, "\n", 1);
	return (0);
 }