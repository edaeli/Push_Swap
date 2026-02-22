#include "push_swap.h"

void rra(t_node **a)
{
    rev_rotate(a);
    write(1, "rra\n", 4);
}

void rrb(t_node **b)
{
    rev_rotate(b);
    write(1, "rrb\n", 4);
}

void rrr(t_node **a, t_node **b)
{
    rev_rotate(a);
    rev_rotate(b);
    write(1, "rrr\n", 4);
}
