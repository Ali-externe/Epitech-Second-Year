##
## EPITECH PROJECT, 2019
## plazza
## File description:
## Makefile
##

NAME    =	plazza

SRC     =	main.cpp	\
		check_command.cpp \
		cook.cpp	\
		kitchen.cpp	\
		reception.cpp

OBJ     =        $(SRC:.cpp=.o)

CPPFLAGS =

all: $(NAME)

$(NAME): $(OBJ)
	g++ -pthread $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)
	rm *# -rf


fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
