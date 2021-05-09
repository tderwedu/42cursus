# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 17:04:23 by tderwedu          #+#    #+#              #
#    Updated: 2021/05/09 10:39:22 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

LIBMLX		=	-lmlx
MLX			=	./mlx/mlx_linux/libmlx.a
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
				./parsing/ft_parse_utils.c\
				./raycasting/draw/doors.c\
				./raycasting/draw/floor_ceil.c\
				./raycasting/draw/raycasting.c\
				./raycasting/draw/arms.c\
				./raycasting/draw/sprites.c\
				./raycasting/draw/skybox.c\
				./raycasting/mlx_init.c\
				./raycasting/bonus/mini_map_bonus.c\
				./raycasting/bonus/sprites_bonus.c\
				./raycasting/bonus/ptr_map_bonus.c\
				./raycasting/bonus/light_effect_bonus.c\
				./raycasting/utils/free.c\
				./raycasting/utils/set_tex_yx_loop.c\
				./raycasting/utils/set_tex_xy_loop.c\
				./raycasting/utils/error_exit.c\
				./raycasting/new_frame.c\
				./raycasting/events/mouse.c\
				./raycasting/events/key_release.c\
				./raycasting/events/key_press.c

# CFLAGS		=	-O3 -fsanitize=address
# SRC			=	./raycasting_old.c

OBJ			=	${SRC:.c=.o}

SRCDIR		=	src/
INCDIR		=	-I$(MLXDIR) -I/usr/include -I${LFTDIR}/include -I./include
OBJDIR	=		bin/


.c.o:		
			${CC} ${CFLAGS} ${INCDIR} -c $< -o $@

all:		${NAME}

$(NAME):	${OBJ}
			${MAKE} -s -w -C ${LFTDIR}
			${CC} ${CFLAGS} ${OBJ} ${LFTFLAGS} ${LDFLAGS} -o ${NAME}
			# ${CC} ${CFLAGS} ${OBJ} ${LFTFLAGS} -o ${NAME}
			# ${CC} ${CFLAGS} ${OBJ} ${LDFLAGS} -o ${NAME}

clean:
			rm -f ${OBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.phony:		re fclean clean

