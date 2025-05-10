/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:45:14 by marvin            #+#    #+#             */
/*   Updated: 2025/05/10 13:45:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printhexa(unsigned nb)
{
    char *digit = "0123456789abcdef";
    int i = 0;

    if (nb >= 16)
        i += ft_printhexa(nb / 16);
    ft_printchar(digit[nb % 16]);
    return i + 1;
}
