/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-13 10:02:59 by antabord          #+#    #+#             */
/*   Updated: 2025-05-13 10:02:59 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	l;

	l = 0;
	while (str[l])
	{
		l++;
	}
	return (l);
}
char	*ft_strdup(char *s)
{
	unsigned char	*p;
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	p = malloc((ft_strlen((const char *)str) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (i < (size_t)ft_strlen((const char *)str))
	{
		p[i] = (unsigned char)str[i];
		i++;
	}
	p[i] = '\0';
	return ((char *)p);
}
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

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)s == '\0')
	{
		return ((char *)(s + i));
	}
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	max;

	if (!s)
		return (NULL);
	i = 0;
	max = ft_strlen(s);
	if (start > max)
		return (ft_strdup(""));
	if (len > max - start)
		len = max - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
