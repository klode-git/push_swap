#include "push_swap.h"

static void	bring_min_to_top(t_ps *ps)
{
	int	min_pos;
	int	dist_ra;
	int	dist_rra;

	min_pos = find_min_pos(&ps->a);
	dist_ra = ps->a.top - min_pos;
	dist_rra = min_pos + 1;
	if (dist_ra <= dist_rra)
	{
		while (dist_ra-- > 0)
			ra(ps);
	}
	else
	{
		while (dist_rra-- > 0)
			rra(ps);
	}
}

void	sort_simple(t_ps *ps)
{
	while (stack_size(&ps->a) > 0)
	{
		bring_min_to_top(ps);
		pb(ps);
	}
	while (stack_size(&ps->b) > 0)
		pa(ps);
}
