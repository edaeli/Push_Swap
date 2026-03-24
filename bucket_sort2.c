/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taslanya <taslanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 20:06:29 by taslanya          #+#    #+#             */
/*   Updated: 2026/03/24 20:57:40 by taslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks_greedy(t_node **a, t_node **b, int chunk)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			if (*a && (*a)->index > i + chunk)
				rb(b);
			i++;
		}
		else if ((*a)->index <= i + chunk)
		{
			pb(a, b);
			i++;
		}
		else
		{
			if (*b && (*b)->index < i)
				rr(a, b);
			else
				ra(a);
		}
	}
}

int	get_target_pos(t_node *a, int index)
{
	t_node	*tmp;
	int		pos;
	int		best_pos;
	int		min_diff;
	int		diff;

	tmp = a;
	pos = 0;
	best_pos = 0;
	min_diff = INT_MAX;
	while (tmp)
	{
		diff = tmp->index - index;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			best_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	if (min_diff != INT_MAX)
		return (best_pos);
	tmp = a;
	pos = 0;
	min_diff = INT_MAX;
	while (tmp)
	{
		if (tmp->index < min_diff)
		{
			min_diff = tmp->index;
			best_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (best_pos);
}

int	get_pos(t_node *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

void	get_cost(t_node *a, t_node *b, int *cost_a,
		int *cost_b, int index)
{
	int	size_a;
	int	size_b;
	int	pos_a;
	int	pos_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	pos_b = get_pos(b, index);
	pos_a = get_target_pos(a, index);
	if (pos_b <= size_b / 2)
		*cost_b = pos_b;
	else
		*cost_b = pos_b - size_b;
	if (pos_a <= size_a / 2)
		*cost_a = pos_a;
	else
		*cost_a = pos_a - size_a;
}

void	do_rotate(t_node **a, t_node **b,
		int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}
