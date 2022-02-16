#Library
NAME = 				libft.a

#Compiler 
CC = 				gcc

#Flags
CFLAGS = 			-Wall -Wextra -Werror

#Headers
HEA_PATH = 			.
HEA_NAME = 			libft.h
HEA =				${addprefix ${HEA_PATH}/,${HEA_NAME}}


#Sources
SRC_NAME = 			${shell ls ft_[!l]*.c}

#Bonus
BONUS_NAME = 		${shell ls ft_[l]*.c} get_next_line.c

#Objects
OBJ_PATH = 			.
OBJ_NAME = 			${SRC_NAME:.c=.o}
OBJ_BONUS_NAME =	${BONUS_NAME:.c=.o}
OBJ = 				${addprefix ${OBJ_PATH}/,${OBJ_NAME}}
OBJ_BONUS =			${addprefix ${OBJ_PATH}/,${OBJ_BONUS_NAME}}

${NAME}: 			${OBJ} ${HEA}
					@ar rc ${NAME} ${OBJ}

%.o: 				%.c ${HEA}
					${CC} ${CFLAGS} -c $< -o $@


all: 				${NAME}

bonus:				${OBJ} ${OBJ_BONUS}
					@ar rc ${NAME} ${OBJ} ${OBJ_BONUS}

clean:
					@rm -rf ${OBJ} ${OBJ_BONUS}

fclean: 			clean
					@rm -rf ${NAME} 

re: 				fclean all

.PHONY: 			all clean fclean re bonus