##
## EPITECH PROJECT, 2020
## makefile
## File description:
## compil
##

SRCS =	main_dante.c \
		create_map.c \
		display_map.c \
		error_gest.c \
		clean_the_map.c \
		create_labyrinthe.c \
		regroup.c \
		write_in_map.c \

OBJS = $(SRCS:.c=.o)

NAME = generator

all : $(NAME)

$(NAME) :
		make -C lib/my
		gcc -g -o $(NAME) $(SRCS) -Werror -Wall -Wextra -L lib/ -lmy -I include
		make x -C lib/my

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

x : re
	clear
	./$(NAME)