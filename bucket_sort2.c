#include "push_swap.h"

void push_chunks_greedy(t_node **a, t_node **b, int chunk)
{
    int i;

    i = 0;
    while (*a)
    {
        if ((*a)->index <= i)
        {
            pb(a, b);
            if (*a && (*a)->index > i + chunk)
                rb(b);
            i++;
        }
        else if ((*a)->index <= i + chunk)
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

int get_target_pos(t_node *a, int index)
{
    t_node *tmp;
    int pos;
    int best_pos;
    int min_diff;
    int diff;

    tmp = a;
    pos = 0;
    best_pos = 0;
    min_diff = 2147483647;

    while (tmp)
    {
        diff = tmp->index - index;
        if (diff > 0 && diff < min_diff)
        {
            min_diff = diff;
            best_pos = pos;
        }
        tmp = tmp->next;
        pos++;
    }

    if (min_diff != 2147483647)
        return (best_pos);

    // если элемент самый большой → вставить перед минимальным
    tmp = a;
    pos = 0;
    min_diff = 2147483647;

    while (tmp)
    {
        if (tmp->index < min_diff)
        {
            min_diff = tmp->index;
            best_pos = pos;
        }
        tmp = tmp->next;
        pos++;
    }
    return (best_pos);
}


int get_pos(t_node *stack, int index)
{
    int pos = 0;

    while (stack)
    {
        if (stack->index == index)
            return pos;
        stack = stack->next;
        pos++;
    }
    return (-1);
}

void get_cost(t_node *a, t_node *b, int *cost_a, int *cost_b, int index)
{
    int size_a = stack_size(a);
    int size_b = stack_size(b);
    int pos_b = get_pos(b, index);
    int pos_a = get_target_pos(a, index);

    // cost_b
    if (pos_b <= size_b / 2)
        *cost_b = pos_b;
    else
        *cost_b = pos_b - size_b;

    // cost_a
    if (pos_a <= size_a / 2)
        *cost_a = pos_a;
    else
        *cost_a = pos_a - size_a;
}

void do_rotate(t_node **a, t_node **b, int *cost_a, int *cost_b)
{
    while (*cost_a > 0 && *cost_b > 0)
    {
        rr(a, b);
        (*cost_a)--;
        (*cost_b)--;
    }
    while (*cost_a < 0 && *cost_b < 0)
    {
        rrr(a, b);
        (*cost_a)++;
        (*cost_b)++;
    }
}

void finish_rotate_a(t_node **a, int cost_a)
{
    while (cost_a > 0)
    {
        ra(a);
        cost_a--;
    }
    while (cost_a < 0)
    {
        rra(a);
        cost_a++;
    }
}

void finish_rotate_b(t_node **b, int cost_b)
{
    while (cost_b > 0)
    {
        rb(b);
        cost_b--;
    }
    while (cost_b < 0)
    {
        rrb(b);
        cost_b++;
    }
}


int get_cheapest(t_node *a, t_node *b)
{
    t_node *tmp = b;
    int best_index = tmp->index;
    int best_cost = 2147483647;

    while (tmp)
    {
        int cost_a;
        int cost_b;
        int total;

        get_cost(a, b, &cost_a, &cost_b, tmp->index);
        total = (cost_a >= 0 ? cost_a : -cost_a)
              + (cost_b >= 0 ? cost_b : -cost_b);

        if (total < best_cost)
        {
            best_cost = total;
            best_index = tmp->index;
        }
        tmp = tmp->next;
    }
    return (best_index);
}

void greedy_push_back(t_node **a, t_node **b)
{
    int index;
    int cost_a;
    int cost_b;

    while (*b)
    {
        index = get_cheapest(*a, *b);
        get_cost(*a, *b, &cost_a, &cost_b, index);

        do_rotate(a, b, &cost_a, &cost_b);
        finish_rotate_a(a, cost_a);
        finish_rotate_b(b, cost_b);

        pa(a, b);
    }
}

void greedy_sort(t_node **a, t_node **b)
{
    int size;
    int chunk;

    size = stack_size(*a);

    if (size <= 100)
        chunk = 25;
    else
        chunk = 60;

    push_chunks_greedy(a, b, chunk);

    greedy_push_back(a, b);
}

