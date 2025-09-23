/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-11 15:46:18 by antabord          #+#    #+#             */
/*   Updated: 2025-05-11 15:46:18 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa(unsigned int nb)
{
	char	*digit;
	int		i;

	digit = "0123456789abcdef";
	i = 0;
	if (nb >= 16)
		i += ft_printhexa(nb / 16);
	ft_printchar(digit[nb % 16]);
	return (i + 1);
}
