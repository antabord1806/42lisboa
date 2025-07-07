/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizz_buzz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:38:54 by marvin            #+#    #+#             */
/*   Updated: 2025/07/06 13:38:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putnbr(int c)
{
    char n;
    if (c >= 10)
        ft_putnbr(c / 10);
    n = (c % 10) + '0';
    write(1, &n, 1);
}

int    main(void)
{
    int c = 1;

    while (c <= 100)
    {
        if ((c % 3 == 0) && (c % 5 == 0))
        {
            write(1, "fizzbuzz", 8);
            write(1, "\n", 1);
        }
        else if (c % 5 == 0)
        {
            write(1, "buzz", 4);
            write(1, "\n", 1);
        }
        else if (c % 3 == 0)
        {
            write(1, "fizz", 4);
            write(1, "\n", 1);
        }
        else
        {
            ft_putnbr(c);
            write(1, "\n", 1);
        }
        c++;
    }
    return (0);
}