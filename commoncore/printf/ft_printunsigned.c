/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:21:09 by marvin            #+#    #+#             */
/*   Updated: 2025/05/10 14:21:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int     ft_printunsigned(unsigned c)
{
    long int nb  = c;
    int     counter = 0;

    if (nb < 10)
    {    
        ft_printchar(nb + '0');
        counter++;
    }
    else
    {
        counter += ft_printint(nb / 10);
        counter += ft_printint(nb % 10);
    }
    return counter;
}