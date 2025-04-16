/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-14 12:39:56 by antabord          #+#    #+#             */
/*   Updated: 2025-04-14 12:39:56 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>


void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char *p = (unsigned char *) s;

    if (s == NULL)
        return NULL;
    size_t i = 0;
    while (i < n)
    {
        p[i] = (unsigned char)c;
        i++;
    }
    return s;
}
/*int main(void)
{
    char str1[] = "ola mundo";
    char str2[] = "ola mundo";
    ft_memset(str1, 'a', 5);
    memset(str2, 'a', 5);
    printf("%s\n", str1);
    printf("%s", str2);
    return 0;
}*/
