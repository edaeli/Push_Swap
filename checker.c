/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoayvaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:38:34 by khoayvaz          #+#    #+#             */
/*   Updated: 2026/03/28 12:38:38 by khoayvaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static void	free_all(t_node **a, t_node **b, char *line)
{
	if (line)
		free(line);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	execute_cmd_2(t_node **a, t_node **b, char *op)
{
	if (!ft_strcmp(op, "ra\n"))
		rotate(a);
	else if (!ft_strcmp(op, "rb\n"))
		rotate(b);
	else if (!ft_strcmp(op, "rr\n"))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strcmp(op, "rra\n"))
		rev_rotate(a);
	else if (!ft_strcmp(op, "rrb\n"))
		rev_rotate(b);
	else if (!ft_strcmp(op, "rrr\n"))
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	else
		free_all(a, b, op);
}

static void	execute_cmd(t_node **a, t_node **b, char *op)
{
	if (!ft_strcmp(op, "sa\n"))
		swap(a);
	else if (!ft_strcmp(op, "sb\n"))
		swap(b);
	else if (!ft_strcmp(op, "ss\n"))
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strcmp(op, "pa\n"))
		push(b, a);
	else if (!ft_strcmp(op, "pb\n"))
		push(a, b);
	else
		execute_cmd_2(a, b, op);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	*line;

	if (argc < 2)
		return (0);
	a = parse_args(argc, argv);
	if (!a)
		return (0);
	b = NULL;
	line = get_next_line(0);
	while (line)
	{
		execute_cmd(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
