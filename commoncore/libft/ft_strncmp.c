/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-16 13:48:56 by antabord          #+#    #+#             */
/*   Updated: 2025-04-16 13:48:56 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    int i;

    i = 0;
    while (i < n)
    {
        if (s1[i] != s2[i])
            break;
        i++;
    }
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*int main(void)
{
    char s1[] = "ola bom dia";
    char s2[] = "olb boa tarde";
    size_t n = 8;
    printf("%d\n",ft_strncmp(s1, s2, n));
    printf("%d\n", strncmp(s1, s2, n));
    return 0;
}*/
