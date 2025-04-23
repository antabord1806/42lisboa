/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putend1_fd                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-23 10:52:05 by antabord          #+#    #+#             */
/*   Updated: 2025-04-23 10:52:05 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putend1_fd(char *s, int fd)
{
	if (!s)
		return NULL;
	while (*s)
	{
		write (fd, s, 1);
		s++;
	}
	write (fd, "\n", 1);
}

int	main(void)
{
	ft_putend1_fd("ola tudo bem", 1);
	return 0;
}