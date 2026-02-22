#include "push_swap.h"

void sa(t_node **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void sb(t_node **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void ss(t_node **a, t_node **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}

void pa(t_node **a, t_node **b)
{
    push(b, a);
    write(1, "pa\n", 3);
}

void pb(t_node **a, t_node **b)
{
    push(a, b);
    write(1, "pb\n", 3);
}

void ra(t_node **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void rb(t_node **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void rr(t_node **a, t_node **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}