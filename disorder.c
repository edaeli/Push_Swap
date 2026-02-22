#include "push_swap.h"
/*
int *stack_to_index_array(t_node *stack)
{
    int *arr;
    int size;
    int i;

    size = stack_size(stack);
    arr = malloc(sizeof(int) * size);
    if (!arr)
        return (NULL);
    i = 0;
    while (stack)
    {
        arr[i] = stack->index;
        stack = stack->next;
        i++;
    }
    return (arr);
}

double compute_disorder(t_node *a)
{
    int *arr;
    int size;
    int i;
    int j;
    int mistakes;
    int total;

    size = stack_size(a);
    if (size < 2)
        return (0.0);

    arr = stack_to_index_array(a);
    if (!arr)
        return (0.0);

    mistakes = 0;
    total = 0;

    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            total++;
            if (arr[i] > arr[j])
                mistakes++;
            j++;
        }
        i++;
    }
    free(arr);
    return ((double)mistakes / total);
}
*/

double compute_disorder(t_node *stack)
{
    int total;
    int mistakes;
    t_node *curr;

    total = 0;
    mistakes = 0;
    curr = stack;

    while (curr && curr->next)
    {
        total++;
        if (curr->index > curr->next->index)
            mistakes++;
        curr = curr->next;
    }

    if (total == 0)
        return (0.0);

    return ((double)mistakes / total);
}
