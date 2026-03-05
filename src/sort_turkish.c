#include "push_swap.h"

static int	find_target_pos_b(t_stack *b, int val)
{
	int	best_pos;
	int	best_val;
	int	i;

	if (b->top < 0)
		return (0);
	best_pos = find_max_pos(b);
	best_val = -1;
	i = b->top;
	while (i >= 0)
	{
		if (b->data[i] > val && (best_val == -1 || b->data[i] < best_val))
		{
			best_val = b->data[i];
			best_pos = i;
		}
		i--;
	}
	return (best_pos);
}

static int	cost_dir(int pos, int top)
{
	int	forward;
	int	backward;

	forward = top - pos;
	backward = pos + 1;
	if (forward <= backward)
		return (forward);
	return (-backward);
}

static int	abs_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	combined_cost(int cost_a, int cost_b)
{
	if (cost_a >= 0 && cost_b >= 0)
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	if (cost_a < 0 && cost_b < 0)
	{
		if (-cost_a > -cost_b)
			return (-cost_a);
		return (-cost_b);
	}
	return (abs_val(cost_a) + abs_val(cost_b));
}

static void	find_cheapest(t_ps *ps, int *best_ia, int *best_ib)
{
	int	i;
	int	ca;
	int	cb;
	int	best_cost;

	best_cost = 2147483647;
	i = ps->a.top;
	while (i >= 0)
	{
		ca = cost_dir(i, ps->a.top);
		cb = cost_dir(find_target_pos_b(&ps->b, ps->a.data[i]), ps->b.top);
		if (combined_cost(ca, cb) < best_cost)
		{
			best_cost = combined_cost(ca, cb);
			*best_ia = i;
			*best_ib = find_target_pos_b(&ps->b, ps->a.data[i]);
		}
		i--;
	}
}

static void	exec_both(t_ps *ps, int *ca, int *cb)
{
	while (*ca > 0 && *cb > 0)
	{
		rr(ps);
		(*ca)--;
		(*cb)--;
	}
	while (*ca < 0 && *cb < 0)
	{
		rrr(ps);
		(*ca)++;
		(*cb)++;
	}
}

static void	exec_remaining(t_ps *ps, int ca, int cb)
{
	while (ca > 0)
	{
		ra(ps);
		ca--;
	}
	while (ca < 0)
	{
		rra(ps);
		ca++;
	}
	while (cb > 0)
	{
		rb(ps);
		cb--;
	}
	while (cb < 0)
	{
		rrb(ps);
		cb++;
	}
}

static int	find_target_pos_a(t_stack *a, int val)
{
	int	best_pos;
	int	best_val;
	int	i;

	best_pos = find_min_pos(a);
	best_val = -1;
	i = a->top;
	while (i >= 0)
	{
		if (a->data[i] < val && (best_val == -1 || a->data[i] > best_val))
		{
			best_val = a->data[i];
			best_pos = i;
		}
		i--;
	}
	return (best_pos);
}

static void	rotate_a_for_insert(t_ps *ps, int pos)
{
	int	d;

	d = cost_dir(pos, ps->a.top);
	while (d > 0)
	{
		ra(ps);
		d--;
	}
	while (d < 0)
	{
		rra(ps);
		d++;
	}
}

static void	push_back_to_a(t_ps *ps)
{
	int	max_pos;
	int	d;
	int	pos;

	max_pos = find_max_pos(&ps->b);
	d = cost_dir(max_pos, ps->b.top);
	while (d > 0)
	{
		rb(ps);
		d--;
	}
	while (d < 0)
	{
		rrb(ps);
		d++;
	}
	while (stack_size(&ps->b) > 0)
	{
		pos = find_target_pos_a(&ps->a, ps->b.data[ps->b.top]);
		rotate_a_for_insert(ps, pos);
		pa(ps);
	}
	pos = find_min_pos(&ps->a);
	d = cost_dir(pos, ps->a.top);
	while (d > 0)
	{
		ra(ps);
		d--;
	}
	while (d < 0)
	{
		rra(ps);
		d++;
	}
}

void	sort_turkish(t_ps *ps)
{
	int	ia;
	int	ib;
	int	ca;
	int	cb;

	pb(ps);
	pb(ps);
	while (stack_size(&ps->a) > 3)
	{
		find_cheapest(ps, &ia, &ib);
		ca = cost_dir(ia, ps->a.top);
		cb = cost_dir(ib, ps->b.top);
		exec_both(ps, &ca, &cb);
		exec_remaining(ps, ca, cb);
		pb(ps);
	}
	sort_three(ps);
	push_back_to_a(ps);
}
