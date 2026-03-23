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

void add_front(t_node **stack, t_node *new_node)
{
    if (!stack || !new_node)
        return;
    new_node->next = *stack;
    *stack = new_node;
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

int is_sorted(t_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->index > stack->next->index)
            return 0;
        stack = stack->next;
    }
    return 1; 
}

void count_op(char *op, int mode)
{
	static int total = 0;
	static int sa = 0, sb = 0, ss = 0, pa = 0, pb = 0;
	static int ra = 0, rb = 0, rr = 0, rra = 0, rrb = 0, rrr = 0;

	if (mode == 1) // Режим инкремента (считаем)
	{
		total++;
		if (!op) return ;
		if (ft_strcmp(op, "sa") == 0) sa++;
		else if (ft_strcmp(op, "sb") == 0) sb++;
		else if (ft_strcmp(op, "ss") == 0) ss++;
		else if (ft_strcmp(op, "pa") == 0) pa++;
		else if (ft_strcmp(op, "pb") == 0) pb++;
		else if (ft_strcmp(op, "ra") == 0) ra++;
		else if (ft_strcmp(op, "rb") == 0) rb++;
		else if (ft_strcmp(op, "rr") == 0) rr++;
		else if (ft_strcmp(op, "rra") == 0) rra++;
		else if (ft_strcmp(op, "rrb") == 0) rrb++;
		else if (ft_strcmp(op, "rrr") == 0) rrr++;
	}
	else if (mode == 2) // Режим печати (вывод в stderr)
	{
		write(2, "[bench] Total operations: ", 26);
		ft_putnbr_fd(total, 2);
		write(2, "\n", 1);
		if (sa) { write(2, "[bench] sa: ", 12); ft_putnbr_fd(sa, 2); write(2, "\n", 1); }
		if (sb) { write(2, "[bench] sb: ", 12); ft_putnbr_fd(sb, 2); write(2, "\n", 1); }
		if (ss) { write(2, "[bench] ss: ", 12); ft_putnbr_fd(ss, 2); write(2, "\n", 1); }
		if (pa) { write(2, "[bench] pa: ", 12); ft_putnbr_fd(pa, 2); write(2, "\n", 1); }
		if (pb) { write(2, "[bench] pb: ", 12); ft_putnbr_fd(pb, 2); write(2, "\n", 1); }
		if (ra) { write(2, "[bench] ra: ", 12); ft_putnbr_fd(ra, 2); write(2, "\n", 1); }
		if (rb) { write(2, "[bench] rb: ", 12); ft_putnbr_fd(rb, 2); write(2, "\n", 1); }
		if (rr) { write(2, "[bench] rr: ", 12); ft_putnbr_fd(rr, 2); write(2, "\n", 1); }
		if (rra) { write(2, "[bench] rra: ", 13); ft_putnbr_fd(rra, 2); write(2, "\n", 1); }
		if (rrb) { write(2, "[bench] rrb: ", 13); ft_putnbr_fd(rrb, 2); write(2, "\n", 1); }
		if (rrr) { write(2, "[bench] rrr: ", 13); ft_putnbr_fd(rrr, 2); write(2, "\n", 1); }
	}
}