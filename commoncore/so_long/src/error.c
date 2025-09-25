#include "a_fun.h"
#include "a_structs.h"

void	ft_puterr(char *s)
{
	int i;

	if (!s)
		return;
	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
}
