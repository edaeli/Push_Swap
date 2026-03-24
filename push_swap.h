/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taslanya <taslanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:18:01 by taslanya          #+#    #+#             */
/*   Updated: 2026/03/24 14:26:32 by taslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/*
** ===================== STRUCTS =====================
*/

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stats
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_stats;

/*
** ===================== STACK UTILS =====================
*/

t_node	*new_node(int value);
void	add_back(t_node **stack, t_node *new_node);
int		stack_size(t_node *stack);
void	free_stack(t_node **stack);
int		is_sorted(t_node *stack);

/*
** ===================== OPERATIONS =====================
*/

void	swap(t_node **stack);
void	push(t_node **src, t_node **dst);
void	rotate(t_node **stack);
void	rev_rotate(t_node **stack);

/*
** ===================== COMMANDS =====================
*/

void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

/*
** ===================== INDEX / METRICS =====================
*/

void	index_stack(t_node *stack);
double	compute_disorder(t_node *a);

/*
** ===================== SORTING =====================
*/

/* simple */
void	simple_sort(t_node **a, t_node **b);
void	sort_3(t_node **a);
void	sort_5(t_node **a, t_node **b);

/* medium */
void	chunk_sort(t_node **a, t_node **b);

/* complex */
void	radix_sort(t_node **a, t_node **b);

/* adaptive */
void	greedy_sort(t_node **a, t_node **b);

/*
** ===================== SEARCH =====================
*/

int	find_max_pos(t_node *stack);
int	find_min_pos(t_node *stack);

/*
** ===================== PARSING =====================
*/

t_node	*parse_args(int argc, char **argv);
int		ft_atoi_safe(char *str, int *error);
int		is_number(char *str);
int		has_duplicates(t_node *stack, int value);
void	error_exit(void);

/*
** ===================== LIB =====================
*/

char	**ft_split(char const *s, char delim);
void	free_split(char **arr);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
void	ft_putnbr_fd(int n, int fd);

/*
** ===================== BONUS =====================
*/

void	count_op(char *op, int mode);

#endif
