#include "push_swap.h"

int find_min_pos(t_node *stack)
{
    int min_index = stack->index;
    int pos = 0;
    int i = 0;

    while (stack)
    {
        if (stack->index < min_index)
        {
            min_index = stack->index;
            pos = i;
        }
        stack = stack->next;
        i++;
    }
    return pos;
}

void simple_sort(t_node **a, t_node **b)
{
    int min_pos;

    while (!is_sorted(*a))
    {
        min_pos = find_min_pos(*a);

        // если минимальный элемент ближе к верху — ra, иначе rra
        if (min_pos <= stack_size(*a) / 2)
        {
            while (min_pos-- > 0)
                ra(a);
        }
        else
        {
            min_pos = stack_size(*a) - min_pos;
            while (min_pos-- > 0)
                rra(a);
        }
        pb(a, b);
    }
    while (*b)
        pa(a, b);
}
