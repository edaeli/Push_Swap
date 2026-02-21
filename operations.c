#include "push_swap.h"

void    swap(t_node **stack)
{
    t_node  *first;
    t_node  *second;

    if(!*stack || !(*stack)->next)
        return ;
    first = *stack;
    second = (*stack)->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}

void    push(t_node **src, t_node   **dst)
{
    t_node  *tmp;
    if(!src)
        return ;
    tmp = *src;
    *src = (*src)->next;
    tmp->next = *dst;
    *dst = tmp;
}

void    rotate(t_node   **stack)
{
    t_node  *first;
    t_node  *last;

    if (!*stack || !(*stack)->next)
        return ;
    first = *stack;
    last = *stack;
    while (last->next)
        last = last->next;
    *stack = first->next;
    first->next = NULL;
    last->next = first; 
}

