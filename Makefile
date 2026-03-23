NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Список всех твоих .c файлов
SRCS = main.c \
       stack_utils.c \
       operations.c \
       commands.c \
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
       radix_sort.c

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