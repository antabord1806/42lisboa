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

int    ft_strcheck(char s1, char *set)
{
    int i;

    i = 0;
    while (set[i])
    {
        if (s1 == set[i])
            return (1);
        i++;
    }
 return (0);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    char *new_str;
    int start;
    int end;

    start = 0;
    end = ft_strlen(s1) - 1;
    if (!s1 || !set)
        return NULL;
    while (s1[start] && ft_strcheck(s1[start], (char *)set))
    {
        start++;
    }
    while (start < end && ft_strcheck(s1[end], (char *)set))
    {
        end--;
    }
    new_str = ft_substr(s1, start, start - end + 1);
    return new_str;
}

int	main(void)
{
	char s1[] = "     ola tudo bem     ";
	char set[] = "ob m";
	printf("%s\n", ft_strtrim(s1, set));
	return 0;
}
