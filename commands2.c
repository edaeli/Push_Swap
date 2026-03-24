/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taslanya <taslanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:28:22 by username          #+#    #+#             */
/*   Updated: 2026/03/24 14:28:40 by taslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
	count_op("ra", 1);
}

void	rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
	count_op("rb", 1);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	count_op("rr", 1);
}
