/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-18 08:38:19 by antabord          #+#    #+#             */
/*   Updated: 2025-04-18 08:38:19 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(const char *s)
{
    unsigned char *p;
    size_t i;

    unsigned char *str = (unsigned char *)s;
    i = 0;
    if (s == NULL)
    { 
        printf("string is empty");
        return NULL;
    }
    p = malloc((ft_strlen((const char *)str) + 1) * sizeof(char));
    while (i < ft_strlen((const char *)str))
    {
        p[i] = (unsigned char )str[i];
        i++;
    }
    p[i] = '\0';
    return p;
}
/*int main(void)
{
    char *p;
    int i;
    i = 0;
    p = (char *)ft_strdup("");
    while (i < ft_strlen(p))
    {
        printf("%c", p[i]);
        i++;
    }
    printf("\n");
    free(p);
    return (0);
}*/