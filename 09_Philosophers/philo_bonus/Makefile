
NAME		=	philo_bonus

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -pthread

SRC			=	./waiter_routine.c\
				./philo_routine.c\
				./philo_utils.c\
				./philo_checks.c\
				./philo_exit.c\
				./philo_init.c\
				./philo.c

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
