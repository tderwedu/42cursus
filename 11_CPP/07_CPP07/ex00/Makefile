# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 10:26:02 by tderwedu          #+#    #+#              #
#    Updated: 2021/10/25 11:06:17 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #

NAME	= run

SRC		=	Fixed.cpp \
			main.cpp

CC		= clang++
CFALGS	= -Wall -Wextra -Werror

OBJ		= ${SRC:.cpp=.o}

# ================================== RULES =================================== #

%.o:		%.cpp
			${CC} ${CFALGS} -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
			${CC} ${CFALGS} ${OBJ} -o ${NAME}

clean:
			rm -rf ${OBJ}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.phony:		all clean fclean re
