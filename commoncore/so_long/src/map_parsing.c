#include "a_fun.h"
#include "a_structs.h"


int	char_finder(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == '\n'
		|| c == '\r')
		return (1);
	return (0);
}

char	*read_block(int fd)
{
	char buffer[1024 + 1];
	ssize_t bytes_read;

	bytes_read = read(fd, buffer, 1024);
	if (bytes_read <= 0)
		return (NULL);
	buffer[bytes_read] = '\0';
	return (ft_strdup(buffer));
}

int	validate_chars(char *s)
{
	ssize_t i;

	i = 0;
	while (s[i])
	{
		if (!char_finder(s[i]))
		{
			ft_puterr("Error: Invalid character [");
			write(2, &s[i], 1);
			write(2, "]\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

char	**line_check(char *str)
{
	char **lines;
	int i;
	int len;

	i = 0;
	lines = ft_split(str, '\n');
	if (!lines)
		return (NULL);
	while (lines[i])
	{
		len = ft_strlen(lines[i]);
		if (lines[i][len - 1] == '\n' || lines[i][len - 1] == '\r')
			lines[i][len - 1] = '\0';
		if (!check_walls(lines[i]))
			return (ft_free_all(lines), NULL);
		i++;
	}
	create_grid(lines, i);
	return (lines);
}

char	*line_reader(int fd)
{
	char *tmp;
	char *block;
	char *old;

	tmp = NULL;
	while ((block = read_block(fd)))
	{
		if (!validate_chars(block))
			return (free(block), free(tmp), NULL);
		if (!tmp)
			tmp = ft_strdup(block);
		else
		{
			old = tmp;
			tmp = ft_strjoin(tmp, block);
			free(old);
			if (!tmp)
				return (free(block), NULL);
		}
		free(block);
	}
	if (!tmp || !line_check(tmp))
		return (free(tmp), NULL);
	return (tmp);
}
