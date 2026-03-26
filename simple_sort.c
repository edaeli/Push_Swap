/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taslanya <taslanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 20:39:16 by taslanya          #+#    #+#             */
/*   Updated: 2026/03/26 18:24:38 by khoayvaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_min_pos(t_node *stack)
{
	int	min_idx;
	int	pos;
	int	i;

	min_idx = stack->index;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->index < min_idx)
		{
			min_idx = stack->index;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

int	find_max_pos(t_node *stack)
{
	int	max_idx;
	int	pos;
	int	i;

	max_idx = stack->index;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->index > max_idx)
		{
			max_idx = stack->index;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

void	simple_sort(t_node **a, t_node **b)
{
	int	pos;
	int	size;

	while (stack_size(*a) > 3 && !is_sorted(*a))
	{
		size = stack_size(*a);
		pos = find_min_pos(*a);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				ra(a);
		}
		else
		{
			pos = size - pos;
			while (pos-- > 0)
				rra(a);
		}
		pb(a, b);
	}
	sort_3(a);
	while (*b)
		pa(a, b);
}
