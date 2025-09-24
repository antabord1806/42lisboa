#include "../libraries/fun.h"
#include "../libraries/structs.h"


t_grid	*create_grid(void)
{
	t_grid *grid;

	grid = malloc(sizeof(t_grid));
	if (!grid)
		return (NULL);
	grid->lines = NULL;
	grid->n_lines = 0;
	grid->n_collums = 0;
	printf("grid created\n");
	return (grid);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int i;
	char *result;
	unsigned int total;

	i = 0;
	total = ft_strlen(s1) + ft_strlen(s2);
	if (!ft_strlen(s2))
		return (NULL);
	result = malloc(sizeof(char) * (total + 1));
	if (!result)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		result[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	result[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (result);
}
int	main(/* t_grid *grid */)
{
	int fd;
	ssize_t bytes_read;
	char buffer[2];
	char *tmp;
	char *old_buffer;

	bytes_read = 1;
	tmp = NULL;
	fd = open("src/map/map.ber", O_RDONLY);
	if (fd < 0)
		return (perror("Error Cant open file!\n"), 1);
	while ((bytes_read = read(fd, buffer, 1)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (!char_finder(buffer))
			return (free(tmp), close(fd), 1);
		old_buffer = tmp;
		tmp = ft_strjoin(tmp, buffer);
		free(old_buffer);
		
	}
	if (!tmp || tmp[0] == '\0')
	return (close(fd), /* perror("Error File is empty!\n"),  */1);
	fd = line_parser(tmp);
	//add_line(grid, tmp, fd);
	return (free(tmp), close(fd), 0);
	printf("tudo bem");
}

int	char_finder(char *str)
{
	if (str[0] != '0' && str[0] != '1' && str[0] != 'C' && str[0] != 'E'
		&& str[0] != 'P')
	{
		/* perror("Error Invalid character\n"); */
		return (0);
	}
	return (1);
}
int	line_parser(char *str)
{
	int i;
	int p;
	int e;

	p = 0;
	e = 0;
	i = 0;
	if (str[i] != '1')
		return (free(str), /* perror("Error Invalid map walls\n"), */ 1);
	while (str[i])
	{
		if (str[i] == 'E')
			e++;
		if (str[i] == 'P')
			p++;
		i++;
	}
	if (e > 1)
		return (free(str), /* perror("Error Too many exits\n"), */ 1);
	if (p > 1)
		return (free(str), /* perror("Error Too many spawn points\n"), */ 1);
	if (str[i - 1] != '1')
		return (free(str), /* perror("Error Invalid map walls"),  */1);
	return (i);
}
