/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taslanya <taslanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 20:44:01 by taslanya          #+#    #+#             */
/*   Updated: 2026/03/24 20:51:47 by taslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i + 1 < dstsize && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

/* -------------------- ft_split -------------------- */

int	word_count(const char *s, char delim)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	while (s[i])
	{
		in_word = 0;
		while (s[i] == delim && s[i])
			i++;
		while (s[i] != delim && s[i])
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
			i++;
		}
	}
	return (count);
}

int	alloc_word(char **words, int pos, size_t len)
{
	int	i;

	i = 0;
	words[pos] = malloc(len);
	if (!words[pos])
	{
		while (i < pos)
		{
			free(words[i]);
			i++;
		}
		free(words);
		return (1);
	}
	return (0);
}
