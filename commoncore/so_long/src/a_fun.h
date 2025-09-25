#ifndef A_FUN_H
#define A_FUN_H

#include "a_structs.h"
#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"

typedef struct s_grid t_grid;

int	main(int argc, char **argv);

//error + free
void	ft_puterr(char *s);
void	ft_free_all(char **arr_aloc);
void    free_grid(t_grid *grid);

//map
    //parsing
    char    *read_block(int fd);
    char    *line_reader(int fd);
    int     validate_chars(char *s);
    int     check_walls(char *str);
    int     check_counts(char **lines);
    int     line_parser(char *str);
    int     check_walls(char *line);
    int     count_e(char *str);
    int     count_p(char *str);
    int     is_square(char **lines, int n_lines);

    //to_struct
    t_grid      *create_grid(char **lines, int n_lines);

#endif