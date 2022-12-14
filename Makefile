#VARIAVEIS
CC = cc
CFLAGS = -g3 $(INCLUDE) -Wall -Wextra -Werror
INCLUDE = -I ./include
SRCS = push_swap.c \
		support/ft_is_number.c \
		support/ft_calloc.c \
		support/ft_bzero.c \
		support/ft_stoi.c \
		support/is_duplicated.c \
		support/is_ordenated.c \
		moves/moves.c \
		moves/double_moves.c \
		ordenate/ordenate.c \
		ordenate/normalization.c

NAME = push_swap
OBJECTS = $(SRCS:.c=.o)

#TARGETS
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJECTS) -o $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re