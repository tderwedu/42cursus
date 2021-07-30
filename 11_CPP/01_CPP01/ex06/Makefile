# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/28 09:22:15 by tderwedu          #+#    #+#              #
#    Updated: 2021/07/30 12:28:41 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #

NAME	=  karenFilter

SRC		= ./Karen.cpp\
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

clean:
			rm -f ${OBJ}

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

.phony:		all clean fclean re
