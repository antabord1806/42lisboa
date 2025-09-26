#include "a_fun.h"
#include "a_structs.h"

int	main(int argc, char **argv)
{
	int fd;
	size_t len;
	char *line;

	if (argc != 2)
		return (ft_puterr("Error: too many arguments!\n"), 1);
	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strncmp(argv[1] + len - 4, ".ber", 4))
		return (ft_puterr("Error: Invalid file extension (must end with .ber)\n"),
			1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_puterr("Error: Can't open file\n"), 1);
	line = line_reader(fd);
	close(fd);
	if (!line)
		return (1);
	free(line);
	return (0);
}
