NAME		= push_swap
BONUS		= checker
LIBFT		= ./src/libft/libft.a
INCL_DIR	= include 

CC			= gcc
C_FLAGS		= -Wall -Wextra -Werror

LIBFT_DIR	= $(dir ${LIBFT})
LIBFT_FLAGS	= -L ${LIBFT_DIR} -lft
INCL_DIR	+= -I ${LIBFT_DIR}include

SRC_M		=	./src/moves/swap.c \
				./src/moves/push_a.c \
				./src/moves/push_b.c \
				./src/moves/reverse_rotate.c \
				./src/moves/rotate.c \
				./src/utils/t_part.c \
				./src/utils/utils.c \
				./src/utils/parse_input.c \
				./src/src_push_swap/push_swap.c \
				./src/src_push_swap/array_sorted.c \
				./src/src_push_swap/sort_quick_sort.c \
				./src/src_push_swap/sort_insertion_sort.c \
				./src/src_push_swap/sort_utils.c \
				./src/not_submitted.c

SRC_B		=	./src/moves/swap.c \
				./src/moves/push_a.c \
				./src/moves/push_b.c \
				./src/moves/reverse_rotate.c \
				./src/moves/rotate.c \
				./src/utils/utils.c \
				./src/utils/parse_input.c \
				./src/src_checker/read_instructions.c \
				./src/src_checker/checker.c \

OBJ_M		= ${SRC_M:.c=.o}

OBJ_B		= ${SRC_B:.c=.o}

.c.o:		
			${CC} ${C_FLAGS} -I ${INCL_DIR} -c $< -o $@

all:		${NAME}

${LIBFT}:
			${MAKE} -s -C ${LIBFT_DIR}

$(NAME):	${OBJ_M}
			${CC} ${CFLAGS} -fsanitize=address ${OBJ_M} ${LIBFT_FLAGS} -o ${NAME}

$(BONUS):	${LIBFT} ${OBJ_B}
			${CC} ${CFLAGS} -fsanitize=address ${OBJ_B} ${LIBFT_FLAGS} -o ${BONUS}

bonus:		$(BONUS)

clean:
			rm -rf ${OBJ_M} ${OBJ_B}

fclean:		clean
			rm -f ${NAME} ${BONUS}

bclean:		
			rm -rf ${OBJ_B} ${BONUS}

re:			fclean all

.phony:		all bonus clean flcean bclean re
