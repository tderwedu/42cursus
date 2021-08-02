# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 10:17:28 by tderwedu          #+#    #+#              #
#    Updated: 2021/08/02 18:26:47 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #

NAME	= claptrap

SRC		= ./ClapTrap.cpp\
		  ./ScavTrap.cpp\
		  ./FragTrap.cpp\
		  ./DiamondTrap.cpp\
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
			./$(NAME)

clean:
			rm -f ${OBJ}

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.phony:		all run clean fclean re
