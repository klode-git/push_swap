#include "push_swap.h"

static void	init_ps(t_ps *ps)
{
	ps->a.data = NULL;
	ps->b.data = NULL;
	ps->a.top = -1;
	ps->b.top = -1;
	ps->a.capacity = 0;
	ps->b.capacity = 0;
	ps->strategy = STRATEGY_ADAPTIVE;
	ps->bench = 0;
	ps->size = 0;
	ft_bzero(&ps->ops, sizeof(t_ops));
}

static void	dispatch_sort(t_ps *ps)
{
	if (ps->strategy == STRATEGY_SIMPLE)
		sort_simple(ps);
	else if (ps->strategy == STRATEGY_MEDIUM)
		sort_medium(ps);
	else if (ps->strategy == STRATEGY_COMPLEX)
		sort_complex(ps);
	else
		sort_adaptive(ps);
}

static void	do_sort(t_ps *ps)
{
	double	disorder;
	int		size;

	size = stack_size(&ps->a);
	disorder = compute_disorder(&ps->a);
	normalize_indices(ps);
	if (size == 1 || is_sorted(&ps->a))
	{
		if (ps->bench)
			print_bench(ps, disorder);
		return ;
	}
	if (size == 2)
		sort_two(ps);
	else if (size == 3)
		sort_three(ps);
	else
		dispatch_sort(ps);
	if (ps->bench)
		print_bench(ps, disorder);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	init_ps(&ps);
	argc--;
	argv++;
	if (argc == 0)
		return (0);
	if (parse_flags(&argc, &argv, &ps) < 0)
		error_exit(&ps);
	if (argc == 0)
		return (0);
	if (!parse_args(argc, argv, &ps))
		error_exit(&ps);
	do_sort(&ps);
	free_ps(&ps);
	return (0);
}
