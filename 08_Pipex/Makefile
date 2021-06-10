NAME		= pipex

LIBFT		= ./libft/libft.a

INCLUDES	= -I include

LIBFT_DIR	= $(dir ${LIBFT})
LIBS		= -L ${LIBFT_DIR} -lft
INCLUDES	+= -I ${LIBFT_DIR}/include

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC			=	./src/pipex.c \
				./src/pipex_run_prog.c \
				./src/pipex_error.c \
				./src/pipex_utils.c \
				./src/utils/ft_path_join.c \
				./src/utils/free_array.c

OBJ			= ${SRC:.c=.o}

.c.o:
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

all:		$(NAME)

${LIBFT}:
			$(MAKE) -s -C ${LIBFT_DIR}

$(NAME):	${LIBFT} ${OBJ}
			${CC} ${CFLAGS} -fsanitize=address ${OBJ} ${LIBS} -o ${NAME}

clean:
			rm -rf ${OBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.phony:		all clean fclean re
