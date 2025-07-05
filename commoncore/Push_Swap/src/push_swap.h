/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-27 13:57:25 by antabord          #+#    #+#             */
/*   Updated: 2025-06-27 13:57:25 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define NULL ((void *)0)

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				content;
	int				idx;
	struct s_stack	*next;
	struct s_stack	*prev;
}		t_stack;

//aux functions
long	ft_atol(char *str);
char	**ft_strjoin(char **s1, char **s2);

//main & arg breakdown
int		push_swap(int argc, char **argv);
char	**join_args(int ac, char **av);

//error & free
void	ft_err(void);
void	freedom(char **str);
void	freedom_stack(t_stack **stack);

//adding to lst & parsing
void	parser(t_stack **stack, char *av[]);
int		ft_isduplicate(t_stack *stack);
int		ft_isdigit_mod(char **nbr);

#endif
