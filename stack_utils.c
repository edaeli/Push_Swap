#include "push_swap.h"

t_node *new_node(int value)
{
    t_node *node;

    node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->value = value;
    node->index = -1;
    node->next = NULL;
    return (node);
}

void add_back(t_node **stack, t_node *new)
{
	t_node *tmp;

    if (!*stack)
    {
        *stack = new;
        return ;
    }
    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

int stack_size(t_node *stack)
{
    int size;

    size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}

void free_stack(t_node **stack)
{
    t_node *tmp;

    while (*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
}
