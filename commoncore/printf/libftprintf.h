/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:44:30 by marvin            #+#    #+#             */
/*   Updated: 2025/05/09 11:44:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int     ft_putchar(char c);
int     ft_printchar(char c);
int     ft_printf(const char *format, ...);
int     ft_printstr(char *str);
int     ft_printhexa(unsigned nb);
int     ft_printhexa_upper(unsigned nb);
int     ft_print_pointer(void *p);
int     ft_printint(int c);
int     ft_printunsigned(unsigned c);

#endif