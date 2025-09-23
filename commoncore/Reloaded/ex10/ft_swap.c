/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:40:06 by antabord          #+#    #+#             */
/*   Updated: 2025/04/08 15:58:15 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_swap(int *a, int *b)
{
	int	temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

int	main(void)
{
	int	*a;
	int	*b;
	int	da;
	int	db;

	da = 1;
	db = 2;

	a = &da;
	b = &db;
	ft_swap(a, b);
	printf(" %d, %d", da, db);
	return (0);
}

