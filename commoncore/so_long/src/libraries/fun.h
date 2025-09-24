#ifndef FUN_H
#define FUN_H

#include "structs.h"

//map
    //parsing
    int		line_reader();
    int		line_parser(char *str);
    int		char_finder(char *str);
    //utils
    char	*ft_strjoin(char const *s1, char const *s2);

#endif