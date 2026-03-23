#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_safe(char *str, int *error)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		{
			*error = 1;
			return (0);
		}
		i++;
	}
	return ((int)(result * sign));
}

int	has_duplicates(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
/*
t_node	*parse_args(int argc, char **argv)
{
	t_node	*stack;
	int		i;
	int		value;
	int		error;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			error_exit();
		error = 0;
		value = ft_atoi_safe(argv[i], &error);
		if (error || has_duplicates(stack, value))
			error_exit();
		add_back(&stack, new_node(value));
		i++;
	}
	return (stack);
}
*/