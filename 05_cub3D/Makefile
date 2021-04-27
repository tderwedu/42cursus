# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 17:04:23 by tderwedu          #+#    #+#              #
#    Updated: 2021/04/27 11:19:09 by tderwedu         ###   ########.fr        #
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
				./raycasting/rc_set_mlx.c\
				./raycasting/rc_error.c\
				./raycasting/rc_free.c\
				./raycasting/rc_ptr_map.c\
				./raycasting/rc_scanline.c\
				./raycasting/rc_skybox.c\
				./raycasting/rc_doors.c\
				./raycasting/rc_key_press.c\
				./raycasting/rc_key_release.c\
				./raycasting/rc_mouse_hook.c\
				./raycasting/rc_raycasting.c\
				./raycasting/rc_mlx_init.c\
				./raycasting/rc_sprites.c\
				./raycasting/rc_mmap.c

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

