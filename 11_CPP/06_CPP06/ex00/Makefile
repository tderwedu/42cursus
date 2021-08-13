# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/13 09:28:34 by tderwedu          #+#    #+#              #
#    Updated: 2021/08/13 10:29:28 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #
NAME	= ex00

SRC		= ./main.cpp

CC		= clang++
CFLAGS	= -Wall -Wextra -Werror

OBJ		= ${SRC:.cpp=.o}

# ================================== RULES =================================== #

%.o:		%.cpp
			${CC} ${CFLAGS} -c $< -o $@

all:		$(NAME)

$(NAME):	${OBJ}
			${CC} ${CFLAGS} ${OBJ} -o $(NAME)

clean:
			rm -f ${OBJ}

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.phony:		all clean fclean re
