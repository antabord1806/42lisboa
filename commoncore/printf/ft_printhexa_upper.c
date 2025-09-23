/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-11 15:46:14 by antabord          #+#    #+#             */
/*   Updated: 2025-05-11 15:46:14 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa_upper(unsigned int nb)
{
	char	*digit;
	int		i;

	digit = "0123456789ABCDEF";
	i = 0;
	if (nb >= 16)
		i += ft_printhexa_upper(nb / 16);
	ft_printchar(digit[nb % 16]);
	return (i + 1);
}
