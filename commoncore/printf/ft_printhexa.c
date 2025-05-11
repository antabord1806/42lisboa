/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:45:14 by marvin            #+#    #+#             */
/*   Updated: 2025/05/11 16:22:41 by antabord         ###   ########.fr       */
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
