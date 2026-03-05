/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: push_swap                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 00:00:00 by push_swap         #+#    #+#             */
/*   Updated: 2026/03/05 00:00:00 by push_swap        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

# define STRATEGY_ADAPTIVE 0
# define STRATEGY_SIMPLE   1
# define STRATEGY_MEDIUM   2
# define STRATEGY_COMPLEX  3

typedef struct s_stack
{
	int	*data;
	int	top;
	int	capacity;
}	t_stack;

typedef struct s_ops
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_ops;

typedef struct s_ps
{
	t_stack	a;
	t_stack	b;
	t_ops	ops;
	int		strategy;
	int		bench;
	int		size;
}	t_ps;

/* error.c */
void	error_exit(t_ps *ps);
void	free_ps(t_ps *ps);

/* utils.c */
long	ft_long_atoi(const char *str);

/* parse_flags.c */
int		parse_flags(int *argc, char ***argv, t_ps *ps);

/* parse_args.c */
int		parse_args(int argc, char **argv, t_ps *ps);

/* stack_init.c */
void	stack_init(t_ps *ps, int size);
void	normalize_indices(t_ps *ps);

/* stack operations */
void	sa(t_ps *ps);
void	sb(t_ps *ps);
void	ss(t_ps *ps);
void	pa(t_ps *ps);
void	pb(t_ps *ps);
void	ra(t_ps *ps);
void	rb(t_ps *ps);
void	rr(t_ps *ps);
void	rra(t_ps *ps);
void	rrb(t_ps *ps);
void	rrr(t_ps *ps);

/* disorder.c */
double	compute_disorder(t_stack *a);

/* sort_utils.c */
int		is_sorted(t_stack *a);
int		find_min_pos(t_stack *s);
int		find_max_pos(t_stack *s);
int		stack_size(t_stack *s);

/* sort_small.c */
void	sort_two(t_ps *ps);
void	sort_three(t_ps *ps);

/* sort_simple.c */
void	sort_simple(t_ps *ps);

/* sort_medium.c */
void	sort_medium(t_ps *ps);

/* sort_complex.c */
void	sort_complex(t_ps *ps);

/* sort_turkish.c */
void	sort_turkish(t_ps *ps);

/* sort_adaptive.c */
void	sort_adaptive(t_ps *ps);

/* bench.c */
void	print_bench(t_ps *ps, double disorder);

#endif
