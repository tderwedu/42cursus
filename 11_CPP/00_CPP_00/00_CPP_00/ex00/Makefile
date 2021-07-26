# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/26 15:59:03 by tderwedu          #+#    #+#              #
#    Updated: 2021/07/26 16:27:21 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #
NAME	= megaphone

SRC		= ./megaphone.cpp

CC		= clang++
CFLAGS	= -Wall -Wextra -Werror

# SRC_D	= ./
# OBJ_D	= obj/

OBJ		= ${SRC:.cpp=.o}
# SRC_P	= $(addprefix ${SRC_D} ${SRC})
# OBJ_P	= $(addprefix ${OBJ_D} ${OBJ})

# ================================== RULES =================================== #

%.o:		%.cpp
			${CC} ${CFLAGS} -c $< -o $@

all:		$(NAME)

$(NAME):	${OBJ}
			${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean:
			rm -f {$OBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean	all

.phony:		all clean fclean re
