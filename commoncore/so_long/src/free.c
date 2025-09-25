#include "a_structs.h"
#include "a_fun.h"

void	ft_free_all(char **arr_aloc)
{
	int	i;

	i = 0;
	while (arr_aloc[i])
	{
		free(arr_aloc[i]);
		i++;
	}
	free(arr_aloc);
}

void free_grid(t_grid *grid)
{
    if (!grid)
        return;
    if (grid->lines)
        ft_free_all(grid->lines);
    free(grid);
}
