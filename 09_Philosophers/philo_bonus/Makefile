
NAME		=	philo_bonus

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -pthread

SRC			=	./philo_init_bonus.c\
				./philo_utils_bonus.c\
				./philo_exit_bonus.c\
				./routine_philo_bonus.c\
				./routine_death_bonus.c\
				./routine_reaper_bonus.c\
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
