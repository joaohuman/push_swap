#VARIAVEIS
CC = cc
CFLAGS = -g3 $(INCLUDE) -Wall -Wextra -Werror
INCLUDE = -I ./include
SRCS = push_swap.c \
		support/ft_is_number.c \
		support/ft_calloc.c \
		support/ft_bzero.c \
		support/ft_stoi.c \
		moves/moves.c \
		ordenate/ordenate.c
NAME = push_swap
OBJECTS = $(SRCS:.c=.o)

#TARGETS
all: $(NAME)
#	./$(NAME) 1 4 3 6 5 9 8 7 66 55 44 0 -1231

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJECTS) -o $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re