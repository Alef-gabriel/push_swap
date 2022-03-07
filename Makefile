SRCS =	./push_swap.c \
		./game_func.c \
		./radix.c \
		./small_sort.c \
		./split.c \
		./utils.c \
		./utils2.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

CC = clang
RM = rm -f

CFLAGS = -Wall -Werror -Wextra

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all