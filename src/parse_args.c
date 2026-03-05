#include "push_swap.h"

static int	is_valid_number(const char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '-' || *str == '+')
	{
		str++;
		if (!*str)
			return (0);
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	count_words(char **argv, int argc)
{
	int		total;
	int		i;
	char	**split;
	int		j;

	total = 0;
	i = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (-1);
		j = 0;
		while (split[j])
			free(split[j++]);
		total += j;
		free(split);
		i++;
	}
	return (total);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static int	fill_stack(char **argv, int argc, t_ps *ps)
{
	int		idx;
	int		i;
	char	**split;
	int		j;
	long	val;

	idx = ps->a.top;
	i = -1;
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			error_exit(ps);
		j = 0;
		while (split[j])
		{
			if (!is_valid_number(split[j]))
				return (free_split(split), 0);
			val = ft_long_atoi(split[j]);
			if (val > INT_MAX || val < INT_MIN)
				return (free_split(split), 0);
			ps->a.data[idx--] = (int)val;
			free(split[j++]);
		}
		free(split);
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_ps *ps)
{
	int	total;

	total = count_words(argv, argc);
	if (total <= 0)
		return (0);
	stack_init(ps, total);
	ps->a.top = total - 1;
	if (!fill_stack(argv, argc, ps))
		return (0);
	if (has_duplicates(ps->a.data, total))
		return (0);
	ps->size = total;
	return (1);
}
