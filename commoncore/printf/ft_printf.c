/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-11 15:46:06 by antabord          #+#    #+#             */
/*   Updated: 2025-05-11 15:46:06 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	checker(char format)
{
	if (format == 'c' || format == 's' || format == 'p' || format == 'i'
		|| format == 'd' || format == 'u' || format == 'x' || format == 'X'
		|| format == '%')
		return (1);
	return (0);
}

static int	printer(va_list ptr, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_printchar(va_arg(ptr, int));
	else if (format == 's')
		len += ft_printstr(va_arg(ptr, char *));
	else if (format == 'p')
		len += ft_print_pointer(va_arg(ptr, void *));
	else if (format == 'i' || format == 'd')
		len += ft_printint(va_arg(ptr, int));
	else if (format == 'u')
		len += ft_printunsigned(va_arg(ptr, unsigned int));
	else if (format == 'x')
		len += ft_printhexa(va_arg(ptr, int));
	else if (format == 'X')
		len += ft_printhexa_upper(va_arg(ptr, int));
	else if (format == '%')
		len += ft_printchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		total;
	int		i;

	if (!format)
		return (1);
	total = 0;
	i = 0;
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] && checker(format[i + 1]))
		{
			total += printer(ptr, format[i + 1]);
			i++;
		}
		else
			total += ft_printchar(format[i]);
		i++;
	}
	va_end(ptr);
	return (total);
}

/*int main(void)
{
	char c = 0;
	char *s = "ola tudo bem";
	void *p1 = &c;
	void *p2 = &s;
	int i = 0;
	int n = -1;

	ft_printf("------ft_printf--------\n");
	ft_printf("ola tudo bem %c\n", c);
	ft_printf("NULL s NULL\n", NULL);
	ft_printf("42, %, adeus%d\n", n);
	ft_printf("%i\n", i);
	ft_printf("ponteiros %p %p\n", p1, p2);
	ft_printf("%x\n", n);
	ft_printf("%X\n", n);

	printf("------printf--------\n");
	printf("ola tudo bem %c\n", c);
	printf("NULL s NULL\n", NULL);
	printf("42, %, adeus%d\n", n);
	printf("%i\n", i);
	printf("ponteiros %p %p\n", p1, p2);
	printf("%x\n", n);
	printf("%X\n", n);
	return (0);
}*/
