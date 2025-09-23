/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-11 15:43:57 by antabord          #+#    #+#             */
/*   Updated: 2025/05/11 16:53:32 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printhexa_pointer(unsigned long long nb)
{
	char	*digit;
	int		i;

	digit = "0123456789abcdef";
	i = 0;
	if (nb >= 16)
		i += ft_printhexa_pointer(nb / 16);
	ft_printchar(digit[nb % 16]);
	return (i + 1);
}

int	ft_print_pointer(void *p)
{
	unsigned long long	ptr;
	int					i;

	i = 0;
	ptr = (unsigned long long)p;
	if (!ptr)
		i += ft_printstr("(nil)");
	else
	{
		i += ft_printstr("0x");
		i += ft_printhexa_pointer(ptr);
	}
	return (i);
}
