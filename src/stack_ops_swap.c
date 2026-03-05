#include "push_swap.h"

static void	swap(t_stack *s)
{
	int	tmp;

	if (s->top < 1)
		return ;
	tmp = s->data[s->top];
	s->data[s->top] = s->data[s->top - 1];
	s->data[s->top - 1] = tmp;
}

void	sa(t_ps *ps)
{
	swap(&ps->a);
	ft_putendl_fd("sa", 1);
	ps->ops.sa++;
	ps->ops.total++;
}

void	sb(t_ps *ps)
{
	swap(&ps->b);
	ft_putendl_fd("sb", 1);
	ps->ops.sb++;
	ps->ops.total++;
}

void	ss(t_ps *ps)
{
	swap(&ps->a);
	swap(&ps->b);
	ft_putendl_fd("ss", 1);
	ps->ops.ss++;
	ps->ops.total++;
}
