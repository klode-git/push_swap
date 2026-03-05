#include "push_swap.h"

void	pa(t_ps *ps)
{
	if (ps->b.top < 0)
		return ;
	ps->a.top++;
	ps->a.data[ps->a.top] = ps->b.data[ps->b.top];
	ps->b.top--;
	ft_putendl_fd("pa", 1);
	ps->ops.pa++;
	ps->ops.total++;
}

void	pb(t_ps *ps)
{
	if (ps->a.top < 0)
		return ;
	ps->b.top++;
	ps->b.data[ps->b.top] = ps->a.data[ps->a.top];
	ps->a.top--;
	ft_putendl_fd("pb", 1);
	ps->ops.pb++;
	ps->ops.total++;
}
