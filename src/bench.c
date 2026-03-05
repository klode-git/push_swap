#include "push_swap.h"

static void	print_strategy_name(int strategy, int fd)
{
	if (strategy == STRATEGY_SIMPLE)
		ft_putstr_fd("Selection Sort / O(n^2)", fd);
	else if (strategy == STRATEGY_MEDIUM)
		ft_putstr_fd("Chunk Sort / O(n*sqrt(n))", fd);
	else if (strategy == STRATEGY_COMPLEX)
		ft_putstr_fd("Radix Sort / O(n*log(n))", fd);
	else
		ft_putstr_fd("Adaptive", fd);
}

static void	print_disorder(double disorder, int fd)
{
	int	pct_int;
	int	pct_dec;

	pct_int = (int)(disorder * 100);
	pct_dec = (int)(disorder * 10000) % 100;
	ft_putstr_fd("[bench] disorder: ", fd);
	ft_putnbr_fd(pct_int, fd);
	ft_putchar_fd('.', fd);
	if (pct_dec < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(pct_dec, fd);
	ft_putendl_fd("%", fd);
}

static void	print_op_line1(t_ops *ops, int fd)
{
	ft_putstr_fd("[bench] sa: ", fd);
	ft_putnbr_fd(ops->sa, fd);
	ft_putstr_fd(" sb: ", fd);
	ft_putnbr_fd(ops->sb, fd);
	ft_putstr_fd(" ss: ", fd);
	ft_putnbr_fd(ops->ss, fd);
	ft_putstr_fd(" pa: ", fd);
	ft_putnbr_fd(ops->pa, fd);
	ft_putstr_fd(" pb: ", fd);
	ft_putnbr_fd(ops->pb, fd);
	ft_putchar_fd('\n', fd);
}

static void	print_op_line2(t_ops *ops, int fd)
{
	ft_putstr_fd("[bench] ra: ", fd);
	ft_putnbr_fd(ops->ra, fd);
	ft_putstr_fd(" rb: ", fd);
	ft_putnbr_fd(ops->rb, fd);
	ft_putstr_fd(" rr: ", fd);
	ft_putnbr_fd(ops->rr, fd);
	ft_putstr_fd(" rra: ", fd);
	ft_putnbr_fd(ops->rra, fd);
	ft_putstr_fd(" rrb: ", fd);
	ft_putnbr_fd(ops->rrb, fd);
	ft_putstr_fd(" rrr: ", fd);
	ft_putnbr_fd(ops->rrr, fd);
	ft_putchar_fd('\n', fd);
}

void	print_bench(t_ps *ps, double disorder)
{
	print_disorder(disorder, 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	print_strategy_name(ps->strategy, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(ps->ops.total, 2);
	ft_putchar_fd('\n', 2);
	print_op_line1(&ps->ops, 2);
	print_op_line2(&ps->ops, 2);
}
