/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:49:21 by marvin            #+#    #+#             */
/*   Updated: 2025/05/08 21:49:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf"
#include <unistd.h>
#include <stdio.h>

int    ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int     ft_printchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int     ft_printint(int c)
{
    long int nb  = c;
    int     counter = 0;

    if (nb < 0)
    {
        nb = - nb;
        ft_putchar('-');
        counter++;
    }
    if (nb < 10)
    {    
        ft_putchar(nb + '0');
        counter++;
    }
    else
    {
        counter += ft_printint(nb / 10);
        counter += ft_printint(nb % 10);
    }
    return counter;
}

int     ft_printstr(char *str)
{
    int     len;
    int     i;

    i = 0;
    len = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        len++;
        i++;
    }
    return (len);
}

int ft_printhexa(unsigned int nb)
{
    char *digit = "0123456789abcdef";
    int i = 0;

    if (nb >= 16)
        i += ft_printhexa(nb / 16);
    
    return i + 1;
}

int ft_printhexa_upper(unsigned int nb)
{
    char *digit = "0123456789ABCDEF";
    int i = 0;

    if (nb >= 16)
        i += ft_printhexa_upper(nb / 16);
    
    ft_putchar(digit[nb % 16]);
    return i + 1;
}

int ft_print_pointer(void *p)
{
    unsigned long ptr = (unsigned long)p;
    int i = 0;

    i += ft_printstr("0x");
    i += ft_printhexa(ptr);
    return i;
}


/*int main(void)
{
    ft_printhexa_upper(15151);
    return (0);
}*/

/*int main(void)
{
    char *c = "ola tudo bem";
    printf("\nlen: %d\n", ft_printstr(c));
    return (0);
}*/

/*int main(void)
{
    int i = 8;
    void *a = &i;
    printf("%p\n",a);
    ft_print_pointer(a);
    return (0);
}*/