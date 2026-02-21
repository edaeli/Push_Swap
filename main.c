#include "push_swap.h"
#include <stdio.h>

void print_stack(t_node *stack)
{
    while (stack)
    {
        printf("value=%d index=%d\n", stack->value, stack->index);
        stack = stack->next;
    }
}

int main(void)
{
    t_node *a = NULL;

    add_back(&a, new_node(50));
    add_back(&a, new_node(10));
    add_back(&a, new_node(30));
    add_back(&a, new_node(20));

    index_stack(a);

    print_stack(a);

    free_stack(&a);
}
