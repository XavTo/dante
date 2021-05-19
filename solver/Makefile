##
## EPITECH PROJECT, 2020
## Makefile project
## File description:
## Builds the project.
##

SRC = 	*.c

NAME = solver

all : $(NAME)

$(NAME):
	gcc *.c -g -o $(NAME) -L ../lib/ -lmy -I ../include

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all