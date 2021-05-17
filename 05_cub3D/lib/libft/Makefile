# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 15:57:49 by tderwedu          #+#    #+#              #
#    Updated: 2021/05/17 16:14:59 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

LIBFT_FOLDER	= ./
LIBFT_INCLUDES	= $(LIBFT_FOLDER)include

include ${LIBFT_FOLDER}libft.mk

CFLAGS			=	-Wall -Wextra -Werror
CC				=	gcc ${CFLAGS}

LIB				=	ar
LIB_LAGS		=	-rcs

OBJ				= 	${SRC:.c=.o}

.c.o:
			${CC} -I ${LIBFT_INCLUDES} -c $< -o ${<:.c=.o}

$(NAME):	${OBJ}
			${LIB} ${LIB_LAGS} ${NAME} ${OBJ}

all:		${NAME}

clean:
			rm -f ${OBJ} ${OBJ_B}

fclean:		clean
			rm -f ${NAME} bonus

re:			fclean all

.phony:		all clean fclean re

