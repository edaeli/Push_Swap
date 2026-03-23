/*
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
    int             value;
    int             index;
    struct s_node   *next;
}   t_node;

t_node  *new_node(int value);
void    add_back(t_node **stack, t_node *new);
int     stack_size(t_node *stack);
void    free_stack(t_node **stack);

void    swap(t_node **stack);
void    push(t_node **src, t_node **dst);
void    rotate(t_node **stack);
void rev_rotate(t_node **stack);

void    sa(t_node **a);
void    sb(t_node **b);
void    ss(t_node **a, t_node **b);

void    pa(t_node **a, t_node **b);
void    pb(t_node **a, t_node **b);

void    ra(t_node **a);
void    rb(t_node **b);
void    rr(t_node **a, t_node **b);

void rra(t_node **a);
void rrb(t_node **b);
void rrr(t_node **a, t_node **b);

int     *stack_to_array(t_node *stack);
void    sort_array(int *arr, int size);
void    assign_index(t_node *stack, int *arr, int size);
void    index_stack(t_node *stack);
int is_sorted(t_node *stack);

double  compute_disorder(t_node *a);

void simple_sort(t_node **a, t_node **b);

void bucket_sort(t_node **a, t_node **b);

// void push_back_to_a(t_node **a, t_node **b);

void push_chunks(t_node **a, t_node **b, int chunk);
int	find_max_pos(t_node *stack);
int find_min_pos(t_node *stack);

void	sort_3(t_node **a);
void	sort_5(t_node **a, t_node **b);

int		is_number(char *str);
int		ft_atoi_safe(char *str, int *error);
int		has_duplicates(t_node *stack, int value);
t_node	*parse_args(int argc, char **argv);
void	error_exit(void);

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
int	word_count(const char *s, char delim);
int	alloc_word(char **words, int pos, size_t len);
int	split_words(char **words, const char *s, char delim);
char	**ft_split(char const *s, char delim);
int	is_empty_split(char **arr);
void	add_number(t_node **stack, char *str);
// t_node	*parse_args_split(int argc, char **argv);
size_t ft_strlen(const char *s);
void ft_putnbr_fd(int n, int fd);
void free_split(char **arr);

void rotate_both(t_node **a, t_node **b, int *pos);
void rev_rotate_both(t_node **a, t_node **b, int *pos);

//bucket2
int get_target_pos(t_node *a, int index);
int get_pos(t_node *stack, int index);
void get_cost(t_node *a, t_node *b, int *cost_a, int *cost_b, int index);
void do_rotate(t_node **a, t_node **b, int *cost_a, int *cost_b);
void finish_rotate_a(t_node **a, int cost_a);
void finish_rotate_b(t_node **b, int cost_b);
int get_cheapest(t_node *a, t_node *b);
void greedy_push_back(t_node **a, t_node **b);

void push_chunks(t_node **a, t_node **b, int chunk_size);
void push_back_quick(t_node **a, t_node **b);
void quick_sort(t_node **a, t_node **b);

#endif
*/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
    int             value;
    int             index;
    struct s_node   *next;
}   t_node;

// Структура для --bench (необязательно, но удобно)
typedef struct s_stats
{
    int sa, sb, ss;
    int pa, pb;
    int ra, rb, rr;
    int rra, rrb, rrr;
    int total;
} t_stats;

// Стек и базовые утилиты
t_node  *new_node(int value);
void    add_back(t_node **stack, t_node *new);
int     stack_size(t_node *stack);
void    free_stack(t_node **stack);
int     is_sorted(t_node *stack);

// Базовые операции (operations.c)
void    swap(t_node **stack);
void    push(t_node **src, t_node **dst);
void    rotate(t_node **stack);
void    rev_rotate(t_node **stack);

// Команды с выводом (commands.c / reverse_rotate.c)
void    sa(t_node **a);
void    sb(t_node **b);
void    ss(t_node **a, t_node **b);
void    pa(t_node **a, t_node **b);
void    pb(t_node **a, t_node **b);
void    ra(t_node **a);
void    rb(t_node **b);
void    rr(t_node **a, t_node **b);
void    rra(t_node **a);
void    rrb(t_node **b);
void    rrr(t_node **a, t_node **b);

// Индексация и Disorder
void    index_stack(t_node *stack);
double  compute_disorder(t_node *a);

// --- СТРАТЕГИИ СОРТИРОВКИ ---

// 1. Simple (O(n2))
void    simple_sort(t_node **a, t_node **b);
void    sort_3(t_node **a);
void    sort_5(t_node **a, t_node **b);

// 2. Medium (O(n*sqrt(n))) - Твой Chunk Sort
void chunk_sort(t_node **a, t_node **b);

// 3. Complex (O(n log n))
void    radix_sort(t_node **a, t_node **b);

// 4. Custom/Adaptive - Твой Greedy
void greedy_sort(t_node **a, t_node **b);

// Вспомогательные функции для поиска
int     find_max_pos(t_node *stack);
int     find_min_pos(t_node *stack);

// Парсинг и ошибки
t_node  *parse_args(int argc, char **argv);
int     ft_atoi_safe(char *str, int *error);
int     is_number(char *str);
int     has_duplicates(t_node *stack, int value);
void    error_exit(void);

// Либа (split.c и утилиты)
char    **ft_split(char const *s, char delim);
void    free_split(char **arr);
size_t  ft_strlen(const char *s);
int     ft_strcmp(char *s1, char *s2);
void    ft_putnbr_fd(int n, int fd);

// ha
  // Вместо bucket_sort
 // Вместо bucket_sort2


void count_op(char *op, int mode);

#endif