/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:51:49 by marvin            #+#    #+#             */
/*   Updated: 2025/06/29 18:51:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int push_swap(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int     str;

    if (argc < 2)
        return (ft_err(void));
    str = checker(argc, **argv);
    
}