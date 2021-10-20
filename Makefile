##
## EPITECH PROJECT, 2021
## makefile
## File description:
## faire fichier
##

SRC	=	main.c

OBJ	=	${SRC:.c=.o}

NAME	=	101pong

all:	${NAME}

$(NAME):	${OBJ}
	gcc -o ${NAME} ${OBJ} -lm

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re:	fclean all
