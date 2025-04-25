/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-15 13:36:20 by antabord          #+#    #+#             */
/*   Updated: 2025-04-15 13:36:20 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	src_len = ft_strlen(src);
	// Encontra o tamanho atual de dst
	while (dst[dst_len] && dst_len < dstsize)
		dst_len++;
	// Se dst_len >= dstsize, não há espaço para copiar nada
	if (dst_len == dstsize)
		return (dstsize + src_len);
	// Copia os caracteres de src para dst (sem ultrapassar dstsize - 1)
	i = 0;
	while (src[i] && (dst_len + i + 1) < dstsize)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	// Finaliza com '\0' se couber
	if (dst_len + i < dstsize)
		dst[dst_len + i] = '\0';
	// Retorna o tamanho total que teria sido criado
	return (dst_len + src_len);
}

/*int	main(void)
{
	char	src[] = "123456790089898889";
	char	dest1[] = "ola tudo bem";
	char	dest2[] = "ola tudo bem";

	ft_strlcat(dest1, src, 0);
	strlcat(dest2, src, 0);
	printf("%s\n", dest1);
	printf("%s\n", dest2);
	return (0);
}*/
