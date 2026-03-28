NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

COMMON_SRCS = stack_utils.c \
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
	chunk_sort.c \
	greedy_sort.c \
	greedy_sort2.c \
	sort_3.c \
	sort_5.c \
	parser.c \
	split.c \
	split2.c \
	split3.c \
	radix_sort.c

PS_SRCS = main.c
PS_OBJS = $(PS_SRCS:.c=.o) $(COMMON_SRCS:.c=.o)

BONUS_SRCS = checker.c \
	get_next_line.c \
	get_next_line_utils.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o) $(COMMON_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(PS_OBJS)
	$(CC) $(CFLAGS) $(PS_OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(PS_OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
