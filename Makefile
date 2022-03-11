NAME = push_swap

LIBFT =	libft/libft.a

SRCS =	push_swap.c \
		parsing.c \
		fnct1.c \
		fnct2.c \
		fnct3.c \
		radix.c \

ODIR = build

OBJS = $(patsubst $(SDIR)/%,$(ODIR)/%,$(SRCS:.c=.o))

HEADER =	push_swap.h \
			libft/libft.h \

CC = gcc

FLAGS = -Wall -Wextra -Werror
# FLAGS += -fsanitize=address -g3

all: lib $(NAME)

lib:
	make -C libft

%.o : %.c $(HEADER) Makefile
	$(CC) $(FLAGS) -I includes -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
 
clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY:	all lib clean fclean re
