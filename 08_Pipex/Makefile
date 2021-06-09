NAME		= pipex

LIBFT		= ./libft/libft.a

INCLUDES	= -I include

LIBFT_DIR	= $(dir ${LIBFT})
LIBS		= -L ${LIBFT_DIR} -lft
INCLUDES	+= -I ${LIBFT_DIR}/include

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC			= ./pipex.c

OBJ			= ${SRC:.c=.o}

.c.o:
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

all:		$(NAME)

${LIBFT}:
			$(MAKE) -s -C ${LIBFT_DIR}

$(NAME):	${LIBFT} ${OBJ}
			${CC} ${CFLAGS} ${OBJ} ${LIBS} -o ${NAME}

clean:
			rm -rf ${OBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.phony:		all clean fclean re
