##
## EPITECH PROJECT, 2020
## Makefile project
## File description:
## Builds the project.
##

NAME = yes
NAME1 = solver
NAME2 = generator
OBJ = lib/my/*.o

all : $(NAME)

$(NAME):
	make -C lib/my
	make -C solver/
	make -C generator/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f solver/$(NAME1)
	rm -f generator/$(NAME2)

re: fclean all