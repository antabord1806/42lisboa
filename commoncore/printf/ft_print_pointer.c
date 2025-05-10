/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:42:44 by marvin            #+#    #+#             */
/*   Updated: 2025/05/10 13:42:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int ft_printhexa_pointer(unsigned long long nb)
{
    char *digit = "0123456789abcdef";
    int i = 0;

    if (nb >= 16)
        i += ft_printhexa_pointer(nb / 16);
    ft_printchar(digit[nb % 16]);
    return i + 1;
}

int ft_print_pointer(void *p)
{
    unsigned long long ptr = (unsigned long long)p;
    int i = 0;
    
    i += ft_printstr("0x");
    i += ft_printhexa_pointer(ptr);
    return i;
}