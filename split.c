/*#include "push_swap.h"

int	is_empty_split(char **arr)
{
	if (!arr || !arr[0])
		return (1);
	return (0);
}


static int word_count(const char *s, char delim)
{
    int i;
    int count;
    int in_word;

    i = 0;
    count = 0;
    while (s[i] != '\0')
    {
        in_word = 0;
        while (s[i] == delim && s[i] != '\0')
            i++;
        while (s[i] != delim && s[i] != '\0')
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

static int alloc_word(char **words, int pos, size_t len)
{
    int i;

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

static int split_words(char **words, const char *s, char delim)
{
    int  j;
    size_t len;

    j = 0;
    while (*s != '\0')
    { 
        len = 0;
        while (*s == delim && *s != '\0')
            s++;
        while (*s != delim && *s != '\0')
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

char **ft_split(char const *s, char delim)
{
    char **words;
    int  wc;

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
*/

#include "push_swap.h"


size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
        size_t  i;

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

size_t ft_strlen(const char *s)
{
    size_t len = 0;
    while (s[len])
        len++;
    return (len);
}

void ft_putnbr_fd(int n, int fd)
{
    char c;
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
    c = (n % 10) + '0';
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

/* -------------------- Helper -------------------- */

int	is_empty_split(char **arr)
{
	if (!arr || !arr[0])
		return (1);
	return (0);
}

/* -------------------- Add number -------------------- */

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

/* -------------------- Parse args -------------------- */

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

void free_split(char **arr)
{
    int i = 0;

    if (!arr)
        return ;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
