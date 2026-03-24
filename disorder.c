/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taslanya <taslanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:29:40 by username          #+#    #+#             */
/*   Updated: 2026/03/24 14:29:48 by taslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_node *stack)
{
	long	mistakes;
	long	total_pairs;
	t_node	*i_node;
	t_node	*j_node;

	mistakes = 0;
	total_pairs = 0;
	if (!stack || !stack->next)
		return (0.0);
	i_node = stack;
	while (i_node)
	{
		j_node = i_node->next;
		while (j_node)
		{
			total_pairs++;
			if (i_node->index > j_node->index)
				mistakes++;
			j_node = j_node->next;
		}
		i_node = i_node->next;
	}
	return ((double) mistakes / total_pairs);
}
