#include "structs.h"

t_grid  *create_grid()
{
    t_grid *grid;

    grid = malloc(sizeof(t_grid));
    if (!grid)
        return ;
    grid->lines = NULL;
    grid->n_lines = 0;
    grid->n_collums = 0;
    return (grid);
}

int     add_line()