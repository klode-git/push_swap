#include "push_swap.h"

void	stack_init(t_ps *ps, int size)
{
	ps->a.data = (int *)malloc(sizeof(int) * size);
	ps->b.data = (int *)malloc(sizeof(int) * size);
	if (!ps->a.data || !ps->b.data)
		error_exit(ps);
	ps->a.capacity = size;
	ps->b.capacity = size;
	ps->a.top = -1;
	ps->b.top = -1;
}

static void	copy_and_sort(int *sorted, int *data, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		sorted[i] = data[i];
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (sorted[i] > sorted[j])
			{
				tmp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	normalize_indices(t_ps *ps)
{
	int	*sorted;
	int	size;
	int	i;
	int	j;

	size = ps->a.top + 1;
	sorted = (int *)malloc(sizeof(int) * size);
	if (!sorted)
		error_exit(ps);
	copy_and_sort(sorted, ps->a.data, size);
	i = 0;
	while (i <= ps->a.top)
	{
		j = 0;
		while (j < size)
		{
			if (ps->a.data[i] == sorted[j])
			{
				ps->a.data[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(sorted);
}
