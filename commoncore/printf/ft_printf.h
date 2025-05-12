/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-11 15:46:10 by antabord          #+#    #+#             */
/*   Updated: 2025-05-11 15:46:10 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdbool.h>

int	ft_printchar(char c);
int	ft_printf(const char *format, ...);
int	ft_printstr(char *str);
int	ft_printhexa(unsigned int nb);
int	ft_printhexa_upper(unsigned int nb);
int	ft_print_pointer(void *p);
int	ft_printint(int c);
int	ft_printunsigned(unsigned int c);

#endif
