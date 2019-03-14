##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## solver
##

CC	= gcc

RM	= rm -f

NAME	= solver

SRCS	=	src/main.c			\
		src/my_str_to_wordtab.c		\
		src/tools.c			\
		src/algo.c			\
		src/prepa_maze.c


OBJS	= $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
