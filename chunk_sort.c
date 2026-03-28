/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taslanya <taslanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 20:03:02 by taslanya          #+#    #+#             */
/*   Updated: 2026/03/26 17:39:00 by khoayvaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks_medium(t_node **a, t_node **b, int chunk)
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

void	push_back_to_a(t_node **a, t_node **b)
{
	int	max_pos;
	int	size;

	while (*b)
	{
		size = stack_size(*b);
		max_pos = find_max_pos(*b);
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(b);
		}
		else
		{
			max_pos = size - max_pos;
			while (max_pos-- > 0)
				rrb(b);
		}
		pa(a, b);
	}
}

void	chunk_sort(t_node **a, t_node **b)
{
	int	size;
	int	chunk;

	size = stack_size(*a);
	chunk = 25;
	if (size > 100)
		chunk = 60;
	push_chunks_medium(a, b, chunk);
	push_back_to_a(a, b);
}
