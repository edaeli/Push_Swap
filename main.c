/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taslanya <taslanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 20:06:14 by taslanya          #+#    #+#             */
/*   Updated: 2026/03/26 18:18:16 by khoayvaz         ###   ########.fr       */
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

void	run_adaptive(t_node **a, t_node **b, double d)
{
if (d < 0.2)
simple_sort(a, b);
else if (d < 0.5)
chunk_sort(a, b);
else
radix_sort(a, b);
}

int	main(int argc, char **argv)
{
t_node	*a;
t_node	*b;
char	*mode;
int		bench;
int		i;
int		size;
double	disorder;
char	*s_name;
char	*c_class;

b = NULL;
mode = "--adaptive";
bench = 0;
i = 1;
if (argc < 2)
	return (0);
while (i < argc && argv[i][0] == '-')
{
	if (ft_strcmp(argv[i], "--bench") == 0)
		bench = 1;
	else if (ft_strcmp(argv[i], "--simple") == 0)
		mode = "--simple";
	else if (ft_strcmp(argv[i], "--medium") == 0)
		mode = "--medium";
	else if (ft_strcmp(argv[i], "--complex") == 0)
		mode = "--complex";
	else if (ft_strcmp(argv[i], "--adaptive") == 0)
		mode = "--adaptive";
	i++;
}
if (i >= argc)
	return (0);
a = parse_args(argc - i + 1, &argv[i - 1]);
index_stack(a);
disorder = compute_disorder(a);
size = stack_size(a);
if (is_sorted(a))
{
	free_stack(&a);
	return (0);
}
if (size == 2)
	sa(&a);
else if (size == 3)
	sort_3(&a);
else if (size == 5)
	sort_5(&a, &b);
else if (ft_strcmp(mode, "--simple") == 0)
	simple_sort(&a, &b);
else if (ft_strcmp(mode, "--medium") == 0)
	chunk_sort(&a, &b);
else if (ft_strcmp(mode, "--complex") == 0)
	radix_sort(&a, &b);
else
	run_adaptive(&a, &b, disorder);
if (bench)
{
	s_name = "Adaptive Selection";
	c_class = "Mixed";
	if (size <= 5)
	{
		s_name = "Small Sort";
		c_class = "O(1)";
	}
	else if (ft_strcmp(mode, "--simple") == 0)
	{
		s_name = "Simple Sort";
		c_class = "O(n2)";
	}
	else if (ft_strcmp(mode, "--medium") == 0)
	{
		s_name = "Chunk Sort";
		c_class = "O(n*sqrt(n))";
	}
	else if (ft_strcmp(mode, "--complex") == 0)
	{
		s_name = "Radix Sort";
		c_class = "O(n log n)";
	}
	else if (disorder < 0.2)
	{
		s_name = "Simple (Adaptive)";
		c_class = "O(n2)";
	}
	else if (disorder < 0.5)
	{
		s_name = "Chunk (Adaptive)";
		c_class = "O(n*sqrt(n))";
	}
	else
	{
		s_name = "Radix (Adaptive)";
		c_class = "O(n log n)";
	}
	print_bench(disorder, s_name, c_class);
	count_op(NULL, 2);
}
free_stack(&a);
free_stack(&b);
return (0);

}
