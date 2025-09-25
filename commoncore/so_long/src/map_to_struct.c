#include "a_structs.h"
#include "a_fun.h"

static t_grid *init_grid(void)
{
    t_grid *grid = malloc(sizeof(t_grid));
    if (!grid)
        return NULL;
    grid->lines = NULL;
    grid->n_lines = 0;
    grid->n_columns = 0;
    return grid;
}

t_grid *create_grid(char **line, int n_lines)
{
    t_grid *grid;
    
    grid = init_grid();
    if (!grid)
        return NULL;
    grid->n_columns = ft_strlen(line[0]);
    grid->lines = line;
    grid->n_lines = n_lines;
    if (!is_square(line, n_lines))
    {
        ft_puterr("Error: The map is not rectangular\n");
        return (free_grid(grid), NULL);
    }
    if (!check_counts(line))
        return (free_grid(grid), NULL);
    printf("grid created\n");
    free_grid(grid);
    return grid;
}
