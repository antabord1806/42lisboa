/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-13 09:29:21 by antabord          #+#    #+#             */
/*   Updated: 2025-05-13 09:29:21 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_extractor(char *temp)
{
	size_t	len;

	len = 0;
	while (temp[len] && temp[len] != '\n')
		len++;
	if (temp[len] == '\n')
		len++;
	if (!temp[len])
		return (NULL);
	return (ft_substr(temp, 0, len));
}

char	*temp_getter(int fd, char *temp)
{
	int		bytes_read;
	char	buffer[BUFFER_SIZE + 1];
	char	*old_temp;

	bytes_read = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	while (bytes_read > 0 && !ft_strchr(temp, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		old_temp = temp;
		if (bytes_read < 0)
			break
	}
	temp[bytes_read] = '\0';
	if (!temp)
		return (NULL);
	temp = ft_strjoin(temp, buffer);
	free(old_temp);
	return (temp);
}
char	*temp_destroyer(char *temp)
{
	char	*restos;
	size_t	i;

	i = 0;
	while (temp[i] != '\n' && temp[i])
		i++;
	if (temp[i] == '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	restos = ft_substr(temp, i, ft_strlen(temp) - i);
	free(temp);
	return (restos);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	temp = temp_getter(fd, temp);
	if (!temp)
		return (NULL);
	line = line_extractor(temp);
	if (!line)
		return (NULL);
	temp = temp_destroyer(temp);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*linha;

	// Abre o arquivo para leitura
	fd = open("exemplo.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erro ao abrir o arquivo");
		return (1);
	}
	// Lê e imprime linha por linha
	while ((linha = get_next_line(fd)) != NULL)
	{
		printf("%s", linha);
		free(linha); // Libera a memória da linha
	}
	close(fd); // Fecha o arquivo
	return (0);
}
