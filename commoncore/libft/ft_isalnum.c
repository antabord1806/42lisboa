/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-14 11:10:03 by antabord          #+#    #+#             */
/*   Updated: 2025-04-14 11:10:03 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int ft_isalnum(int c)
{
    return (ft_isalpha() || ft_isdigit());
}

int main(void)
{
    printf("%d", ft_isalnum(49));
    return (0);
}