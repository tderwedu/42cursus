# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/28 09:22:15 by tderwedu          #+#    #+#              #
#    Updated: 2021/10/13 17:34:06 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #

NAME	= brainz

SRC		= ./Zombie.cpp\
		  ./newZombie.cpp\
		  ./randomChump.cpp\
		  ./main.cpp

CC		= clang++
CFLAGS	= -Wall -Wextra -Werror

OBJ		= ${SRC:.cpp=.o}

# ================================== RULES =================================== #

%.o:		%.cpp
			${CC} ${CFLAGS} -c $< -o $@

all:		$(NAME)

$(NAME):	${OBJ}
			${CC} ${CFLAGS} ${OBJ} -o ${NAME}

run:		$(NAME)
			./${NAME}

clean:
			rm -f ${OBJ}

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

.phony:		all run clean fclean re
