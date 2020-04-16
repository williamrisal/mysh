##
## EPITECH PROJECT, 2019
## minishell
## File description:
## Makefile
##

SRC	=	src/main.c\
		src/get_next_line.c\
		src/function_sys.c\
		src/input.c\
		global.c \
		src/command.c \
		src/unsetenv.c \
		src/my_strcpy.c \
		src/my_strcmp.c \
		src/my_strcat.c \
		src/my_strncmp.c

NAME = mysh

all:	$(NAME)

$(NAME):
	rm -f $(NAME)
	gcc $(SRC) -o $(NAME)

clean:
	$(fclean)


fclean:
	rm -f $(NAME)

re:
	$(clean) $(all)
	gcc $(SRC) -o $(NAME) -g3

test:
	rm -f $(NAME)
	$(clean) $(all)
	gcc $(SRC) -o mysh -g3
	./mysh
