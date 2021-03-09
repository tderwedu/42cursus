# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 15:57:49 by tderwedu          #+#    #+#              #
#    Updated: 2021/03/08 12:09:07 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CFLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

LIB		=	ar

LFLAGS	=	-rcs

SRC		= 	./ft_strchr.c\
			./ft_split.c\
			./ft_strtrim.c\
			./ft_bzero.c\
			./ft_strnstr.c\
			./ft_strmapi.c\
			./ft_isprint.c\
			./ft_atoi.c\
			./ft_strdup.c\
			./ft_tolower.c\
			./ft_toupper.c\
			./ft_substr.c\
			./ft_memchr.c\
			./ft_putnbr_fd.c\
			./ft_strlcpy.c\
			./ft_itoa.c\
			./ft_memset.c\
			./ft_calloc.c\
			./ft_strlen.c\
			./ft_putchar_fd.c\
			./ft_isascii.c\
			./ft_memccpy.c\
			./ft_strlcat.c\
			./ft_putendl_fd.c\
			./ft_memcmp.c\
			./ft_isdigit.c\
			./ft_strrchr.c\
			./ft_putstr_fd.c\
			./ft_isalpha.c\
			./ft_strncmp.c\
			./ft_isalnum.c\
			./ft_memcpy.c\
			./ft_memmove.c\
			./ft_strjoin.c\

SRC_B	= ./ft_lstadd_back.c \
			./ft_lstadd_front.c \
			./ft_lstclear.c \
			./ft_lstdelone.c \
			./ft_lstiter.c \
			./ft_lstlast.c \
			./ft_lstmap.c \
			./ft_lstnew.c \
			./ft_lstsize.c \

OBJ		= 	${SRC:.c=.o}

OBJ_B	=	$(SRC_B:.c=.o)

.c.o:
			${CC} ${CFLAGS} -I . -c $< -o ${<:.c=.o}

$(NAME):	${OBJ}
			${LIB} ${LFLAGS} ${NAME} ${OBJ}

bonus:		$(OBJ) $(OBJ_B)
			${LIB} ${LFLAGS} ${NAME} ${OBJ} ${OBJ_B}
			touch bonus

all:		${NAME}

clean:
			rm -f ${OBJ} ${OBJ_B}

fclean:		clean
			rm -f ${NAME} bonus

re:			fclean all

.phony:		all clean fclean re

