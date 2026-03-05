#include "push_swap.h"

static int	get_chunk_size(int n)
{
	if (n <= 20)
		return (n / 2);
	if (n <= 100)
		return (n / 5);
	return (n / 11);
}

static int	find_nearest_in_range(t_stack *a, int lo, int hi)
{
	int	from_top;
	int	from_bot;

	from_top = 0;
	while (from_top <= a->top)
	{
		if (a->data[a->top - from_top] >= lo
			&& a->data[a->top - from_top] < hi)
			break ;
		from_top++;
	}
	from_bot = 0;
	while (from_bot <= a->top)
	{
		if (a->data[from_bot] >= lo && a->data[from_bot] < hi)
			break ;
		from_bot++;
	}
	if (from_top <= from_bot + 1)
		return (from_top);
	return (-(from_bot + 1));
}

static void	rotate_to_top(t_ps *ps, int dist)
{
	if (dist >= 0)
	{
		while (dist-- > 0)
			ra(ps);
	}
	else
	{
		dist = -dist;
		while (dist-- > 0)
			rra(ps);
	}
}

static void	push_chunks_to_b(t_ps *ps, int chunk_size, int n)
{
	int	pushed;
	int	chunk_start;
	int	dist;

	pushed = 0;
	chunk_start = 0;
	while (pushed < n)
	{
		while (pushed < chunk_start + chunk_size && pushed < n)
		{
			dist = find_nearest_in_range(&ps->a, chunk_start,
					chunk_start + chunk_size);
			rotate_to_top(ps, dist);
			pb(ps);
			if (ps->b.top > 0
				&& ps->b.data[ps->b.top] < chunk_start + chunk_size / 2)
				rb(ps);
			pushed++;
		}
		chunk_start += chunk_size;
	}
}

static void	bring_max_to_top_b(t_ps *ps)
{
	int	max_pos;
	int	dist_rb;
	int	dist_rrb;

	max_pos = find_max_pos(&ps->b);
	dist_rb = ps->b.top - max_pos;
	dist_rrb = max_pos + 1;
	if (dist_rb <= dist_rrb)
	{
		while (dist_rb-- > 0)
			rb(ps);
	}
	else
	{
		while (dist_rrb-- > 0)
			rrb(ps);
	}
}

void	sort_medium(t_ps *ps)
{
	int	n;
	int	chunk_size;

	n = stack_size(&ps->a);
	chunk_size = get_chunk_size(n);
	push_chunks_to_b(ps, chunk_size, n);
	while (stack_size(&ps->b) > 0)
	{
		bring_max_to_top_b(ps);
		pa(ps);
	}
}

