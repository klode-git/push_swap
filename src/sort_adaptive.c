#include "push_swap.h"

void	sort_adaptive(t_ps *ps)
{
	int		n;
	double	d;

	n = stack_size(&ps->a);
	d = compute_disorder(&ps->a);
	if (d < 0.1 && n > 10)
		sort_medium(ps);
	else
		sort_turkish(ps);
	(void)d;
}
