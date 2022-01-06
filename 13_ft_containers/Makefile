# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 09:36:32 by tderwedu          #+#    #+#              #
#    Updated: 2022/01/06 11:26:51 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_FT		:= ft
NAME_STD	:= std

SRC_DIR		:= ./src
TESTER_DIR	:= ./Tester

# ================================ VARIABLES ================================= #

INCLUDES	:= -I ${SRC_DIR} -I ${TESTER_DIR}

SRC			:=	./Tester/Timer.cpp \
				./Tester/Tester.cpp \
				./Tester/Vector/constructors.cpp \
				./Tester/Vector/capacity.cpp \
				./Tester/Vector/iterators.cpp \
				./Tester/Vector/const_iterators.cpp \
				./Tester/Vector/reverse_iterators.cpp \
				./Tester/Vector/elementAccess.cpp \
				./Tester/Vector/modifiers.cpp \
				./Tester/Vector/relationalOperators.cpp \
				./Tester/Map/constructors.cpp \
				./Tester/Map/capacity.cpp \
				./Tester/Map/iterators.cpp \
				./Tester/Map/elementAccess.cpp \
				./Tester/Map/modifiers.cpp \
				./Tester/Map/observers.cpp \
				./Tester/Map/operations.cpp \
				./Tester/Map/relationalOperators.cpp \
				./Tester/Stack/stack.cpp \
				./Tester/tests.cpp

OBJ			:= ${SRC:.cpp=.o}

CC			:= clang++

CFLAGS		:= -Wall -Wextra -Werror -std=c++98


# ================================== RULES =================================== #

%.o:		%.cpp
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

all:		${OBJ}
			${CC} ${C_FLAGS} -D FT_CONTAINERS=std ${INCLUDES} ${OBJ} -o ${NAME_STD}

clean:
			rm -rf ${OBJ}

fclean:		clean
			rm -rf ${NAME_FT} ${NAME_STD}

re:			fclean all

.phony:		all clean fclean re
