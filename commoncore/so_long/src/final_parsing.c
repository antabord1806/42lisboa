#include "a_structs.h"
#include "a_fun.h"

int	top_bottom_walls(char *st_line, char *lst_line)
{
	int	i;

	i = 0;
	while (st_line[i] && lst_line[i])
	{
		if (st_line[i] != '1' || lst_line[i] != '1')
		{
			ft_puterr("Error: Map walls invalid\n");
			return (0);
		}
		i++;
	}
	return (1);
}

char	**find_e(char **str, int max_x)
{
	int	x;

	x = 0;
	while ()
}

int	way_out(char **lines, int max_y, int max_x)
{
	char	**p;
	char 	**e;
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < max_y)
	{
		while (x < max_x)
		{
			if (e == '\0')
				e = find_e(lines[y][x], max_x);
			if (p == '\0')
				p = find_p(lines[y][x]);
			x++;
		}
		y++;
	}
}

