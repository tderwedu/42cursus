/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:22:36 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/06 12:24:39 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <mlx.h>

# define FOV	75

# define mapWidth		24
# define mapHeight		24
# define screenWidth		640
# define screenHeight	480

# define RED		0x00FF0000
# define GREEN	0x0000FF00
# define BLUE	0x000000FF
# define WHITE	0x00FFFFFF
# define YELLOW	0x00FFFF00

# define WALK_SPEED 0.25
# define TURN_SPEED 25

# define XK_LATIN1
# define XK_MISCELLANY
# include <X11/keysymdef.h>
# include <X11/X.h>

# define KEY_WALK_FORWARD		XK_w
# define KEY_WALK_BACKWARD		XK_s
# define KEY_TURN_LEFT			XK_a
# define KEY_TURN_RIGHT			XK_d
# define KEY_STRAFE_LEFT		XK_q
# define KEY_STRAFE_RIGHT		XK_e
# define KEY_ESCAPE				XK_Escape


typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}				t_img;

typedef struct	s_mlx
{
	int		width;
	int		height;
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct	s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_player;


typedef struct	s_tex
{
	int		*img;
	char	*addr;
	int		width;
    int		height;
}				t_tex;


typedef struct	s_vars
{
	t_mlx		*mlx;
	t_player	*player;
	t_img		*img;
	t_tex		tex[4];
	int			hcol[2];
	t_tex		htex[2];
}				t_vars;


#endif
