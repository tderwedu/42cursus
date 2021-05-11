/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 09:04:17 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/11 12:01:25 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include "libft.h"

enum			e_tex
{
	NO,
	WE,
	SO,
	EA,
	D,
	F,
	C,
	S,
	S_broken,
	tex_knife,
	kfc_y000,
	kfc_y045,
	kfc_y090,
	kfc_y135,
	kfc_y180,
	kfc_y225,
	kfc_y270,
	kfc_y315,
	kfc_dead,
	tex_door,
	arm_0,
	arm_1
};

enum			e_map
{
	empty,
	wall,
	sprite,
	knife,
	kfc,
	door,
	secret,
};

typedef struct s_cam
{
	double	x_pos;
	double	y_pos;
	double	z_pos;
	double	pitch;
	double	height_pitch;
	double	x_dir;
	double	y_dir;
	double	x_plane;
	double	y_plane;
}			t_cam;

typedef struct s_tex
{
	int		*img;
	t_u32	*addr;
	int		width;
	int		height;
	int		w_mask;
	int		h_mask;
	int		bpp;
	int		sl;
	int		endia;
}			t_tex;

typedef struct s_img
{
	void	*img;
	t_u32	*addr;
	int		width;
	int		height;
	int		bpp;
	int		sl;
	int		endia;
}			t_img;

typedef struct s_spr
{
	int				id;
	int				dead;
	int				show;
	double			y_map;
	double			x_map;
	double			y_dir;
	double			x_dir;
	double			y_tr;
	double			x_tr;
	double			dist;
	t_tex			*tex;
	struct s_spr	*next;
}				t_spr;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	int			width;
	int			width_2;
	int			height;
	int			height_2;
	double		fov_2;
	double		ratio;
	int			**map;
	void		***ptr;
	int			y_max;
	int			x_max;
	t_cam		*cam;
	t_img		*img;
	t_tex		tex[22];
	t_u32		rgb[2];
	double		*z_buff;
	int			nb_spr;
	int			strike;
	t_spr		*tab;
	t_spr		*lst;
	int			show_left;
	int			show_right;
	int			nb_TEX_DOOR;
	long		fps; 	// TODO: remove
	long		avg;	// TODO: remove
	long		count;	// TODO: remove
}				t_mlx;

typedef struct s_floor
{
	int			x;
	int			y;
	int			y_max;
	double		x_grid_step;
	double		y_grid_step;
	double		x_grid;
	double		y_grid;
	int			x_tex;
	int			y_tex;
	int			p;
	double		z_cam;
	double		row_dist;
}				t_floor;

typedef struct s_ray
{
	int			x;
	int			x_map;
	int			y_map;
	int			x_step;
	int			y_step;
	int			side;
	int			line_h;
	int			y_s;
	int			y_e;
	int			hit;
	int			x_tex;
	t_tex		*tex;
	double		pc_wall;
	double		pc_plane;
	double		x_r_dir;
	double		y_r_dir;
	double		x_dt_dist;
	double		y_dt_dist;
	double		w_dist;
	double		x_dist;
	double		y_dist;
}				t_ray;

typedef struct s_cub
{
	int			width;
	int			height;
	int			fd;
	int			flag;
	int			x_map;
	int			y_map;
	int			x_pos;
	int			y_pos;
	int			nb_spr;
	int			nb_TEX_DOOR;
	int			rgb[7];
	char		*tex[8];
	char		*ptr;
	char		*line;
	t_list		*first;
	t_list		*last;
	int			**map;
	char		dir;
}				t_cub;

typedef struct s_loop
{
	int			y;
	int			y_max;
	int			y_range;
	int			y_tex;
	int			y_tex_range;
	int			x;
	int			x_max;
	int			x_range;
	int			x_tex;
	int			x_tex_range;
	uint32_t	rgb;
}				t_loop;

typedef struct s_TEX_DOOR
{
	int			updated;
	double		angle;
	double		moving;
	double		dx;
	double		sin_leaf;
	double		y_leaf_1;
	double		y_leaf_2;
	double		y_1_min;
	double		y_1_max;
	double		y_2_min;
	double		y_2_max;
}				t_TEX_DOOR;

#endif
