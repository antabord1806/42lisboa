/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:47:15 by marvin            #+#    #+#             */
/*   Updated: 2025/05/10 13:47:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int     ft_printint(int c)
{
    long int nb  = c;
    int     counter = 0;

    if (nb < 0)
    {
        nb = - nb;
        ft_printchar('-');
        counter++;
    }
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