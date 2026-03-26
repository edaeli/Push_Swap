/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taslanya <taslanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:30:38 by username          #+#    #+#             */
/*   Updated: 2026/03/26 17:43:38 by khoayvaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_names(char *names[11])
{
	names[0] = "sa";
	names[1] = "sb";
	names[2] = "ss";
	names[3] = "pa";
	names[4] = "pb";
	names[5] = "ra";
	names[6] = "rb";
	names[7] = "rr";
	names[8] = "rra";
	names[9] = "rrb";
	names[10] = "rrr";
}

static void	print_bench(int total, int ops[11], char *names[11])
{
	int	i;

	write(2, "[bench] Total operations: ", 26);
	ft_putnbr_fd(total, 2);
	write(2, "\n", 1);
	i = 0;
	while (i < 11)
	{
		if (ops[i] > 0)
		{
			write(2, "[bench] ", 8);
			write(2, names[i], ft_strlen(names[i]));
			write(2, ": ", 2);
			ft_putnbr_fd(ops[i], 2);
			write(2, "\n", 1);
		}
		i++;
	}
}

void	count_op(char *op, int mode)
{
	static int	ops[11] = {0};
	static int	total = 0;
	char		*names[11];
	int			i;

	init_names(names);
	if (mode == 1)
	{
		total++;
		i = 0;
		while (i < 11)
		{
			if (ft_strcmp(op, names[i]) == 0)
				ops[i]++;
			i++;
		}
	}
	else if (mode == 2)
		print_bench(total, ops, names);
}
