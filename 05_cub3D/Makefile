# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 17:04:23 by tderwedu          #+#    #+#              #
#    Updated: 2021/03/29 12:02:43 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

LIBMLX	=	-lmlx
MLX		=	./mlx_linux/libmlx.a
MLXDIR	=	$(dir ${MLX})
LDFLAGS =	-L ${MLXDIR} ${LIBMLX} -lXext -lX11 -lm

CC		=	gcc
CFLAGS	=	-O3 #-Wall -Werror -Wextra

SRC		=	main.c
OBJ		=	${SRC:.c=.o}

SRCDIR	=	src/
INCDIR	=	-I$(MLXDIR) -I/usr/include
OBJDIR	=	bin/


.c.o:		
			${CC} ${CFLAGS} ${INCDIR} -c $< -o $@

$(NAME):	${OBJ}
			${CC} ${CFLAGS} ${OBJ} ${LDFLAGS} -o ${NAME}

debug :
	@echo "SRC $(SRC)"
	@echo "OBJ $(OBJ)"
	@echo "CFLAGS $(CFLAGS)"
	@echo "MLX $(MLX)"
	@echo "MLXDIR $(MLXDIR)"
	@echo "LDFLAGS $(LDFLAGS)"


