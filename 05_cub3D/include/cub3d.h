/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:22:36 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/20 16:34:54 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <mlx.h>

# define XK_LATIN1
# define XK_MISCELLANY
# include <X11/keysymdef.h>
# include <X11/X.h>

# include "cub3d_error.h"

# define DEBUG			1
# define BONUS			1

# ifndef M_PI
#  define M_PI			3.14159265358979323846
# endif

/*
**	cam's behaviour
*/

# define FOV			75
# define WALK_SPEED 	0.25
# define TURN_SPEED 	25

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

# define F_WALL				1.5

/*
**	Used to parse the '.cub' file
*/

# define VALID_DIR			"NWSE"
# define VALID_NBR			"012"
# define FLAG_R				0x01
# define FLAG_C				0x02
# define FLAG_F				0x04
# define FLAG_SP			0x08
# define FLAG_NO			0x10
# define FLAG_SO			0x20
# define FLAG_WE			0x40
# define FLAG_EA			0x80
# define FLAG_ALL			0xFF

typedef uint32_t	t_u32;
typedef uint64_t	t_u64;

enum	e_tex
{
	NO,
	WE,
	SO,
	EA,
	F,
	C,
	S
};

typedef struct	s_cam
{
	double	x_pos;
	double	y_pos;
	double	x_dir;
	double	y_dir;
	double	x_plane;
	double	y_plane;
}				t_cam;

typedef struct	s_tex
{
	int		*img;
	t_u32	*addr;
	int		width;
	int		height;
	int		bpp;
	int		sl;
	int		endia;
}				t_tex;

typedef struct	s_img {
	void	*img;
	t_u32	*addr;
	int		width;
	int		height;
	int		bpp;
	int		sl;
	int		endia;
}				t_img;

typedef struct	s_spr_lst
{
	double				x_map;
	double				y_map;
	double				x_tr;
	double				y_tr;
	double				dist;
	t_tex				*tex;
	struct s_spr_lst	*next;	
}				t_spr_lst;

typedef struct s_spr_vars
{
	int		x_screen;
	int		spr_h;
	int		spr_w;
	int		y_s;
	int		y_e;
	int		x_s;
	int		x_e;
	int		x_tex;
	int		y_tex;
	int		tex_h;
	int		tex_w;
	int		y;
	t_u32	*src;
	t_u32	*dst;
}				t_spr_vars;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	double	fov;
	double	ratio;
	int		**map;
	int		y_max;
	int		x_max;
	t_cam	*cam;
	t_img	*img;
	t_tex	tex[7];
	int		rgb[7];
	double 	*z_buff;
	int		nb_spr;
	t_spr_lst	*tab;
	t_spr_lst	*lst;
}				t_mlx;

typedef struct s_scan
{
	int		x;
	int		y;
	int		y_max;
	double	x_grid_step;
	double	y_grid_step;
	double	x_grid;
	double	y_grid;
	int		x_tex;
	int		y_tex;
	double	factor;
}				t_scan;

typedef struct	s_ray
{
	int		x;
	int		x_map;
	int		y_map;
	int		x_step;
	int		y_step;
	int		side;
	int		line_h;
	int		y_s;
	int		y_e;
	int 	hit;
	double	pc_wall;
	double	pc_plane;
	double	x_r_dir;
	double	y_r_dir;
	double	x_dt_dist;
	double	y_dt_dist;
	double	w_dist;
	double	x_dist;
    double	y_dist;
}				t_ray;

typedef struct s_cub
{
	int		width;
	int		height;
	int		fd;
	int		flag;
	int		x_map;
	int		y_map;
	int		x_pos;
	int		y_pos;
	int		nb_spr;
	int		rgb[7];
	char	*tex[7];
	char	*ptr;
	char	*line;
	t_list	*first;
	t_list	*last;
	int		**map;
	char	dir;
}				t_cub;

/*
** 1: [parsing] ft_parse_file.c
*/

int				ft_get_data(t_cub *data, int argc, char **argv);
int				ft_parse_cubfile(t_cub *data);

/*
** 2: [parsing] ft_get_data.c
*/

int				ft_line_handler(t_cub *data);
int				ft_get_wall(t_cub *data, int i, int flag);
int				ft_get_pavement(t_cub *data, int i, int flag);
int				ft_get_resolution(t_cub *data);

/*
** 3: [parsing] ft_get_map.c
*/

int				ft_parse_map(t_cub *data, int empty);
int				ft_check_map_line(t_cub *data, int empty);
int				ft_create_map(t_cub *data);

/*
** 4: [parsing] ft_check_boundary.c
*/

int				ft_check_boundary_y(t_cub *data);
int				ft_check_boundary_x(t_cub *data);

/*
** [parsing] ft_parse_utils.c
*/

int				ft_get_int(char **ptr);
int32_t			ft_get_color(char *ptr);
void			ft_print_data(t_cub *data);
void			ft_print_map(t_cub *data);

/*
** [parsing] ft_error.c
*/

int				ft_error_arg(t_cub *data, char *str, char *arg);
int				ft_error_parser(t_cub *data, char *str);
int				ft_error_map(t_cub *data, char *str, int y_e, int x_e);

/*
** [parsing] ft_data.c
*/

void			ft_init_data(t_cub *data);
void			ft_free_data(t_cub *data);

/*
** [raycasting] rc_mlx_init.c
*/

int				rc_mlx_init(t_cub *data, t_mlx *mlx);
void			rc_set_cam(t_cub *data, t_cam *cam, double fov);
int				rc_get_wall_tex(t_cub *d, t_mlx *x, int i);
void			rc_rotate_wall_tex(t_tex *tex);
int				rc_spr_init(t_cub *data, t_mlx *mlx);

/*
** [raycasting] rc_error.c
*/

void			rc_free_mlx(t_mlx *mlx);
int				rc_error(t_mlx *mlx, char *str);
int				rc_error_data(t_cub *data,t_mlx *mlx, char *str);

/*
** [raycasting] rc_key_hooks.c
*/

int				rc_key_hooks(int keycode, t_mlx *mlx);
void			rc_walk(int keycode, t_mlx *mlx, t_cam *cam);
void			rc_strafe(int keycode, t_mlx *mlx, t_cam *cam);
void			rc_turn(int keycode, t_cam *cam);

/*
** [raycasting] rc_raycasting.c
*/

void			rc_new_frame(t_mlx *mlx);
int				rc_set_mlx(t_cub *data, int show_win);


/*
** [raycasting] rc_set_raycasting.c
*/

void			rc_raycasting(t_mlx *mlx, t_cam *cam);

/*
** [raycasting] rc_scanline.c
*/

void			rc_scanline(t_mlx *mlx);
void			rc_scanline_rgb(t_mlx *mlx, t_img *img, int type);
void			rc_scanline_tex(t_mlx *mlx, t_cam *cam, t_img *img, int type);

/*
** [raycasting] rc_sprites.c
*/

void			rc_sprite(t_mlx *mlx, t_img *img);
void			rc_sprite_update_lst(t_mlx *mlx, t_cam *cam);
void			rc_sprite_lst_add(t_mlx *mlx, t_spr_lst *new);

/*
** [raycasting] rc_mini_map.c
*/
void			rc_draw_square_16(t_img *img, int y, int x, t_u32 rgb);
void			rc_draw_mini_map(t_mlx *mlx, t_img *img);

#endif
