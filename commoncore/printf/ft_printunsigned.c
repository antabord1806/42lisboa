/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:21:09 by marvin            #+#    #+#             */
/*   Updated: 2025/05/11 13:35:06 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned(unsigned int c)
{
	long int	nb;
	int			counter;

	nb = c;
	counter = 0;
	if (nb < 10)
	{
		ft_printchar(nb + '0');
		counter++;
	}
	else
	{
		counter += ft_printunsigned(nb / 10);
		counter += ft_printunsigned(nb % 10);
	}
	return (counter);
}
