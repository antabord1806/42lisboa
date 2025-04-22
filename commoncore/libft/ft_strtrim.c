/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:18:46 by marvin            #+#    #+#             */
/*   Updated: 2025/04/21 14:18:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strcheck(char c, char const *set)
{
    while (*set)
        if (c == *set)
            return 1;
        return 0;
}

char    *ft_strtrim(const char *s1, const char *set)
{
    int start;
    int end;
    int i;
    char *new_string;

    i = 0;
    stert = 0;
    if (!s1)
        return NULL;
    if (!set)
        return (unsigned char *)s1;
    while (s1[start])
    {
        ft_strcheck(s1[i], set)
        start++;
    }
    end = ft_strlen(s1) - 1;
    i = 0;
    while (start <= end)
    {
        ft_strcheck()
    }
    
}

int	main(void)
{
	char s1[] = "ola tudo bem";
	char set[] = "ob m";
	printf("%s\n", ft_strtrim(s1, set));
	return 0;
}
