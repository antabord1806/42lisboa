/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-23 14:52:10 by antabord          #+#    #+#             */
/*   Updated: 2025-04-23 14:52:10 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	int	i;
	int j;
	int len;
	int	count;
	char	**str;
	char	**sub;

	i = 0;
	j = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			len = i - j;
			sub[count] = ft_substr((char *)s, i, len);
			str[count] = ft_strdup(sub[count]);
			count++;
			j = i;
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	printf("%s\n", ft_split("ola,boa,tarde", ','));
	return (0);
}