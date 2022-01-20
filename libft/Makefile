SOURCE	=	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c

BONUS	=	ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c	\
			ft_lstsize.c

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

HEADER	=	libft.h

BONUS_O	=	${BONUS:.c=.o}

OBJECTS	=	${SOURCE:.c=.o}

RM		=	rm -f

NAME	=	libft.a

AR		=	ar rc

CFLAGS	=	-Wall -Wextra -Werror

%.o: %.c ${HEADER}
			@gcc ${CFLAGS} -c $< -o ${<:.c=.o}
			@echo "$(GREEN)/$(RESET)\c"

$(NAME):	${OBJECTS}
			@${AR} ${NAME} ${OBJECTS}

all:		${NAME}

clean:
			@${RM} ${OBJECTS} ${BONUS_O}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

bonus:		${BONUS_O}
			@${AR} ${NAME} ${BONUS_O}

.PHONY:		all clean fclean bonus
