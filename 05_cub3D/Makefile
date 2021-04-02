# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 17:04:23 by tderwedu          #+#    #+#              #
#    Updated: 2021/04/02 21:05:16 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

LIBMLX	=	-lmlx
MLX		=	./mlx_linux/libmlx.a
MLXDIR	=	$(dir ${MLX})
LDFLAGS =	-L ${MLXDIR} ${LIBMLX} -lXext -lX11 -lm

CC		=	gcc
CFLAGS	=	-O3 #-Wall -Werror -Wextra

SRC		=	raycasting.c
OBJ		=	${SRC:.c=.o}

SRCDIR	=	src/
INCDIR	=	-I$(MLXDIR) -I/usr/include
OBJDIR	=	bin/


.c.o:		
			${CC} ${CFLAGS} ${INCDIR} -c $< -o $@

$(NAME):	${OBJ}
			${CC} ${CFLAGS} ${OBJ} ${LDFLAGS} -o ${NAME}

clean:
			rm -f ${OBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.phony:		re fclean clean

