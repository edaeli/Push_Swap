#include "push_swap.h"

void radix_sort(t_node **a, t_node **b)
{
    int size;
    int max_bits;
    int i;
    int j;

    size = stack_size(*a);
    max_bits = 0;
    // Находим сколько бит нужно для максимального индекса
    while (((size - 1) >> max_bits) != 0)
        max_bits++;
    
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            // Если i-тый бит индекса равен 1, оставляем в A
            if ((((*a)->index >> i) & 1) == 1)
                ra(a);
            else
                pb(a, b); // Если 0 - кидаем в B
            j++;
        }
        // Возвращаем всё из B в A для следующего бита
        while (*b)
            pa(a, b);
        i++;
        // Если стек уже отсортирован, можно выйти раньше
        if (is_sorted(*a))
            break;
    }
}