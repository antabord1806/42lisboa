/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:22:18 by marvin            #+#    #+#             */
/*   Updated: 2025/07/02 22:22:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char    *epur_str(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (str[i] == 9)
            str[i] = ' ';
        write (1, &str[i], 1);
        i++;
    }
}

int main(int ac, char **av)
{
    int i = 0;

    if (ac != 2)
    {
        write(1, "\n", 1);
        return (0)
    }
    epur_str(av[1]);
}