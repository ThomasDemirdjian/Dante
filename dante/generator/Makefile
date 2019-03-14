##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## push_swap
##

CC	=	gcc

RM	=	rm -f

NAME	=	generator

CFLAGS	+=	-Wextra -Wall
CFLAGS	+=	-pedantic
CFLAGS	+=	-I./include

SRCS	=	src/main.c	\
		src/init.c	\
		src/built.c

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re