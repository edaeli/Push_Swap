/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taslanya <taslanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 20:35:49 by taslanya          #+#    #+#             */
/*   Updated: 2026/03/24 20:35:50 by taslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks(t_node **a, t_node **b, int chunk_size)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
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

void	push_back_quick(t_node **a, t_node **b)
{
	int	max_pos;
	int	size;

	while (*b)
	{
		size = stack_size(*b);
		max_pos = find_max_pos(*b);
		if (max_pos <= size / 2)
		{
			while (max_pos > 0)
			{
				rb(b);
				max_pos--;
			}
		}
		else
		{
			max_pos = size - max_pos;
			while (max_pos > 0)
			{
				rrb(b);
				max_pos--;
			}
		}
		pa(a, b);
	}
}

void	quick_sort(t_node **a, t_node **b)
{
	int	size;
	int	chunk;

	size = stack_size(*a);
	if (size <= 100)
		chunk = 20;
	else
		chunk = 45;
	push_chunks(a, b, chunk);
	push_back_quick(a, b);
	final_rotate(a);
}
