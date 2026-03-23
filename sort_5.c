#include "push_swap.h"

void	sort_5(t_node **a, t_node **b)
{
	int	min_pos;

	while (stack_size(*a) > 3)
	{
		min_pos = find_min_pos(*a);
		if (min_pos <= stack_size(*a) / 2)
			while (min_pos-- > 0)
				ra(a);
		else
		{
			min_pos = stack_size(*a) - min_pos;
			while (min_pos-- > 0)
				rra(a);
		}
		pb(a, b);
	}
	sort_3(a);
	pa(a, b);
	pa(a, b);
}
