##
## EPITECH PROJECT, 2018
## make
## File description:
## make
##

CC		= gcc

LD		= ld -s -o

ASM		= nasm

ASMFLAGS	= -f elf64

LDFLAGS 	= -shared

RM		= rm -rf

NAME		= libasm.so

SRCS		=	strlen.s	\
				strchr.s	\
				strcmp.s	\
				strncmp.s

OBJS	= $(SRCS:.s=.o)

%.o: %.s
	$(ASM) -o $@ $< $(ASMFLAGS)


all:  $(NAME)

$(NAME): $(OBJS)
	$(LD) $(CC) $(LDFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
