##
## EPITECH PROJECT, 2017
## makefile
## File description:
## Makefile root
##

SRC	=	src/malloc.c \
		src/tools.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_malloc.so

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-Iinclude

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -shared -fpic -o $(NAME) $(SRC) -I include

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:	fclean all

.PHONY: all re clean fclean
