/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-22 10:30:57 by antabord          #+#    #+#             */
/*   Updated: 2025-05-22 10:30:57 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*line_extractor(char *temp)
{
	size_t	len;

	len = 0;
	if (!temp || !*temp)
		return (NULL);
	while (temp[len] && temp[len] != '\n')
		len++;
	if (temp[len] == '\n')
		len++;
	return (ft_substr(temp, 0, len));
}

static char	*temp_getter(int fd, char *temp)
{
	char	*old_temp;
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (BUFFER_SIZE < 1 || !buffer)
		return (free(buffer), NULL);
	while (bytes_read > 0 && !ft_strchr(temp, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(temp), NULL);
		buffer[bytes_read] = '\0';
		if (!temp)
			temp = ft_strdup(buffer);
		else
		{
			old_temp = temp;
			temp = ft_strjoin(temp, buffer);
			free(old_temp);
		}
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
	restos = ft_substr(temp, i, ft_strlen(temp) - i);
	free(temp);
	return (restos);
}

char	*get_next_line(int fd)
{
	static char	*temp[FOPEN_MAX];
	char		*line;

	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	temp[fd] = temp_getter(fd, temp[fd]);
	if (!temp[fd])
		return (NULL);
	line = line_extractor(temp[fd]);
	if (!line)
	{
		free(temp[fd]);
		temp[fd] = NULL;
		return (NULL);
	}
	temp[fd] = temp_destroyer(temp[fd]);
	return (line);
}
/*int main(void)
{
	int fd1 = open("arquivo1.txt", O_RDONLY);
	int fd2 = open("arquivo2.txt", O_RDONLY);
	int fd3 = open("arquivo3.txt", O_RDONLY);
	char *linha1;
	char *linha2;
	char *linha3;

	while (1)
	{
		linha1 = get_next_line(fd1);
		linha2 = get_next_line(fd2);
		linha3 = get_next_line(fd3);

		if (!linha1 && !linha2)
			break ;

		if (linha1)
		{
			printf("arq1_ %s", linha1);
			free(linha1);
		}
		if (linha2)
		{
			printf("arq2_ %s", linha2);
			free(linha2);
		}
		if (linha3)
		{
			printf("arq3_ %s", linha3);
			free(linha3);
		}
	}

	close(fd3);
	close(fd1);
	close(fd2);
	return (0);
}*/
