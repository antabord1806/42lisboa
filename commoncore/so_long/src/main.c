#include "a_structs.h"
#include "a_fun.h"

int	main(int argc, char **argv)
{
	int		fd;
	size_t	len;

	if (argc != 2)
	{
		ft_puterr("Usage: ./so_long <file.ber>\n");
		return (1);
	}
	
	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0)
	{
		ft_puterr("Error: Invalid file extension (must end with .ber)\n");
		return (1);
	}
	
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_puterr("Error: Can't open file\n");
		return (1);
	}
	printf("starting\n");
	line_reader(fd);
	close(fd);
	return (0);
}