/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-16 10:46:55 by antabord          #+#    #+#             */
/*   Updated: 2025-04-16 10:46:55 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    int i;
    while (*s)
    {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    if (*s == '\0')
        return (char *)s;
}

/*int main(void)
{
    const char  s[] = "ola tudo bem";
    int c = 'b';
    char *res1 = ft_strchr(s, c);
    char *res2 = strchr(s, c);
    printf("%s\n", res1);
    printf("%s\n", res2);
    return 0;
}*/