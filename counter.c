#include "push_swap.h"

void count_op(char *op, int mode)
{
    static int ops[11] = {0}; // sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
    static int total = 0;
    char *names[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};

    if (mode == 1) // Режим инкремента
    {
        total++;
        for (int i = 0; i < 11; i++)
            if (ft_strcmp(op, names[i]) == 0)
                ops[i]++;
    }
    else if (mode == 2) // Режим печати статистики (в stderr)
    {
        write(2, "[bench] Total operations: ", 26);
        ft_putnbr_fd(total, 2);
        write(2, "\n", 1);
        for (int i = 0; i < 11; i++)
        {
            if (ops[i] > 0)
            {
                write(2, "[bench] ", 8);
                write(2, names[i], ft_strlen(names[i]));
                write(2, ": ", 2);
                ft_putnbr_fd(ops[i], 2);
                write(2, "\n", 1);
            }
        }
    }
}