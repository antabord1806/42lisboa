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

static int	ft_word_counter(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			j++;
		i++;
	}
	return (j + 1); // nr palavras
}
static int	*ft_word_len(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	int		*str;

	i = 0;
	j = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			len = i - j;
			str[i] = len;
			j = i;
		}
		i++;
	}
	return str;//array de comprimentos
}
static char	**ft_str_aloc(char const *s, char c)
{
	int		i;
	int		col;
	int		*line;
	char	**new_str;

	new_str = malloc(sizeof(char **) * (col + 1));
	i = 0;
	*line = ft_word_len(s, c);
	col = ft_word_counter(s, c);
	while (i < col)
	{
		new_str[i] = malloc(sizeof(char *) * line[i]);
	}
}
char	**ft_split(char const *s, char c)
{
	int i;
	int wr_len;
	int wr_counter = ft_word_counter(s, c);
	char **new_str;

	int main(void)
	{
		printf("%s\n", ft_split("ola,boa,tarde", ','));
		return (0);
	}