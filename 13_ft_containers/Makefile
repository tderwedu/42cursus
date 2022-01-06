# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 09:36:32 by tderwedu          #+#    #+#              #
#    Updated: 2022/01/06 19:27:41 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_FT		:= ft
NAME_STD	:= std

# ================================ VARIABLES ================================= #
SRC_DIR		:= src/
TEST_DIR	:= tester/

INCLUDES	:= -I ./${SRC_DIR} -I ./${TEST_DIR}

SRC			:=	./src/RedBlackTree.cpp
SRC_TESTER	:=	./tester/Timer.cpp \
				./tester/Tester.cpp \
				./tester/Vector/constructors.cpp \
				./tester/Vector/capacity.cpp \
				./tester/Vector/iterators.cpp \
				./tester/Vector/const_iterators.cpp \
				./tester/Vector/reverse_iterators.cpp \
				./tester/Vector/elementAccess.cpp \
				./tester/Vector/modifiers.cpp \
				./tester/Vector/relationalOperators.cpp \
				./tester/Map/constructors.cpp \
				./tester/Map/capacity.cpp \
				./tester/Map/iterators.cpp \
				./tester/Map/elementAccess.cpp \
				./tester/Map/modifiers.cpp \
				./tester/Map/observers.cpp \
				./tester/Map/operations.cpp \
				./tester/Map/relationalOperators.cpp \
				./tester/Stack/stack.cpp \
				./tester/tests.cpp

BIN_SRC		:= .bin_src/
BIN_FT		:= .bin_ft/
BIN_STD		:= .bin_std/

OBJ_SRC		:= $(subst ${SRC_DIR},${BIN_SRC}, ${SRC:.cpp=.o})
OBJ_FT		:= $(subst ${TEST_DIR},${BIN_FT}, ${SRC_TESTER:.cpp=.o})
OBJ_STD		:= $(subst ${TEST_DIR},${BIN_STD}, ${SRC_TESTER:.cpp=.o})

CC			:= clang++

CFLAGS		:= -Wall -Wextra -Werror -std=c++98

# ================================== RULES =================================== #

${BIN_SRC}%.o:	${SRC_DIR}%.cpp
				@mkdir -p $(dir $@)
				${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${BIN_FT}%.o:	${TEST_DIR}%.cpp
				@mkdir -p $(dir $@)
				${CC} ${CFLAGS} -D FT_CONTAINER=ft ${INCLUDES} -c $< -o $@

${BIN_STD}%.o:	${TEST_DIR}%.cpp
				@mkdir -p $(dir $@)
				${CC} ${CFLAGS} -D FT_CONTAINER=std ${INCLUDES} -c $< -o $@

all:			${OBJ_SRC} ${OBJ_FT} ${OBJ_STD}
				${CC} ${C_FLAGS} -D FT_CONTAINER=std ${INCLUDES} ${OBJ_SRC} ${OBJ_FT} -o ${NAME_FT}
				${CC} ${C_FLAGS} -D FT_CONTAINER=std ${INCLUDES} ${OBJ_SRC} ${OBJ_STD} -o ${NAME_STD}
				${CC} ${C_FLAGS} ./tester/compare_time.cpp -o compare_time
				@./${NAME_STD} ./std.res
				@./${NAME_FT} ./ft.res
				@./compare_time ./ft.res ./std.res

clean:
				rm -rf ${OBJ_SRC} ${OBJ_FT} ${OBJ_STD}

fclean:			clean
				rm -rf ${NAME_FT} ${NAME_STD} ${BIN_SRC} ${BIN_FT}  ${BIN_STD}
				rm -rf compare_time ./std.res ./ft.res

re:				fclean all

.phony:			all clean fclean re
