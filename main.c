/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taslanya <taslanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 20:06:14 by taslanya          #+#    #+#             */
/*   Updated: 2026/03/26 18:27:38 by khoayvaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_bench(double disorder, char *strat, char *complexity)
{
	write(2, "\n[bench] Disorder: ", 19);
	ft_putnbr_fd((int)(disorder * 100), 2);
	write(2, "%\n", 2);
	write(2, "[bench] Strategy: ", 18);
	write(2, strat, ft_strlen(strat));
	write(2, "\n[bench] Complexity: ", 21);
	write(2, complexity, ft_strlen(complexity));
	write(2, "\n", 1);
}

static void	get_bench_info(char *mode, double d, int size)
{
	if (size <= 5)
		print_bench(d, "Small Sort", "O(1)");
	else if (ft_strcmp(mode, "--simple") == 0 || (ft_strcmp(mode,
				"--adaptive") == 0 && d < 0.2))
		print_bench(d, "Simple Sort", "O(n2)");
	else if (ft_strcmp(mode, "--medium") == 0 || (ft_strcmp(mode,
				"--adaptive") == 0 && d < 0.5))
		print_bench(d, "Chunk Sort", "O(n*sqrt(n))");
	else
		print_bench(d, "Radix Sort", "O(n log n)");
	count_op(NULL, 2);
}

static void	apply_sort(t_node **a, t_node **b, char *mode, double d)
{
	int	size;

	size = stack_size(*a);
	if (size == 2 && (*a)->index > (*a)->next->index)
		sa(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 5)
		sort_5(a, b);
	else if (ft_strcmp(mode, "--simple") == 0)
		simple_sort(a, b);
	else if (ft_strcmp(mode, "--medium") == 0)
		chunk_sort(a, b);
	else if (ft_strcmp(mode, "--complex") == 0)
		radix_sort(a, b);
	else
	{
		if (d < 0.2)
			simple_sort(a, b);
		else if (d < 0.5)
			chunk_sort(a, b);
		else
			radix_sort(a, b);
	}
}

static int	parse_flags(int argc, char **argv, char **mode, int *bench)
{
	int	i;

	i = 1;
	*mode = "--adaptive";
	*bench = 0;
	while (i < argc && argv[i][0] == '-')
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			*bench = 1;
		else
			*mode = argv[i];
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	t_node	*stk[2];
	char	*mode;
	int		bench;
	int		idx;
	double	init_d;

	idx = parse_flags(argc, argv, &mode, &bench);
	if (idx >= argc)
		return (0);
	stk[0] = parse_args(argc - idx + 1, &argv[idx - 1]);
	index_stack(stk[0]);
	if (is_sorted(stk[0]))
	{
		free_stack(&stk[0]);
		return (0);
	}
	init_d = compute_disorder(stk[0]);
	stk[1] = NULL;
	apply_sort(&stk[0], &stk[1], mode, init_d);
	if (bench)
		get_bench_info(mode, init_d, stack_size(stk[0]));
	free_stack(&stk[0]);
	free_stack(&stk[1]);
	return (0);
}
