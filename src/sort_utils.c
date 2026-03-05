#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	int	i;

	if (a->top <= 0)
		return (1);
	i = a->top;
	while (i > 0)
	{
		if (a->data[i] > a->data[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	stack_size(t_stack *s)
{
	return (s->top + 1);
}

int	find_min_pos(t_stack *s)
{
	int	min;
	int	pos;
	int	i;

	min = s->data[s->top];
	pos = s->top;
	i = s->top - 1;
	while (i >= 0)
	{
		if (s->data[i] < min)
		{
			min = s->data[i];
			pos = i;
		}
		i--;
	}
	return (pos);
}

int	find_max_pos(t_stack *s)
{
	int	max;
	int	pos;
	int	i;

	max = s->data[s->top];
	pos = s->top;
	i = s->top - 1;
	while (i >= 0)
	{
		if (s->data[i] > max)
		{
			max = s->data[i];
			pos = i;
		}
		i--;
	}
	return (pos);
}
