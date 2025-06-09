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
	if (!str)
		return (0);
	while (str[l])
	{
		if (str[l] == '\n')
			return (l);
		l++;
	}
	return (l);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	if (!s)
		return (NULL);
	ch = (unsigned char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;
	size_t	total_len;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (s1[j])
		result[i++] = s1[j++];
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
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
		return (NULL);
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
