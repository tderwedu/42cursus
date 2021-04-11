# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 17:04:23 by tderwedu          #+#    #+#              #
#    Updated: 2021/04/11 15:06:40 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

LIBMLX		=	-lmlx
MLX			=	./mlx_linux/libmlx.a
MLXDIR		=	$(dir ${MLX})
LDFLAGS 	=	-L ${MLXDIR} ${LIBMLX} -lXext -lX11 -lm

LFTDIR		=	./Libft
LFTFLAGS	=	-L ${LFTDIR} -lft

CC			=	gcc
CFLAGS		=	-O3 -Wall -Werror -Wextra -fsanitize=address

SRC			=	./main.c\
				./parsing/ft_parse_file.c\
				./parsing/ft_get_data.c\
				./parsing/ft_get_map.c\
				./parsing/ft_check_boundary.c\
				./parsing/ft_data.c\
				./parsing/ft_error.c\
				./parsing/ft_parse_utils.c

OBJ			=	${SRC:.c=.o}

SRCDIR		=	src/
INCDIR		=	-I$(MLXDIR) -I/usr/include -I${LFTDIR}/include -I./include
OBJDIR	=		bin/


.c.o:		
			${CC} ${CFLAGS} ${INCDIR} -c $< -o $@

all:		${NAME}

$(NAME):	${OBJ}
			${MAKE} -s -w -C ${LFTDIR}
			${CC} ${CFLAGS} ${OBJ} ${LFTFLAGS} -o ${NAME}
			# ${CC} ${CFLAGS} ${OBJ} ${LDFLAGS} -o ${NAME}

clean:
			rm -f ${OBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.phony:		re fclean clean

