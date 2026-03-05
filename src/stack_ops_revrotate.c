#include "push_swap.h"

static void	rev_rotate(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->top < 1)
		return ;
	tmp = s->data[0];
	i = 0;
	while (i < s->top)
	{
		s->data[i] = s->data[i + 1];
		i++;
	}
	s->data[s->top] = tmp;
}

void	rra(t_ps *ps)
{
	rev_rotate(&ps->a);
	ft_putendl_fd("rra", 1);
	ps->ops.rra++;
	ps->ops.total++;
}

void	rrb(t_ps *ps)
{
	rev_rotate(&ps->b);
	ft_putendl_fd("rrb", 1);
	ps->ops.rrb++;
	ps->ops.total++;
}

void	rrr(t_ps *ps)
{
	rev_rotate(&ps->a);
	rev_rotate(&ps->b);
	ft_putendl_fd("rrr", 1);
	ps->ops.rrr++;
	ps->ops.total++;
}
