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
	int				idx;
	int				target;
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
int		ft_isduplicate(t_stack **stack);
int		ft_isdigit_mod(char **nbr);
void	add_index(t_stack **stack);

//processing stack
int		check_if_sorted(t_stack **stack);
int		check_if_3(t_stack **stack_a, t_stack **stack_b);
void	stack_is_2(t_stack **stack_a);
void	stack_is_3(t_stack **stack_a);

//operations
	//rotate
		void	rotate_a(t_stack **head);
		void	rotate_b(t_stack **head);
		void	rotate_ab(t_stack **head_a, t_stack **head_b);
	//reverse rotate
		void	reverse_rotate_a(t_stack **head);
		void	reverse_rotate_b(t_stack **head);
		void	reverse_rotate_ab(t_stack **head_a, t_stack **head_b);
	//push
		void	push_a(t_stack **head_b, t_stack **head_a);
		void	push_b(t_stack **head_a, t_stack **head_b);
	//swap
		void	swap_a(t_stack **head_a);
		void	swap_b(t_stack **head_b);
		void	swap_ab(t_stack **head_a, t_stack **head_b);

//algo implementation -- turksort
void	push_loop(t_stack *stack_a, t_stack *stack_b);


#endif
