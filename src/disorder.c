#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	int		inversions;
	int		total_pairs;
	int		i;
	int		j;
	int		size;

	size = a->top + 1;
	if (size <= 1)
		return (0.0);
	inversions = 0;
	total_pairs = size * (size - 1) / 2;
	i = a->top;
	while (i > 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (a->data[i] > a->data[j])
				inversions++;
			j--;
		}
		i--;
	}
	return ((double)inversions / (double)total_pairs);
}
