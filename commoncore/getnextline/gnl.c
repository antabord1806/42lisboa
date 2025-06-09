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

static char	*line_extractor(char *temp, int start)
{
	size_t	len;
	char	*sub;
	size_t	i;

	i = 0;
	len = 0;
	if (!temp || !*temp)
		return (NULL);
	while (temp[len + start] && temp[len + start] != '\n')
		len++;
	if (temp[len + start] == '\n')
		len++;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = temp[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

static char	*temp_getter(int fd, char *temp)
{
	char	*old_temp;
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (BUFFER_SIZE < 1 || fd < 0 || !buffer)
		return (free(buffer), NULL);
	while (bytes_read > 0 && !ft_strchr(temp, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		old_temp = temp;
		temp = ft_strjoin(temp, buffer);
		free(old_temp);
	}
	free(buffer);
	return (temp);
}

static char	*temp_destroyer(char *temp)
{
	char	*restos;
	size_t	i;

	i = 0;
	if (!temp)
		return (NULL);
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	restos = line_extractor(temp, i);
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
	line = line_extractor(temp, 0);
	if (!line)
	{
		free(temp);
		temp = NULL;
		return (NULL);
	}
	temp = temp_destroyer(temp);
	return (line);
}
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("arquivo1.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Erro ao abrir o arquivo");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
