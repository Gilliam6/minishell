# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/15 19:12:42 by fuserwyn          #+#    #+#              #
#    Updated: 2021/10/12 22:30:53 by fuserwyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	ft_atoi.c			\
		ft_bzero.c			\
		ft_calloc.c			\
		ft_isalnum.c		\
		ft_isalpha.c		\
		ft_isascii.c		\
		ft_isdigit.c		\
		ft_isprint.c		\
		ft_memccpy.c		\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_memcpy.c			\
		ft_memmove.c		\
		ft_memset.c			\
		ft_strchr.c			\
		ft_strdup.c			\
		ft_strlcat.c		\
		ft_strlcpy.c		\
		ft_strlen.c			\
		ft_strncmp.c		\
		ft_strnstr.c		\
		ft_strrchr.c		\
		ft_tolower.c		\
		ft_toupper.c		\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c		\
		ft_strmapi.c		\
		ft_substr.c			\
		ft_strjoin.c		\
		ft_strtrim.c		\
		ft_itoa.c			\
		ft_split.c			\
		ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\

OBJS = ${SRC:.c=.o}

FLAGS = -Wall -Wextra -Werror

RM	= rm -f

AR 	= ar rcs

CC = gcc

HDRS = -I libft.h

.c.o:
			${CC} ${FLAGS} -c ${HDRS} $< -o ${<:.c=.o}

all:		${NAME}

${NAME}: 	${OBJS}
			${AR} ${NAME} $?


clean:
			${RM} ${OBJS}

fclean: 
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re