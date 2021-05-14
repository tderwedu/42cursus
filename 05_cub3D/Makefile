# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 17:04:23 by tderwedu          #+#    #+#              #
#    Updated: 2021/05/14 18:57:53 by tderwedu         ###   ########.fr        #
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
SRC			=	./parsing/ft_error.c\
				./parsing/ft_check_map_line.c\
				./parsing/ft_parse_file.c\
				./parsing/ft_get_map.c\
				./parsing/ft_data.c\
				./parsing/ft_parse_utils.c\
				./parsing/ft_check_boundary.c\
				./parsing/ft_get_data.c\
				./raycasting/mlx_init_struct.c\
				./raycasting/draw/arm_bonus.c\
				./raycasting/draw/floor_ceil.c\
				./raycasting/draw/raycasting.c\
				./raycasting/draw/door_bonus.c\
				./raycasting/draw/sprites.c\
				./raycasting/bonus/life_bar_bonus.c\
				./raycasting/draw/skybox_bonus.c\
				./raycasting/bonus/ptr_map_bonus.c\
				./raycasting/bonus/kfc_bonus.c\
				./raycasting/bonus/mini_map_bonus_2.c\
				./raycasting/bonus/mini_map_bonus_1.c\
				./raycasting/utils/rc_free.c\
				./raycasting/utils/set_tex_yx_loop.c\
				./raycasting/utils/get_tex_bonus.c\
				./raycasting/utils/check_4_stuff.c\
				./raycasting/utils/set_tex_xy_loop.c\
				./raycasting/utils/get_tex.c\
				./raycasting/utils/error_exit.c\
				./raycasting/new_frame.c\
				./raycasting/events/mouse.c\
				./raycasting/events/key_press_1.c\
				./raycasting/events/key_release.c\
				./raycasting/events/key_press_2.c\
				./raycasting/set_mlx.c\
				./main.c

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

