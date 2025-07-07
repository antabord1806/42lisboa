/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:59:43 by marvin            #+#    #+#             */
/*   Updated: 2025/07/06 14:59:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;

    while (s1[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}

int main(void)
{
    char s1[50] = "ola tudo bem";
    char *s2 = "adeus";

    ft_strcpy(s1, s2);
    printf("%s\n", s1);
    return (0);
}