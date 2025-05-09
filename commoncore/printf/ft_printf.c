/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:17:28 by marvin            #+#    #+#             */
/*   Updated: 2025/05/07 16:17:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>

int print_checker(va_list ptr, char format)
{
    int len;

    len = 0;
    if (format == 'c')
        len += ft_printchar(va_arg(ptr, int));
    else if (format == 's')
        len += ft_printstr(va_arg(ptr, char *));
    else if (format == 'p')
        len += ft_print_pointer(va_arg(ptr, void *));
    else if (format == 'i' || format == 'd')
        len += ft_printint(va_arg(ptr, int));
    //else if (spec == 'u')
        //len += ft_printunsigned(va_arg(ptr, unsigned char));
    else if (format == 'x')
        len += ft_printhexa(va_arg(ptr, int));
    else if (format == 'X')
        len += ft_printhexa_upper(va_arg(ptr, int));
    return (len);
}

int ft_printf(const char *format, ...)
{
    va_list ptr;
    int total;
    int i;
    if (!format)
        return 1;
    total = 0;
    i = 0;
    va_start(ptr, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
        i++;
        total += print_checker(ptr, format[i]);
        }
        else
            total += ft_putchar(format[i]);
        i++;
    }
    va_end(ptr);
    return (total);
}

int main(void)
{
    char c = 'a';
    char *s = "ola tudo bem";
    void *p = &c;
    int i = 45565;
    int negativo = -88820;

    ft_printf("------ft_printf--------\n");
    ft_printf("%c\n", c);
    ft_printf("%s\n", s);
    ft_printf("%d\n", 362386);
    ft_printf("%i\n", -7262);
    ft_printf("%p\n", p);
    ft_printf("%x\n", 15);
    ft_printf("%X\n", 15);

    printf("------printf--------\n");
    printf("%c\n", c);
    printf("%s\n", s);
    printf("%d\n", 362386);
    printf("%i\n", -7262);
    printf("%p\n", p);
    printf("%x\n", 15);
    printf("%X\n", 15);
    return (0);
}