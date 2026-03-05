#include "push_swap.h"

static int	check_flag(const char *arg, t_ps *ps)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		ps->strategy = STRATEGY_SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		ps->strategy = STRATEGY_MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		ps->strategy = STRATEGY_COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		ps->strategy = STRATEGY_ADAPTIVE;
	else if (ft_strncmp(arg, "--bench", 8) == 0)
		ps->bench = 1;
	else
		return (0);
	return (1);
}

int	parse_flags(int *argc, char ***argv, t_ps *ps)
{
	int		consumed;

	consumed = 0;
	while (*argc > 0 && (*argv)[0][0] == '-' && (*argv)[0][1] == '-')
	{
		if (!check_flag((*argv)[0], ps))
			return (-1);
		(*argv)++;
		(*argc)--;
		consumed++;
	}
	return (consumed);
}
