#include "push_swap.h"

void	free_ps(t_ps *ps)
{
	if (ps->a.data)
		free(ps->a.data);
	if (ps->b.data)
		free(ps->b.data);
}

void	error_exit(t_ps *ps)
{
	free_ps(ps);
	ft_putendl_fd("Error", 2);
	exit(1);
}
