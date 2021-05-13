/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_define.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 09:02:18 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/13 11:51:43 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINE_H
# define CUB3D_DEFINE_H

# include <stdint.h>

# define XK_LATIN1
# define XK_MISCELLANY
# include <X11/keysymdef.h>
# include <X11/X.h>

# define DEBUG			1
# define BONUS			1
# define SHADOW			0

# ifndef M_PI
#  define M_PI			3.14159265358979323846
# endif

# ifndef M_PI_2
#  define M_PI_2		1.57079632679489661923
# endif

/*
**	cam's behaviour
*/

# define FOV			75
# define WALK_SPEED 	0.125
# define TURN_SPEED 	25

# if BONUS

#  define KFC_SPEED 		0.03125
#  define DOOR_SPEED		0.0869140625

#  define S_BROKEN	"./textures/barrel_broken.xpm"
#  define TEX_KNIFE	"./textures/knife_free.xpm"
#  define KFC_Y000	"./textures/chick_y000.xpm"
#  define KFC_Y045	"./textures/chick_y045.xpm"
#  define KFC_Y090	"./textures/chick_y090.xpm"
#  define KFC_Y135	"./textures/chick_y135.xpm"
#  define KFC_Y180	"./textures/chick_y180.xpm"
#  define KFC_Y225	"./textures/chick_y225.xpm"
#  define KFC_Y270	"./textures/chick_y270.xpm"
#  define KFC_Y315	"./textures/chick_y315.xpm"
#  define KFC_DEAD	"./textures/kfc_bucket.xpm"
#  define TEX_DOOR	"./textures/door_wood.xpm"
#  define TEX_ARM_0	"./textures/knife_hand.xpm"
#  define TEX_ARM_1	"./textures/knife_strike.xpm"

#  define RGB_FLOOR		0x00FDAE80
#  define RGB_WALL		0x00721A16
#  define RGB_SPRITE	0x00945D45
#  define RGB_KNIFE		0x00945D45
#  define RGB_DOOR		0x00945D45
#  define RGB_KFC		0x00945D45
#  define RGB_EMPTY		0x002C0C0B
#  define RGB_PLAYER	0x000FFFFFF
#  define RGB_EDGE		0x00000000
#  define SQ			6

# endif

/*
**	Keyboard's mapping
*/

# define KEY_WALK_FWD	XK_w
# define KEY_WALK_BWK	XK_s
# define KEY_TURN_L		XK_a
# define KEY_TURN_R		XK_d
# define KEY_STRAFE_L	XK_q
# define KEY_STRAFE_R	XK_e
# define KEY_ESCAPE		XK_Escape
# define KEY_CTRL		XK_Control_L
# define KEY_SPACE		XK_space
# define BUTTON_LEFT	0x1

# define F_WALL				1.5

/*
**	Used to parse the '.cub' file
*/

# define VALID_DIR			"NWSE"
# if BONUS
#  define VALID_NBR			"0123456"
# else
#  define VALID_NBR			"012"
# endif

# define FLAG_R				0x01
# define FLAG_C				0x02
# define FLAG_F				0x04
# define FLAG_SP			0x08
# define FLAG_NO			0x10
# define FLAG_SO			0x20
# define FLAG_WE			0x40
# define FLAG_EA			0x80
# define FLAG_ALL			0xFF
# define FLAG_D				0x100

typedef uint32_t	t_u32;
typedef uint64_t	t_u64;

#endif
