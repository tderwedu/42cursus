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
				./moves/swap.c \
				./moves/push_a.c \
				./moves/push_b.c \
				./moves/reverse_rotate.c \
				./moves/rotate.c \
				./sort_find_median_value.c \
				./sort_quick_sort.c \
				./t_part.c\
				./utils.c


OBJ			= ${SRC:.c=.o}

.c.o:		
			${CC} ${C_FLAGS} -I ${INCL_DIR} -c $< -o $@

all:		${NAME}

$(NAME):	${LIBFT} ${OBJ}
			${CC} ${CFLAGS} ${OBJ} ${LIBFT_FLAGS} -o ${NAME}

${LIBFT}:
			${MAKE} -s -C ${LIBFT_DIR}

clean:
			rm -rf ${OBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.phony:		all clean flcean re
