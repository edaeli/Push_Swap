/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taslanya <taslanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:18:01 by taslanya          #+#    #+#             */
/*   Updated: 2026/03/26 18:09:13 by khoayvaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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

t_node	*new_node(int value);
void	add_back(t_node **stack, t_node *new_n);
int		stack_size(t_node *stack);
void	free_stack(t_node **stack);
int		is_sorted(t_node *stack);

void	swap(t_node **stack);
void	push(t_node **src, t_node **dst);
void	rotate(t_node **stack);
void	rev_rotate(t_node **stack);

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

void	index_stack(t_node *stack);
double	compute_disorder(t_node *a);

void	simple_sort(t_node **a, t_node **b);
void	sort_3(t_node **a);
void	sort_5(t_node **a, t_node **b);
void	chunk_sort(t_node **a, t_node **b);
void	radix_sort(t_node **a, t_node **b);
void	greedy_sort(t_node **a, t_node **b);

int		find_max_pos(t_node *stack);
int		find_min_pos(t_node *stack);

t_node	*parse_args(int argc, char **argv);
int		ft_atoi_safe(char *str, int *error);
int		is_number(char *str);
int		has_duplicates(t_node *stack, int value);
void	error_exit(void);

char	**ft_split(char const *s, char delim);
void	free_split(char **arr);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
void	ft_putnbr_fd(int n, int fd);

void	count_op(char *op, int mode);
void	get_cost(t_node *a, t_node *b, int costs[2], int index);
void	do_rotate(t_node **a, t_node **b, int *cost_a, int *cost_b);
void	push_chunks_greedy(t_node **a, t_node **b, int chunk);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		word_count(const char *s, char delim);
int		alloc_word(char **words, int pos, size_t len);

#endif
