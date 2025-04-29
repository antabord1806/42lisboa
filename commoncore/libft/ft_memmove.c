/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-15 11:06:17 by antabord          #+#    #+#             */
/*   Updated: 2025-04-15 11:06:17 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	if (s > d)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

int main(void)
{
	char src[] = "";
	char dest1[] = "123456789101112";
	char dest2[] = "";
	ft_memmove(dest1, src, 4);
//	memmove(dest2, src, 4);
	printf("%s\n", dest1);
//	printf("%s", dest2);
	return (0);
}