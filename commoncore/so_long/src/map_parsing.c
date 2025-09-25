#include "a_structs.h"
#include "a_fun.h"

int	char_finder(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == '\n' || c == '\r')
		return (1);
	return (0);
}

char *read_block(int fd)
{
    char buffer[1024 + 1];
    ssize_t bytes_read;

    bytes_read = read(fd, buffer, 1024);
    if (bytes_read <= 0)
        return (NULL);
    buffer[bytes_read] = '\0';
	//printf("%s\n", buffer);
    return ft_strdup(buffer);
}

int validate_chars(char *s)
{
    ssize_t i;

	i = 0;
    while (s[i])
    {
		if (!char_finder(s[i]))
		{
			write(2, "Error: invalid character: [", 27);
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
	char	**lines;
	int		i;
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
	printf("ola\n");	
	create_grid(lines, i);
	return (lines);
}

char *line_reader(int fd)
{
    char *tmp;
	char *block;
    char *old;
	
	ft_puterr("DEBUG: starting line_reader\n");
	tmp = ft_strdup("");
	if (!tmp)
		return (NULL);
    while ((block = read_block(fd)))
    {
        if (!validate_chars(block))
            return (free(tmp), free(block), NULL);
        old = tmp;
        tmp = ft_strjoin(tmp, block);
		if (!tmp)
			return (free(old), free(block), NULL);
        free(old);
        free(block);
    }
	if (!tmp || !line_check(tmp))
		return(free(tmp), NULL);
    return tmp;
}


