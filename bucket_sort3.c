/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taslanya <taslanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 20:57:44 by taslanya          #+#    #+#             */
/*   Updated: 2026/03/24 20:57:59 by taslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_rotate_a(t_node **a, int cost_a)
{
	while (cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
}

void	finish_rotate_b(t_node **b, int cost_b)
{
	while (cost_b > 0)
	{
		rb(b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b);
		cost_b++;
	}
}

int	get_cheapest(t_node *a, t_node *b)
{
	t_node	*tmp;
	int		best_index;
	int		best_cost;
	int		cost_a;
	int		cost_b;
	int		total;

	tmp = b;
	best_index = tmp->index;
	best_cost = INT_MAX;
	while (tmp)
	{
		get_cost(a, b, &cost_a, &cost_b, tmp->index);
		total = cost_a;
		if (total < 0)
			total = -total;
		if (cost_b < 0)
			total += -cost_b;
		else
			total += cost_b;
		if (total < best_cost)
		{
			best_cost = total;
			best_index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (best_index);
}

void	greedy_push_back(t_node **a, t_node **b)
{
	int	index;
	int	cost_a;
	int	cost_b;

	while (*b)
	{
		index = get_cheapest(*a, *b);
		get_cost(*a, *b, &cost_a, &cost_b, index);
		do_rotate(a, b, &cost_a, &cost_b);
		finish_rotate_a(a, cost_a);
		finish_rotate_b(b, cost_b);
		pa(a, b);
	}
}

void	greedy_sort(t_node **a, t_node **b)
{
	int	size;
	int	chunk;

	size = stack_size(*a);
	if (size <= 100)
		chunk = 25;
	else
		chunk = 60;
	push_chunks_greedy(a, b, chunk);
	greedy_push_back(a, b);
}
