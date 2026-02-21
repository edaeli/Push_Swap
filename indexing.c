#include "push_swap.h"

int *stack_to_array(t_node  *stack)
{
    int *arr;
    int     i;
    int     size;

    i = 0;
    size = stack_size(stack);
    arr = malloc(size * sizeof(int));
    if (!arr)
        return (NULL);
    while (stack)
    {
        arr[i] = stack->value;
        stack = stack->next;
        i++;
    }
    return (arr);
}

void    sort_array(int  *arr, int   size)
{
    int i;
    int j;
    int tmp;
    int flag;

    i = 0;
    while(i < size - 1)
    {
        j = 0;
        flag = 0;
        while (j < size - i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 1;
            }
            j++;
        }
        if (flag == 0)
            break;
        i++;
    }
}

void assign_index(t_node    *stack,int  *arr, int size)
{
    int i;

    while (stack)
    {
        i = 0;
        while (i < size)
        {
            if(arr[i] == stack->value)
            {
                stack->index = i;
                break ;
            }
            i++;
        }
        stack = stack->next;
    }
}

void    index_stack(t_node  *stack)
{
    int *arr;
    int size;

    arr = stack_to_array(stack);
    if (!arr)
        return ;
    size = stack_size(stack);
    sort_array(arr, size);
    assign_index(stack, arr, size);
    free(arr);
}