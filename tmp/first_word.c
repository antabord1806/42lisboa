/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 21:05:47 by marvin            #+#    #+#             */
/*   Updated: 2025/07/05 21:05:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    first_word(char *c)
{
    int i;

    i = 0;
    while(c[i] == ' ' || c[i] == '\t')
    {
        i++;
    }
    while(c[i])
    {
        if ((c[i] == ' ' || c[i] == '\t'))
            return ;
        else
            write(1, &c[i], 1);
        i++;
    }
}

int     main(int ac, char **av)
{
    int j = 0;
    if (ac != 2)
    {
        write(1, "\n", 1);
        return (1);
    }
    first_word(av[1]);
    return (0);
}