# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 17:04:23 by tderwedu          #+#    #+#              #
#    Updated: 2021/05/19 11:28:44 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

# MAPPING:
# 1 : Linux QWERTY
# 2 : Linux AZERTY
MAPPING		=	1
VERBOSE		=	0

MLX			=	./lib/mlx_linux/libmlx.a
MLX_DIR		=	$(dir ${MLX})
MLX_FLAG 	=	-L ${MLX_DIR} -lmlx -L /usr/include -lXext -lX11 -lm

LIBFT		=	./lib/libft/libft.a
LIBFT_DIR	=	$(dir ${LIBFT})
LIBFT_FLAG	=	-L ${LIBFT_DIR} -lft

CC			=	gcc
CC_FLAGS	=	-Wall -Werror -Wextra

LIBS		=	 ${LIBFT_FLAG} ${MLX_FLAG}
INCL_DIR	=	-I ${MLX_DIR} -I /usr/include -I ${LIBFT_DIR}include -I ./include

OBJ_DIR		=	bin/
OBJ_DIR_B	=	bin_b/
SRC_DIR		=	src/
SRC			=	./src/parsing/ft_error.c\
				./src/parsing/ft_check_map_line.c\
				./src/parsing/ft_parse_file.c\
				./src/parsing/ft_get_map.c\
				./src/parsing/ft_parse_utils.c\
				./src/parsing/ft_check_boundary.c\
				./src/parsing/ft_init_free.c\
				./src/parsing/ft_get_data.c\
				./src/raycasting/set_mlx.c\
				./src/raycasting/mlx_init_struct.c\
				./src/raycasting/new_frame.c\
				./src/raycasting/bonus/check_4_stuff_bonus.c\
				./src/raycasting/bonus/mouse_bonus.c\
				./src/raycasting/bonus/get_tex_bonus.c\
				./src/raycasting/bonus/life_bar_bonus.c\
				./src/raycasting/bonus/arm_bonus.c\
				./src/raycasting/bonus/ptr_map_bonus.c\
				./src/raycasting/bonus/kfc_bonus.c\
				./src/raycasting/bonus/mini_map_bonus_2.c\
				./src/raycasting/bonus/door_bonus.c\
				./src/raycasting/bonus/mini_map_bonus_1.c\
				./src/raycasting/bonus/skybox_bonus.c\
				./src/raycasting/draw/floor_ceil.c\
				./src/raycasting/draw/raycasting.c\
				./src/raycasting/draw/sprites.c\
				./src/raycasting/utils/set_tex_yx_loop.c\
				./src/raycasting/utils/rc_free.c\
				./src/raycasting/utils/bmp_save.c\
				./src/raycasting/utils/set_tex_xy_loop.c\
				./src/raycasting/utils/get_tex.c\
				./src/raycasting/utils/error_exit.c\
				./src/raycasting/events/key_press_1.c\
				./src/raycasting/events/key_release.c\
				./src/raycasting/events/key_press_2.c\
				./src/main.c

OBJ			=	$(subst ${SRC_DIR},${OBJ_DIR}, ${SRC:.c=.o})
OBJ_B		=	$(subst ${SRC_DIR},${OBJ_DIR_B}, ${SRC:.c=.o})
KEYBOARD	=	-D KEYBOARD=${MAPPING}

ifeq ($(VERBOSE), 0)
	QUIET = > /dev/null 2>&1
else
	QUIET = 2>&1
endif

all:			${NAME}

${OBJ_DIR}%.o:	${SRC_DIR}%.c
				@printf "Compiling $<\n"
				@mkdir -p $(dir $@)
				@${CC} ${CC_FLAGS} -D BONUS=0 ${KEYBOARD} ${INCL_DIR} -c $< -o $@

${OBJ_DIR_B}%.o:	${SRC_DIR}%.c
				@printf "Compiling $<\n"
				@mkdir -p $(dir $@)
				@${CC} ${CC_FLAGS} -D BONUS=1 ${KEYBOARD} ${INCL_DIR} -c $< -o $@

$(MLX):
				@printf "Compiling the miniLibX ...\n"
				@${MAKE} -s -C ${MLX_DIR} ${QUIET}
				@printf "\tDone!\n"

$(LIBFT):
				@printf "Compiling the libft ...\n"
				@${MAKE} -s -C ${LIBFT_DIR} ${QUIET}
				@printf "\tDone!\n"

$(NAME):		${LIBFT} ${MLX} ${OBJ}
				@printf "Linking  object files ...\n"
				@${CC} ${CC_FLAGS} ${OBJ} ${LIBS} -o ${NAME}
				@printf "\tDone!\n"

bonus:			${LIBFT} ${MLX} ${OBJ_B}
				@printf "Linking  object files ...\n"
				@${CC} ${CC_FLAGS} ${OBJ_B} ${LIBS} -o ${NAME}
				@touch bonus
				@printf "\tDone!\n"

clean:
				@printf "Removing object files\n"
				@rm -f ${OBJ} ${OBJ_B} save.bmp bonus

fclean:			clean
				@printf "Removing cubD and binary directories\n"
				@rm -f ${NAME}
				@rm -rf ${OBJ_DIR} ${OBJ_DIR_B}

lclean:
				@printf "Removing libraries' object files\n"
				@${MAKE} -s -C ${MLX_DIR} clean
				@${MAKE} -s -C ${LIBFT_DIR}  fclean

aclean:			fclean lclean

re:				fclean all

.phony:			re clean fclean aclean

