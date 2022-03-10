#Programm
NAME = 				minishell
NAME_BONUS = 		minishell_bonus

#Libft
LIBFT_PATH =		libft
LIBFT = 			ft

#Readline
RL_PATH =			readline
RL = 				readline history

#Compiler
CC = 				gcc

#Flags
CFLAGS = 			-Wall -Wextra -Werror

#Include
INC_PATH = 			includes
INC = 				-I${INC_PATH} -I${LIBFT_PATH} -I${RL_PATH}

#Headers
HEA_NAME =			minishell.h
HEA = 				${addprefix ${INC_PATH}/,${HEA_NAME}}

#Sources
SRC_PATH =			srcs
SRC_NAME_MAIN =		init_environment.c main.c garbage_collector.c tokenizator.c parser.c quotes_check.c ft_custom_split.c \
					space_checker.c tokens_linker.c processing_pipes.c processing_dollars.c token_recognizer.c signals.c \
					ft_exec_command.c processing_tokens.c expensive_dollar.c ft_exec_addition.c ft_cd.c ft_exec_new_command.c \
					ft_bin_path.c
SRC_NAME_BONUS =	init_environment.c main.c garbage_collector.c tokenizator.c parser.c quotes_check.c ft_custom_split.c \
					space_checker.c tokens_linker.c processing_pipes.c processing_dollars.c token_recognizer.c signals.c

#Objects
OBJ_PATH = 			objects
OBJ_MAIN = 			${addprefix ${OBJ_PATH}/,${SRC_NAME_MAIN:.c=.o}}
OBJ_BONUS = 		${addprefix ${OBJ_PATH}/,${SRC_NAME_BONUS:.c=.o}}

${OBJ_PATH}/%.o:	${SRC_PATH}/%.c ${HEA} ${LIBFT_PATH}/*.c ${LIBFT_PATH}/*.h ${LIBFT_PATH}/Makefile ${RL_PATH}/*.c ${RL_PATH}/*.h ${RL_PATH}/Makefile Makefile
					@mkdir -p $(dir $@)
					${CC} ${CFLAGS} -c $< -o $@ ${INC}

${NAME}:			${OBJ_MAIN}
					@$(MAKE) bonus -C ${LIBFT_PATH}
					@$(MAKE) static -C ${RL_PATH}
					${CC} ${CFLAGS} -o ${NAME} ${OBJ_MAIN} -L${LIBFT_PATH} -l${LIBFT} -L${RL_PATH} ${addprefix -l,${RL}} -ltermcap

${NAME_BONUS}:		${OBJ_BONUS}
					@$(MAKE) bonus -C ${LIBFT_PATH}
					@$(MAKE) static -C ${RL_PATH}
					${CC} ${CFLAGS} -o ${NAME_BONUS} ${OBJ_BONUS} -L${LIBFT_PATH} -l${LIBFT} -L${RL_PATH} ${addprefix -l,${RL}} -ltermcap

#Rules

all: 				${NAME}

bonus:				${NAME_BONUS}

clean:
					rm -rf ${OBJ_PATH}
					@make clean -C ${LIBFT_PATH}
					@make clean -C ${RL_PATH}

fclean: 			clean
					rm -rf ${NAME}
					rm -rf ${NAME_BONUS}
					@make fclean -C ${LIBFT_PATH}

re: 				fclean all

norm:				fclean
					norminette ./src
					norminette ./inc
					norminette ./libft

.PHONY: 			all clean fclean re bonus norm
