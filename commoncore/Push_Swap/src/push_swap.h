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
int		ft_atoi(char *s);
int		ft_isdigit(int c);
char	**ft_strjoin(char **s1, char **s2);

//main & arg breakdown
int		push_swap(int argc, char **argv);
char	**join_args(int ac, char **av);

//error & free
void	ft_err(void);
void	freedom(char **str);

//adding to lst & parsing
void	parser(t_stack **stack, char *av[]);
void	ft_lstadd_back_mod(t_stack **lst, t_stack *new);
void	filters(t_stack *stack);


#endif
