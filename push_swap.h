#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
    int             value;
    int             index;
    struct s_node   *next;
}   t_node;

t_node  *new_node(int value);
void    add_back(t_node **stack, t_node *new);
int     stack_size(t_node *stack);
void    free_stack(t_node **stack);

void    swap(t_node **stack);
void    push(t_node **src, t_node **dst);
void    rotate(t_node **stack);
void rev_rotate(t_node **stack);

void    sa(t_node **a);
void    sb(t_node **b);
void    ss(t_node **a, t_node **b);

void    pa(t_node **a, t_node **b);
void    pb(t_node **a, t_node **b);

void    ra(t_node **a);
void    rb(t_node **b);
void    rr(t_node **a, t_node **b);

void rra(t_node **a);
void rrb(t_node **b);
void rrr(t_node **a, t_node **b);

int     *stack_to_array(t_node *stack);
void    sort_array(int *arr, int size);
void    assign_index(t_node *stack, int *arr, int size);
void    index_stack(t_node *stack);
int is_sorted(t_node *stack);

double  compute_disorder(t_node *a);

void simple_sort(t_node **a, t_node **b);


#endif
