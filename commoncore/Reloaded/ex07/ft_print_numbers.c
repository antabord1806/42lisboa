/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:25:27 by antabord          #+#    #+#             */
/*   Updated: 2025/04/08 13:42:12 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c);

void	ft_print_numbers(void)
{
	char c;

	c = '1';
	while (c <= '9')
	{
		ft_putchar(c);
		c++;
	}
}

int	main(void)
{
	ft_print_numbers();
	return (0);
}
