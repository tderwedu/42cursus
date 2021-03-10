# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 13:14:08 by tderwedu          #+#    #+#              #
#    Updated: 2021/03/10 20:54:38 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CFLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

LIB		=	ar

LFLAGS	=	-rcs

SRC		=	./printf/ft_printf.c\
			./printf/ft_vdprintf.c\
			./printf/ft_tmp2buff.c\
			./printf/ft_format_error.c\
			./printf/ft_format_parser.c\
			./printf/ft_format_handler.c\
			./printf/ft_format_str.c\
			./printf/ft_format_chr.c\
			./printf/ft_format_int_1.c\
			./printf/ft_format_int_2.c\
			./printf/ft_format_int2str.c\
			./printf/ft_format_grisu.c\
			./printf/ft_format_double_1.c\
			./printf/ft_format_double_2.c\
			./printf/ft_format_double_3.c\
			./grisu/ft_double2fp.c\
			./grisu/ft_fp2double.c\
			./grisu/ft_double2int_64.c\
			./grisu/ft_normalize_fp.c\
			./grisu/ft_multiply_fp.c\
			./grisu/ft_minus_fp.c\
			./grisu/ft_kcomp.c\
			./grisu/ft_cachedpower.c\
			./grisu/ft_digit_gen_no_div.c\
			./libft/ft_newvec.c\
			./libft/ft_growvec.c\
			./libft/ft_freevec.c\
			./libft/ft_memcpy.c\
			./libft/ft_strlen.c\
			./libft/ft_strrchr.c\
			./libft/ft_ceil.c\
			./libft/ft_floor.c\
			./libft/ft_unicode2utf8.c\
			./libft/ft_wcharsize.c\
			./libft/ft_wstrlen.c\
			./libft/ft_wstr2vec.c

OBJ		=	${SRC:.c=.o}

.c.o:		${cc} ${CFLAGS}	-I include -c $< -o ${<:.c=.o}

$(NAME):	${OBJ}
			${LIB} ${LFLAGS} ${NAME} ${OBJ}

all:		${NAME}

bonus:		${NAME}
			touch bonus

clean:		
			rm -f ${OBJ}

fclean:		clean
			rm -f ${NAME} bonus

re:			fclean all

.phony:		all fclean clean
