#include "push_swap.h"

static void	rotate(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->top < 1)
		return ;
	tmp = s->data[s->top];
	i = s->top;
	while (i > 0)
	{
		s->data[i] = s->data[i - 1];
		i--;
	}
	s->data[0] = tmp;
}

void	ra(t_ps *ps)
{
	rotate(&ps->a);
	ft_putendl_fd("ra", 1);
	ps->ops.ra++;
	ps->ops.total++;
}

void	rb(t_ps *ps)
{
	rotate(&ps->b);
	ft_putendl_fd("rb", 1);
	ps->ops.rb++;
	ps->ops.total++;
}

void	rr(t_ps *ps)
{
	rotate(&ps->a);
	rotate(&ps->b);
	ft_putendl_fd("rr", 1);
	ps->ops.rr++;
	ps->ops.total++;
}
