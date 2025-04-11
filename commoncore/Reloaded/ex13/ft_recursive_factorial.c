/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:41:40 by antabord          #+#    #+#             */
/*   Updated: 2025/04/08 17:43:00 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if ((nb == 0)||(nb == 1))
		return (1);
	if (nb < 0)
		return (0);
	if (nb > 0)
	{
		nb = nb *  ft_recursive_factorial(nb - 1);
	}
	return (nb);
}

int	main(void)
{
	printf("%d", ft_recursive_factorial(7));
	return (0);
}
