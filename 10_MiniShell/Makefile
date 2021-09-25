# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/26 15:59:03 by tderwedu          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2021/09/24 15:52:01 by tderwedu         ###   ########.fr        #
=======
#    Updated: 2021/09/24 17:04:10 by tderwedu         ###   ########.fr        #
>>>>>>> c0441df5d3962ebfb1ec197f5bbd1ccbbc6dead7
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #

NAME	= minishell

LIBFT	= ./libft
RDLINE	= /Users/$(USER)/.brew/opt/readline

SRC		=	./lexer.c \
			./parser.c \
			./word_expansion1.c \
			./word_expansion2.c \
<<<<<<< HEAD
=======
			./launcher.c \
>>>>>>> c0441df5d3962ebfb1ec197f5bbd1ccbbc6dead7
			./utils.c \
			./utils_cst.c \
			./utils_env.c \
			./vector/ft_new_vec.c \
			./vector/ft_grow_vec.c \
			./vector/ft_free_vec.c \
			./vector/ft_check_vec.c \
			./MiniShell.c

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

OBJ		= ${SRC:.c=.o}

INCL	= -I ${LIBFT} -I ${RDLINE}/include -I ./vector

LIBS	= -L ${LIBFT} -lft -L ${RDLINE}/lib -lreadline

# ================================== RULES =================================== #

%.o:		%.c
			${CC} ${CFLAGS} ${INCL} -c $< -o $@

all:		$(NAME)

$(NAME):	${OBJ}
			make -C ${LIBFT}
			${CC} -o ${NAME} ${OBJ} ${LIBS}

clean:
			rm -f ${OBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean	all

.phony:		all clean fclean re
