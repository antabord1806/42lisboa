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

static int	count_str(char **arr)
{
	int	len;

	len = 0;
	while (arr && arr[len])
		len++;
	return (len);
}

char	**ft_strjoin(char **s1, char **s2)
{
	int		i;
	char	**result;
	size_t	len1;
	size_t	len2;

	i = -1;
	len1 = count_str(s1);
	len2 = count_str(s2);
	result = malloc(sizeof(char *) * (len1 + len2 + 1));
	if (!result)
		return (NULL);
	while (++i < (int)len1)
		result[i] = ft_strdup(s1[i]);
	i = -1;
	while (++i < (int)len2)
		result[i + len1] = ft_strdup(s2[i]);
	result[len1 + len2] = NULL;
	freedom(s1);
	freedom(s2);
	return (result);
}

/*int	main(void)
{
	char s1[] = "ola tudo bem";
	char s2[] = "adeus tudo mal";
	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}*/
