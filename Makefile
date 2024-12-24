NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = ft_split.c ft_split_utils.c global_utils.c path_utils.c pipex.c struct_utils.c pipex_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
