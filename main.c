#include <stdio.h>
#include "push_swap.h"

void print_stack(t_node *stack)
{
    while (stack)
    {
        printf("value=%d  index=%d\n", stack->value, stack->index);
        stack = stack->next;
    }
}


int main(void)
{
    t_node *a = NULL;
    t_node *b = NULL;

    add_back(&a, new_node(42));
    add_back(&a, new_node(5));
    add_back(&a, new_node(100));
    add_back(&a, new_node(1));
    add_back(&a, new_node(50));

    index_stack(a);

    printf("Before simple_sort:\n");
    print_stack(a);

    simple_sort(&a, &b);

    printf("\nAfter simple_sort:\n");
    print_stack(a);

    free_stack(&a);
    return 0;
}
