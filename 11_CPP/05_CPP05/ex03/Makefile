# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 18:37:14 by tderwedu          #+#    #+#              #
#    Updated: 2021/10/19 11:44:14 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #

NAME	= ex03

SRC		= ./Bureaucrat.cpp\
		  ./Form.cpp\
		  ./ShrubberyCreationForm.cpp\
		  ./RobotomyRequestForm.cpp\
		  ./PresidentialPardonForm.cpp\
		  ./Intern.cpp\
		  ./main.cpp

CC		= clang++
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address

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

