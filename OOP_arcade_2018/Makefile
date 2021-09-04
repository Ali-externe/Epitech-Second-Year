##
## EPITECH PROJECT, 2017
## PSU_2018_malloc
## File description:
## Makefile
##

SRCLIBS	=	lib/lib_sfml.cpp	\
			lib/lib_sfml2.cpp	\
			lib/lib_sfml3.cpp	\
			lib/lib_sfml4.cpp	\
			lib/lib_sfml5.cpp

SRCLIBN	=	lib/lib_ncurse.cpp	\
			lib/lib_ncurse2.cpp	\
			lib/lib_ncurse3.cpp	\
			lib/lib_ncurse4.cpp	\
			lib/lib_ncurse5.cpp

SRCLIBSDL	=	lib/lib_sdl.cpp	\
				lib/lib_sdl2.cpp	\
				lib/lib_sdl3.cpp	\
				lib/lib_sdl4.cpp	\
				lib/lib_sdl5.cpp

SRCGAME	=	games/game.cpp

SRC		=	main.cpp	\
			dl.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME	=	arcade

NAMEGAME	=	lib_arcade_pacman.so

NAMELIBS	=	lib_arcade_sfml.so

NAMELIBN	=	lib_arcade_ncurses.so

NAMELIBSDL	=	lib_arcade_sdl.so

all:	$(NAME)

$(NAME) :	$(OBJ)
	g++ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -fPIC -shared $(SRCLIBS) -o $(NAMELIBS) -g3
	g++ -lncurses -fPIC -shared $(SRCLIBN) -o $(NAMELIBN) -g3
	g++ -fPIC -shared $(SRCLIBSDL) -lSDL -lSDL_image -lSDL_ttf -o $(NAMELIBSDL) -g3
	g++ -fPIC -shared $(SRCGAME) -o $(NAMEGAME) -g3
	g++ -ldl $(OBJ) -o $(NAME) -g3
	cp $(NAMEGAME) ./games/

core:	$(OBJ)
	g++ -ldl $(OBJ) -o $(NAME)

graphicals:
	g++ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -fPIC -shared $(SRCLIBS) -o $(NAMELIBS)
	g++ -lncurses -fPIC -shared $(SRCLIBN) -o $(NAMELIBN)
	g++ -fPIC -shared $(SRCLIBSDL) -lSDL -lSDL_image -lSDL_ttf -o $(NAMELIBSDL)

games:
	g++ -fPIC -shared $(SRCGAME) -o $(NAMEGAME)
	cp $(NAMEGAME) ./games/

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAMELIBN)
	rm -rf $(NAMELIBS)
	rm -rf $(NAMELIBSDL)
	rm -rf $(NAME)
	rm -rf $(NAMEGAME)

re:	fclean all

.PHONY: all clean re fclean
