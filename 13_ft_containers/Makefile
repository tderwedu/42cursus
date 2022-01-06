# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 09:36:32 by tderwedu          #+#    #+#              #
#    Updated: 2022/01/06 13:10:45 by tderwedu         ###   ########.fr        #
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
				./src/RedBlackTree.cpp \
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

BIN_FT		:= ./bin_std
BIN_STD		:= ./bin_std

OBJ_FT		:= $(subst ${SRC_DIR}, ${BIN_FT}, ${SRC:.cpp=.o})
OBJ_STD		:= $(subst ${SRC_DIR}, ${BIN_STD}, ${SRC:.cpp=.o})
# OBJ_STD		:= ${SRC:.cpp=.o}
# OBJ_FT		:= ${SRC:.cpp=.o}

CC			:= clang++

CFLAGS		:= -Wall -Wextra -Werror -std=c++98


# ================================== RULES =================================== #

${BIN_FT}%.o:	${SRC_DIR}%.cpp
				${CC} ${CFLAGS} -D FT_CONTAINER=ft ${INCLUDES} -c $< -o $@

${BIN_STD}%.o:	${SRC_DIR}%.cpp
				${CC} ${CFLAGS} -D FT_CONTAINER=std ${INCLUDES} -c $< -o $@

all:			${OBJ_STD} ${OBJ_FT}
				# ${CC} ${C_FLAGS} -D FT_CONTAINER=std ${INCLUDES} ${OBJ_STD} -o ${NAME_STD}
				${CC} ${C_FLAGS} -D FT_CONTAINER=ft ${INCLUDES} ${OBJ_FT} -o ${NAME_FT}

clean:
				rm -rf ${OBJ}

fclean:			clean
				rm -rf ${NAME_FT} ${NAME_STD}

re:				fclean all

.phony:			all clean fclean re
