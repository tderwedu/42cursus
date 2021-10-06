# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/26 15:59:03 by tderwedu          #+#    #+#              #
#    Updated: 2021/10/06 13:00:59 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #

NAME	= minishell

LIBFT	= ./libft
RDLINE	= /Users/$(USER)/.brew/opt/readline

SRC		=	./src/builtins/msh_echo.c \
			./src/builtins/msh_cd.c \
			./src/builtins/msh_unset.c \
			./src/builtins/msh_exit.c \
			./src/builtins/msh_pwd.c \
			./src/builtins/msh_env.c \
			./src/builtins/msh_export.c \
			./src/launcher/command1.c \
			./src/launcher/command2.c \
			./src/launcher/launch.c \
			./src/launcher/redirection.c \
			./src/launcher/heredoc.c \
			./src/launcher/get_bin.c \
			./src/launcher/is_builtin.c \
			./src/parsing/lexer1.c \
			./src/parsing/lexer2.c \
			./src/parsing/parser1.c \
			./src/parsing/parser2.c \
			./src/parsing/parser3.c \
			./src/parsing/word_expansion1.c \
			./src/parsing/word_expansion2.c \
			./src/signals/signals.c \
			./src/utils/utils.c \
			./src/utils/set_path.c \
			./src/utils/msh_canonpath.c \
			./src/utils/msh_print_error.c \
			./src/utils/utils_cst.c \
			./src/utils/utils_env.c \
			./MiniShell.c

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

OBJ		= ${SRC:.c=.o}

INCL	= -I ${LIBFT} -I ${RDLINE}/include -I ./include

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
