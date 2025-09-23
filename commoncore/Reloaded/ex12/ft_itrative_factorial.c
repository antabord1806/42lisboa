/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itrative_factorial.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:44:34 by antabord          #+#    #+#             */
/*   Updated: 2025/04/08 18:21:57 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iteractive_factorial(int nb)
{
	int	res;

	res = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (nb >= 1)
	{
		res *= nb;
		nb--;
	}
	return (res);
}

int	main(void)
{
	printf("%d", ft_iterative_factorial(7));
	return (0);
}
