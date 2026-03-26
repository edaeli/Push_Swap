NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = main.c \
	stack_utils.c \
	stack_utils2.c \
	operations.c \
	operations2.c \
	commands.c \
	commands2.c \
	counter.c \
	indexing.c \
	disorder.c \
	reverse_rotate.c \
	simple_sort.c \
	bucket_sort.c \
	bucket_sort2.c \
	sort_3.c \
	sort_5.c \
	parser.c \
	split.c \
	radix_sort.c \
	bucket_sort3.c \
	split2.c \
	split3.c

# Превращаем список .c в список .o
OBJS = $(SRCS:.c=.o)

# Главное правило сборки
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Правило для компиляции .c в .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
