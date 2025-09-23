/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-11 15:46:32 by antabord          #+#    #+#             */
/*   Updated: 2025-05-11 15:46:32 by antabord         ###   ########.fr       */
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
