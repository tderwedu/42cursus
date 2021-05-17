# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 17:04:23 by tderwedu          #+#    #+#              #
#    Updated: 2021/05/17 16:43:52 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

MLX_LiB		=	./lib/mlx_linux/libmlx.a
MLX_DIR		=	$(dir ${MLX_LiB})
MLX_FLAG 	=	-L ${MLX_DIR} -lmlx -L /usr/include -lXext -lX11 -lm

LIBFT_LIB	=	./lib/libft/libft.a
LIBFT_DIR	=	$(dir ${LIBFT_LIB})
LIBFT_FLAG	=	-L ${LIBFT_DIR} -lft

CC			=	gcc
CC_FLAGS	=	-Wall -Werror -Wextra -fsanitize=address

LIBS		=	${LIBFT_FLAG} ${LIBFT_FLAG}
INCL_DIR	=	-I ${MLX_DIR} -I /usr/include -I ${LFT_DIR}/include -I ./include

OBJ_DIR		=	bin/

SRC			=	./src/parsing/ft_error.c\
				./src/parsing/ft_check_map_line.c\
				./src/parsing/ft_parse_file.c\
				./src/parsing/ft_get_map.c\
				./src/parsing/ft_parse_utils.c\
				./src/parsing/ft_check_boundary.c\
				./src/parsing/ft_init_free.c\
				./src/parsing/ft_get_data.c\
				./src/raycasting/mlx_init_struct.c\
				./src/raycasting/draw/floor_ceil.c\
				./src/raycasting/draw/raycasting.c\
				./src/raycasting/draw/sprites.c\
				./src/raycasting/bonus/mouse_bonus.c\
				./src/raycasting/bonus/get_tex_bonus.c\
				./src/raycasting/bonus/check_4_stuff_bonus.c\
				./src/raycasting/bonus/life_bar_bonus.c\
				./src/raycasting/bonus/arm_bonus.c\
				./src/raycasting/bonus/ptr_map_bonus.c\
				./src/raycasting/bonus/kfc_bonus.c\
				./src/raycasting/bonus/mini_map_bonus_2.c\
				./src/raycasting/bonus/door_bonus.c\
				./src/raycasting/bonus/mini_map_bonus_1.c\
				./src/raycasting/bonus/skybox_bonus.c\
				./src/raycasting/utils/set_tex_yx_loop.c\
				./src/raycasting/utils/rc_free.c\
				./src/raycasting/utils/bmp_save.c\
				./src/raycasting/utils/set_tex_xy_loop.c\
				./src/raycasting/utils/get_tex.c\
				./src/raycasting/utils/error_exit.c\
				./src/raycasting/new_frame.c\
				./src/raycasting/events/key_press_1.c\
				./src/raycasting/events/key_release.c\
				./src/raycasting/events/key_press_2.c\
				./src/raycasting/set_mlx.c\
				./main.c

OBJ			=	${SRC:.c=.o}

.c.o:		
			${CC} ${CC_FLAGS} ${INC_DIR} -c $< -o $@

all:		${NAME}

$(NAME):	${OBJ}
			${MAKE} -s -w -C ${MLX_DIR}
			${MAKE} -s -w -C ${LFT_DIR}
			${CC} ${CFLAGS} ${OBJ} ${LIBS} -o ${NAME}

clean:
			rm -f ${OBJ} save.bmp

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.phony:		re fclean clean

