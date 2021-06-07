NAME		= push_swap
LIBFT		= ./libft/libft.a
INCL_DIR	= include 

CC			= gcc
C_FLAGS		= -Wall -Wextra -Werror

LIBFT_DIR	= $(dir ${LIBFT})
LIBFT_FLAGS	= -L ${LIBFT_DIR} -lft
INCL_DIR	+= -I ${LIBFT_DIR}include

SRC			=	./main.c \
				./moves/swap.c \
				./moves/push_a.c \
				./moves/push_b.c \
				./moves/reverse_rotate.c \
				./moves/rotate.c \
				./src_push_swap/parse_input.c \
				./src_push_swap/array_sorted.c \
				./src_push_swap/sort_quick_sort.c \
				./src_push_swap/sort_insertion_sort.c \
				./utils/t_part.c\
				./utils/utils.c


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
