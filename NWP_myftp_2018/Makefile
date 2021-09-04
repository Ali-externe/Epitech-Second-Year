##
## EPITECH PROJECT, 2018
## Makefile
## File description:
##
##

NAME	=	myftp

SRCS	=	server.c

OBJS	=	$(SRCS:.c=.o)

all:	compile clean

compile:
	gcc $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all compile clean fclean re
