/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-11 16:04:51 by antabord          #+#    #+#             */
/*   Updated: 2025-05-11 16:04:51 by antabord         ###   ########.fr       */
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
		return (-1);
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