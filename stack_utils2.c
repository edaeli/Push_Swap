/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taslanya <taslanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 20:55:24 by taslanya          #+#    #+#             */
/*   Updated: 2026/03/24 20:55:44 by taslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}
static void	print_op(char *name, int count)
{
	write(2, "[bench] ", 8);
	write(2, name, ft_strlen(name));
	write(2, ": ", 2);
	ft_putnbr_fd(count, 2);
	write(2, "\n", 1);
}

void	count_op(char *op, int mode)
{
	static int	total = 0;
	static int	sa = 0;
	static int	sb = 0;
	static int	ss = 0;
	static int	pa = 0;
	static int	pb = 0;
	static int	ra = 0;
	static int	rb = 0;
	static int	rr = 0;
	static int	rra = 0;
	static int	rrb = 0;
	static int	rrr = 0;

	if (mode == 1)
	{
		total++;
		if (!op)
			return ;
		if (ft_strcmp(op, "sa") == 0)
			sa++;
		else if (ft_strcmp(op, "sb") == 0)
			sb++;
		else if (ft_strcmp(op, "ss") == 0)
			ss++;
		else if (ft_strcmp(op, "pa") == 0)
			pa++;
		else if (ft_strcmp(op, "pb") == 0)
			pb++;
		else if (ft_strcmp(op, "ra") == 0)
			ra++;
		else if (ft_strcmp(op, "rb") == 0)
			rb++;
		else if (ft_strcmp(op, "rr") == 0)
			rr++;
		else if (ft_strcmp(op, "rra") == 0)
			rra++;
		else if (ft_strcmp(op, "rrb") == 0)
			rrb++;
		else if (ft_strcmp(op, "rrr") == 0)
			rrr++;
	}
	else if (mode == 2)
	{
		write(2, "[bench] Total operations: ", 26);
		ft_putnbr_fd(total, 2);
		write(2, "\n", 1);
		if (sa != 0)
			print_op("sa", sa);
		if (sb != 0)
			print_op("sb", sb);
		if (ss != 0)
			print_op("ss", ss);
		if (pa != 0)
			print_op("pa", pa);
		if (pb != 0)
			print_op("pb", pb);
		if (ra != 0)
			print_op("ra", ra);
		if (rb != 0)
			print_op("rb", rb);
		if (rr != 0)
			print_op("rr", rr);
		if (rra != 0)
			print_op("rra", rra);
		if (rrb != 0)
			print_op("rrb", rrb);
		if (rrr != 0)
			print_op("rrr", rrr);
	}
}
