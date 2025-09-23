#include "structs.h"
#include "functions.h"

int		line_reader(const char *map)
{
	int		fd;
	size_t	bytes_read;
	char	buffer[2];
	char	*tmp;
	char	*old_buffer;

	tmp = NULL;
	fd = open("map.ber", _A_RDONLY);
	if (fd < 0)
		return (perror("Error\n Cant open file!"), 1);
	while (bytes_read > 0 && char_finder(buffer))
	{
		old_buffer = tmp;
		bytes_read = read(fd, buffer, 2);
		if (!bytes_read)
			return (perror("Error\n File is empty!"), 1);
		buffer[bytes_read] = "\0";
		tmp = ft_strjoin(tmp, buffer);
		free(old_buffer);
	}
	old_buffer = line_parser(tmp);
	free(tmp);
}

int		line_parser(char *str)
{
	int	i;
	int	p;
	int	e;

	p = 0;
	e = 0;
	i = 0;
	if (str[i] != '1')
		return (perror("Error\n Invalid map walls not closed"), 1);
	while (str[i++])
	{
		if (str[i] == 'E')
			e++;
		if (str[i] == 'P')
			p++;
	}
	if (e > 1)
		return	(perror("Error\n Too many exits"), 1);
	if (p > 1)
		return (perror("Error\n Too many spawn points"), 1);
	if (str[i] != '1')
		return (perror("Error\n Invalid map walls not closed"), 1);
	return (i);
}

int		char_finder(char *str)
{
	if (str[0] != "0" || str[0] != "1" || str[0] != "C" || str[0] != "E")	
	{
		perror("Error\n Invalid character");
		return (0);
	}
}