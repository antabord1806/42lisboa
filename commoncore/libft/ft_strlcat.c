/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-15 13:36:20 by antabord          #+#    #+#             */
/*   Updated: 2025-04-15 13:36:20 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t dslen = ft_strlen(dst);
    size_t srclen = ft_strlen(src);

    i = 0;
    if (!src || !dst)
        return 0;
    if (dslen >= size)
        return (srclen + size);
    else
        while (src[i] && (dslen + i) <= (size - 1))
        {
            dst[dslen + i] = src[i];
            i++;
        }
        dst[dslen + i] = '\0';
        return (dslen + srclen);
}

int main(void)
{
    char src[] = "ola tudo bem";
    char dest1[] = "123456789101112";
    char dest2[] = "123456789101112";
    ft_strlcat(dest1, src, 4);
    strlcat(dest2, src, 4);
    printf("%s\n", dest1);
    printf("%s\n", dest2);
    return (0);
}
