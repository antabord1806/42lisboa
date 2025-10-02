#ifndef A_FUN_H
#define A_FUN_H

#include "a_structs.h"
#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"

#ifndef TILE_SIZE
#define TILE_SIZE 64
#endif

typedef struct s_map t_map;
typedef struct s_game t_game;
typedef struct s_player t_player;

int	main(int argc, char **argv);

//error + free
void	ft_puterr(char *s);
void	ft_free_all(char **arr_aloc);
void    free_grid(t_map *map);

//map
    //parsing
    t_map	*main_parser(int argc, char **argv);
    char    *read_block(int fd);
    char    *line_reader(int fd);
    char    **line_check(char *str);
    int     n_lines(char **grid);
    int     validate_chars(char *s);
    int     check_walls(char *line);
    int     check_counts(char **lines);
    int     line_parser(char *str);
    int     count_e(char *str);
    int     count_p(char *str);
    int     is_square(char **lines, int n_lines);
    int     top_bottom_walls(char *st_line, char *lst_line);
    int     e_p_finder(char **lines, int max_y, int max_x);
    void	flood_fill_st(t_map **map, int x, int y, int height);
    void	flood_filled(char **copy, int x, int y, int *coins);
    int     coin_count(t_map *map);
    void	print_map(char **grid, int height);
    
    //to_struct
    t_map   *create_map(t_map **map, char **lines, int n_lines);
    t_map	*init_grid(void);
    t_game  *game_init(t_map *map, t_player *player);
    t_player    *player_init();
    void    find_p_x(t_map *map);
    void    find_p_y(t_map *map);

    //render
    void    load_images(void *mlx, t_map *map);
    void	map_render(t_game *game);
    void	*rendering_ground(int y, t_map *map);
    void    *img_drawing(t_game *game, int y, int x);
    
    //keys & hooks
    void	key_hooks(void *win, t_game *game);
    int     handle_keypress(int key, t_game *game);
    int     move_check(t_game *game, int new_y, int new_x, char key);
    void	move_player(t_game *game, int new_y, int new_x);
    int     destroy_win(t_game *game);
    int     minimizer();
    int     maximizer();
    int     ressizer();

#endif