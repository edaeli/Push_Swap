/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taslanya <taslanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 20:39:16 by taslanya          #+#    #+#             */
/*   Updated: 2026/03/24 20:40:18 by taslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_node *stack)
{
	int	min_index;
	int	pos;
	int	i;

	min_index = stack->index;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

int	find_max_pos(t_node *stack)
{
	int	max_index;
	int	pos;
	int	i;

	max_index = stack->index;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

void	simple_sort(t_node **a, t_node **b)
{
	int	min_pos;
	int	size;

	while (!is_sorted(*a))
	{
		size = stack_size(*a);
		min_pos = find_min_pos(*a);
		if (min_pos <= size / 2)
		{
			while (min_pos > 0)
			{
				ra(a);
				min_pos--;
			}
		}
		else
		{
			min_pos = size - min_pos;
			while (min_pos > 0)
			{
				rra(a);
				min_pos--;
			}
		}
		pb(a, b);
	}
	while (*b)
		pa(a, b);
}
