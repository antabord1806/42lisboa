/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-14 11:36:50 by antabord          #+#    #+#             */
/*   Updated: 2025-04-14 11:36:50 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int ft_strlen(char *str)
{
    int l;

    l = 0;
    while (str[l])
    {
        l++;
    }
    return (l);
}

int main(void)
{
    printf("%d", ft_strlen("ola tudo "));
    return (0);
}