#include "push_swap.h"

void	sort_two(t_ps *ps)
{
	if (ps->a.data[ps->a.top] > ps->a.data[ps->a.top - 1])
		sa(ps);
}

void	sort_three(t_ps *ps)
{
	int	a;
	int	b;
	int	c;

	a = ps->a.data[ps->a.top];
	b = ps->a.data[ps->a.top - 1];
	c = ps->a.data[ps->a.top - 2];
	if (a > b && b < c && a < c)
		sa(ps);
	else if (a > b && b > c)
	{
		sa(ps);
		rra(ps);
	}
	else if (a > b && b < c && a > c)
		ra(ps);
	else if (a < b && b > c && a < c)
	{
		sa(ps);
		ra(ps);
	}
	else if (a < b && b > c && a > c)
		rra(ps);
}
