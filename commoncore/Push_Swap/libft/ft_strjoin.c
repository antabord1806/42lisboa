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

int		count_str(char **arr)
{
	int	len;

	len = -1;
	while (arr && arr[len])
		len++;
	return (len);
}

char	**ft_strjoin(char **s1, char **s2)
{
	int				i;
	char			**result;
	unsigned int	total;

	i = 0;
	total = count_str(s1) + count_str(s2);
	result = malloc(sizeof(char *) * (total + 1));
	if (!result)
		return (NULL);
	while (i < count_str(s1))
	{
		result[i] = ft_strdup(s1[i]);
		i++;
	}
	i = 0;
	while (i < count_str(s2))
	{
		result[i + count_str(s1)] = ft_strdup(s2[i]);
		i++;
	}
	result[count_str(s1) + count_str(s2)] = '\0';
	return (result);
}

/*int	main(void)
{
	char s1[] = "ola tudo bem";
	char s2[] = "adeus tudo mal";
	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}*/
