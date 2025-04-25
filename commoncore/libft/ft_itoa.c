/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-25 15:06:24 by antabord          #+#    #+#             */
/*   Updated: 2025-04-25 15:06:24 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_nb_str(char *str, int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * (-1);
		str[i] = '-';
	}
	if (n <= 9)
	{
		str[i] = (n + '0');
		i++;
	}
	else
	{
		ft_nb_str(str++, n / 10);
		ft_nb_str(str++, n % 10);
	}
	return (str);
}
static int	ft_int_len(int n)
{
	int	len;
	int	res;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	*final;
	int		len;

	len = ft_int_len(n);
	if (n < 0)
	{
		str = malloc((len + 2) * sizeof(char));
		if (!str)
			return ('\0');
		final = ft_nb_str(str, n);
	}
	else
	{
		str = malloc((len + 1) * sizeof(char));
		if (!str)
			return (NULL);
		final = ft_nb_str(str, n);
	}
	return (final);
}
int	main(void)
{
	int n;
	n = 8906;
	printf("%s\n", ft_itoa(n));
	return (0);
}