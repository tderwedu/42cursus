# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/30 14:16:17 by tderwedu          #+#    #+#              #
#    Updated: 2021/10/14 12:44:10 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #

NAME	= fixed

SRC		= ./Fixed.cpp\
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

run:		${NAME}
			./${NAME}

clean:
			rm -f ${OBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.phony:		all run clean fclean re
