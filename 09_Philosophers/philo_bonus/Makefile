
NAME		=	philo_bonus

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -pthread -fsanitize=address

SRC			=	./philo_init_bonus.c\
				./philo_utils_bonus.c\
				./philo_routine_bonus.c\
				./waiter_routine_bonus.c\
				./sated_routine_bonus.c\
				./dead_routine_bonus.c\
				./philo_exit_bonus.c\
				./philo_bonus.c\

OBJ			=	${SRC:.c=.o}

.c.o:
			${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJ}
			${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean:
			rm -rf ${OBJ}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.phony:		all clean fclean re
