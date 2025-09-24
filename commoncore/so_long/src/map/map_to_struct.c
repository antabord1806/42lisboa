#include "structs.h"

int     add_line(t_grid *grid, char *str, int len)
{
    char    *s;

    s = malloc(sizeof(char *) * (len + 1));
    if (!s)
        return(free(grid), 1);
    s[len + 1] = '\0';
}

