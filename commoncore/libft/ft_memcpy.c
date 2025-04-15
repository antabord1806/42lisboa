/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-15 10:28:14 by antabord          #+#    #+#             */
/*   Updated: 2025-04-15 10:28:14 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *source = (unsigned char *)src;
    unsigned char *destino = (unsigned char *)dest;

    size_t i = 0;
    if (!src && !dest == NULL)
        return NULL;
    while (n--)
    {
        destino[i] = source[i];
        i++;
    }
    return (destino);
}

/*int main(void)
{
    char src[] = "ola tudo bem";
    char dest1[] = "123456789101112";
    char dest2[] = "123456789101112";
    ft_memcpy(dest1, src, 4);
    memcpy(dest2, src, 4);
    printf("%s\n", dest1);
    printf("%s", dest2);
    return (0);
}*/