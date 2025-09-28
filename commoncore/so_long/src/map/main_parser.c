/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-27 15:26:37 by antabord          #+#    #+#             */
/*   Updated: 2025-09-27 15:26:37 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../a_structs.h"
#include "../a_fun.h"

t_map	*main_parser(int argc, char **argv)
{
	int fd;
	char *line;
	char **grid;
	t_map *map;

	(void)map;
	if (argc != 2)
		return (/*ft_puterr("Error: too many arguments!\n"), */NULL);
	if (ft_strlen(argv[1]) < 4 || ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4,
			".ber", 4))
		return (/*ft_puterr("Error: Invalid file extension\n"), */NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (/*ft_puterr("Error: Can't open file\n"), */NULL);
	line = line_reader(fd);
	close(fd);
	if (!line)
		return (NULL);
	grid = line_check(line);
	fd = n_lines(grid);
	map = create_map(grid, fd);
	free(line);
	return (map);
}

int	n_lines(char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
		i++;
	return (i);
}