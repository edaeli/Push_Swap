#include "push_swap.h"

/*
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
}*/

double compute_disorder(t_node *stack)
{
    long mistakes = 0;
    long total_pairs = 0;
    t_node *i_node;
    t_node *j_node;

    if (!stack || !stack->next)
        return (0.0);

    i_node = stack;
    while (i_node)
    {
        j_node = i_node->next;
        while (j_node)
        {
            total_pairs++;
            if (i_node->index > j_node->index)
                mistakes++;
            j_node = j_node->next;
        }
        i_node = i_node->next;
    }
    return ((double)mistakes / total_pairs);
}