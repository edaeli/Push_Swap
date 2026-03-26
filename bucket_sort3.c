/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taslanya <taslanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 20:57:44 by taslanya          #+#    #+#             */
/*   Updated: 2026/03/26 17:34:29 by khoayvaz         ###   ########.fr       */
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
	int		best_idx;
	int		best_cost;
	int		cost[2];

	tmp = b;
	best_idx = tmp->index;
	best_cost = INT_MAX;
	while (tmp)
	{
		get_cost(a, b, cost, tmp->index);
		if (cost[0] < 0)
			cost[0] = -cost[0];
		if (cost[1] < 0)
			cost[1] = -cost[1];
		if (cost[0] + cost[1] < best_cost)
		{
			best_cost = cost[0] + cost[1];
			best_idx = tmp->index;
		}
		tmp = tmp->next;
	}
	return (best_idx);
}

void	greedy_push_back(t_node **a, t_node **b)
{
	int	index;
	int	cost[2];

	while (*b)
	{
		index = get_cheapest(*a, *b);
		get_cost(*a, *b, cost, index);
		do_rotate(a, b, &cost[0], &cost[1]);
		finish_rotate_a(a, cost[0]);
		finish_rotate_b(b, cost[1]);
		pa(a, b);
	}
}

void	greedy_sort(t_node **a, t_node **b)
{
	int	size;
	int	chunk;

	size = stack_size(*a);
	chunk = 25;
	if (size > 100)
		chunk = 60;
	push_chunks_greedy(a, b, chunk);
	greedy_push_back(a, b);
}
