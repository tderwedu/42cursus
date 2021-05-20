/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_define.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 09:02:18 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/19 11:13:46 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINE_H
# define CUB3D_DEFINE_H

# include <stdint.h>

# define XK_LATIN1
# define XK_MISCELLANY
# include <X11/keysymdef.h>
# include <X11/X.h>

# define DEBUG		0

# ifndef KEYBOARD
#  define KEYBOARD	1
# endif

/*
**	Keyboard's mapping
**
** # define K_W_FWD		XK_w
** # define K_W_BWK		XK_s
** # define K_T_L		XK_a
** # define K_T_R		XK_d
** # define K_S_L		XK_q
** # define K_S_R		XK_e
** # define K_ESC		XK_Escape
** # define K_CTRL		XK_Control_L
** # define K_SPACE		XK_space
** # define K_ESC		XK_Escape
** # define K_CTRL		XK_Control_L
** # define K_SPACE		XK_space
** # define BUT_L		0x1
*/

# define A_T_L		0xff51
# define A_T_R		0xff53
# define A_W_FWD	0xff52
# define A_W_BWK	0xff54

# if KEYBOARD == 1

/*
**	Linux QWERTY
*/

#  define K_T_L		0x0071
#  define K_T_R		0x0065
#  define K_W_FWD	0x0077
#  define K_W_BWK	0x0073
#  define K_S_R		0x0064
#  define K_S_L		0x0061
#  define K_ESC		0xff1b
#  define K_CTRL	0xffe3
#  define K_SPACE	0x0020
#  define BUT_L		0x0001

/*
**	Linux AZERTY
*/

# elif KEYBOARD == 2

#  define K_T_L		0x0061
#  define K_T_R		0x0065
#  define K_W_FWD	0x007a
#  define K_W_BWK	0x0073
#  define K_S_R		0x0064
#  define K_S_L		0x0071
#  define K_ESC		0xff1b
#  define K_CTRL	0xffe3
#  define K_SPACE	0x0020
#  define BUT_L		0x0001

# endif

/*
**	Mac QWERTY
** # define K_T_L		123
** # define K_T_R		124
** # define K_W_FWD	13
** # define K_W_BWK	1
** # define K_S_R	2
** # define K_S_L	0
** # define K_ESC		0xff1b
** # define K_CTRL		0xffe3
** # define K_SPACE		0x0020
** # define BUT_L		0x1
*/

# ifndef BONUS
#  define BONUS	0
# endif

/*
**	cam's behaviour
*/

# define FOV			75
# define WALK_SPEED 	0.125
# define TURN_SPEED 	25

# ifndef M_PI
#  define M_PI			3.14159265358979323846
# endif

# ifndef M_PI_2
#  define M_PI_2		1.57079632679489661923
# endif

# define KFC_SPEED 		0.03125
# define DOOR_SPEED		0.0869140625

# define S_BROKEN		"./textures/barrel_broken.xpm"
# define TEX_KNIFE		"./textures/knife_free.xpm"
# define KFC_Y000		"./textures/chick_y000.xpm"
# define KFC_Y045		"./textures/chick_y045.xpm"
# define KFC_Y090		"./textures/chick_y090.xpm"
# define KFC_Y135		"./textures/chick_y135.xpm"
# define KFC_Y180		"./textures/chick_y180.xpm"
# define KFC_Y225		"./textures/chick_y225.xpm"
# define KFC_Y270		"./textures/chick_y270.xpm"
# define KFC_Y315		"./textures/chick_y315.xpm"
# define KFC_DEAD		"./textures/kfc_bucket.xpm"
# define TEX_DOOR		"./textures/door_wood.xpm"
# define TEX_SECRET		"./textures/wall_secret.xpm"
# define TEX_HEART		"./textures/heart.xpm"
# define TEX_ARM_0		"./textures/knife_hand.xpm"
# define TEX_ARM_1		"./textures/knife_strike.xpm"

# define RGB_FLOOR		0x00C6BAAF
# define RGB_WALL		0x001D2526
# define RGB_SPRITE		0x00685748
# define RGB_KNIFE		0x001D2526
# define RGB_DOOR		0x00945D45
# define RGB_KFC		0x00B75400
# define RGB_EMPTY		0x00262D2F
# define RGB_PLAYER		0x00FFFFFF
# define RGB_EDGE		0x00880015

/*
**	Used to parse the '.cub' file
*/

# define VALID_DIR		"NWSE"
# if BONUS
#  define VALID_NBR		"0123456"
# else
#  define VALID_NBR		"012"
# endif

# define FLAG_R			0x01
# define FLAG_C			0x02
# define FLAG_F			0x04
# define FLAG_SP		0x08
# define FLAG_NO		0x10
# define FLAG_SO		0x20
# define FLAG_WE		0x40
# define FLAG_EA		0x80
# define FLAG_ALL		0xFF
# define FLAG_D			0x100

typedef uint32_t		t_u32;
typedef int32_t			t_i32;
typedef uint64_t		t_u64;

#endif
