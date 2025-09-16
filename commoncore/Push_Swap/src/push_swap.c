
#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**args;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		ft_err();
	args = join_args(argc, argv);
	parser(&stack_a, args);
	ft_isduplicate(&stack_a);
	add_index(&stack_a);
	if (check_if_sorted(&stack_a, 1) || check_if_3(&stack_a))
	{
		freedom(args);
		freedom_stack(&stack_a);
		return (0);
	}
	printf("loop\n");
	push_loop_1(&stack_a, &stack_b);
	freedom(args);
	freedom_stack(&stack_a);
	return (0);
}
