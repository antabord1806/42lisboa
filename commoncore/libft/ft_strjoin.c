/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:47:50 by marvin            #+#    #+#             */
/*   Updated: 2025/04/19 17:47:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int				i;
	char			*result;
	unsigned int	total;

	i = 0;
	total = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (total + 1));
	if (!result)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		result[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	result[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (result);
}

/*int	main(void)
{
	char s1[] = "ola tudo bem";
	char s2[] = "adeus tudo mal";
	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}*/
