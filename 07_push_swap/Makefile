NAME		= push_swap
LIBFT		= ./libft/libft.a
INCL_DIR	= include 

CC			= gcc
C_FLAGS		= -Wall -Wextra -Werror

LIBFT_DIR	= $(dir ${LIBFT})
LIBFT_FLAGS	= -L ${LIBFT_DIR} -lft
INCL_DIR	+= -I ${LIBFT_DIR}include

SRC			=	./main.c \
				./parse_input.c \
				./swap.c \
				./push.c \
				./reverse_rotate.c \
				./rotate.c \
				./sort_3_nbr.c \
				./utils.c


OBJ			= ${SRC:.c=.o}

.c.o:		
			${CC} ${C_FLAGS} -I ${INCL_DIR} -c $< -o $@

all:		${NAME}

$(NAME):	${LIBFT} ${OBJ}
			${CC} ${CFLAGS} ${OBJ} ${LIBFT_FLAGS} -o ${NAME}

${LIBFT}:
			${MAKE} -s -c ${LIBFT_DIR}

clean:
			rm -rf ${OBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.phony:		all clean flcean re
