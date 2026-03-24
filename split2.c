/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taslanya <taslanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 20:51:54 by taslanya          #+#    #+#             */
/*   Updated: 2026/03/24 20:53:06 by taslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_words(char **words, const char *s, char delim)
{
	int		j;
	size_t	len;

	j = 0;
	while (*s)
	{
		len = 0;
		while (*s == delim && *s)
			s++;
		while (*s != delim && *s)
		{
			len++;
			s++;
		}
		if (len > 0)
		{
			if (alloc_word(words, j, len + 1))
				return (1);
			ft_strlcpy(words[j], s - len, len + 1);
			j++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char delim)
{
	char	**words;
	int		wc;

	if (!s)
		return (NULL);
	wc = word_count(s, delim);
	words = malloc(sizeof(char *) * (wc + 1));
	if (!words)
		return (NULL);
	words[wc] = NULL;
	if (wc == 0)
		return (words);
	if (split_words(words, s, delim))
		return (NULL);
	return (words);
}

int	is_empty_split(char **arr)
{
	if (!arr || !arr[0])
		return (1);
	return (0);
}

void	add_number(t_node **stack, char *str)
{
	int	value;
	int	error;

	if (!is_number(str))
		error_exit();
	error = 0;
	value = ft_atoi_safe(str, &error);
	if (error || has_duplicates(*stack, value))
		error_exit();
	add_back(stack, new_node(value));
}

t_node	*parse_args(int argc, char **argv)
{
	t_node	*stack;
	char	**split;
	int		i;
	int		j;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split || is_empty_split(split))
			error_exit();
		j = 0;
		while (split[j])
		{
			add_number(&stack, split[j]);
			j++;
		}
		free_split(split);
		i++;
	}
	return (stack);
}
