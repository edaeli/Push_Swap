#include "push_swap.h"

void push_chunks(t_node **a, t_node **b, int chunk_size)
{
    int i = 0;
    //int size = stack_size(*a);

    while (*a)
    {
        if ((*a)->index <= i)
        {
            pb(a, b);
            rb(b);
            i++;
        }
        else if ((*a)->index <= i + chunk_size)
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

void push_back_quick(t_node **a, t_node **b)
{
    int max_pos;

    while (*b)
    {
        max_pos = find_max_pos(*b);
        if (max_pos <= stack_size(*b) / 2)
            while (max_pos-- > 0)
                rb(b);
        else
        {
            max_pos = stack_size(*b) - max_pos;
            while (max_pos-- > 0)
                rrb(b);
        }
        pa(a, b);
    }
}

void quick_sort(t_node **a, t_node **b)
{
    int size = stack_size(*a);
    int chunk;

    if (size <= 100)
        chunk = 20;
    else
        chunk = 45; 

    push_chunks(a, b, chunk);
    push_back_quick(a, b);

    final_rotate(a); 
}
