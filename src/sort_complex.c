#include "push_swap.h"

static int	get_max_bits(int n)
{
	int	bits;

	bits = 0;
	while ((n - 1) >> bits)
		bits++;
	return (bits);
}

void	sort_complex(t_ps *ps)
{
	int	bit;
	int	max_bits;
	int	size;
	int	i;

	size = stack_size(&ps->a);
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if ((ps->a.data[ps->a.top] >> bit) & 1)
				ra(ps);
			else
				pb(ps);
			i++;
		}
		while (stack_size(&ps->b) > 0)
			pa(ps);
		bit++;
	}
}
