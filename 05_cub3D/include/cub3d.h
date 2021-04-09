/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:22:36 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/09 17:41:33 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <mlx.h>
# include "cub3d_error.h"

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

# define VALID_DIR				"NWSE"
# define VALID_NBR				"012"

typedef struct		s_color
{
	uint32_t	a;
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
}					t_color;

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
	int		bpp;
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


#define FLAG_R		0x01
#define FLAG_C		0x02
#define FLAG_F		0x04
#define FLAG_SP		0x08
#define FLAG_NO		0x10
#define FLAG_SO		0x20
#define FLAG_WE		0x40
#define FLAG_EA		0x80
#define FLAG_ALL	0xFF

typedef struct s_cub
{
	int		width;
	int		height;
	int		floor;
	int		ceil;
	char	*tex_no;
	char	*tex_so;
	char	*tex_we;
	char	*tex_ea;
	char	*sprite;
	char	*line;
	char	*ptr;
	int		fd;
	int		flag;
	int		**map;
	t_list	*first;
	t_list	*last;
	int		x_map;
	int		y_map;
	int		x_pos;
	int		y_pos;
	char	dir;
}				t_cub;

/*
** [parsing] ft_data_parse.c
*/

int				ft_data_parse(t_cub *data);
int				ft_get_resolution(t_cub	*data);
int				ft_get_pavement(t_cub *data, int *rgb, int flag);
int				ft_get_tex_path(t_cub *data, char **path, int flag);

/*
** [parsing] ft_data_check.c
*/

int				ft_check_map_closure_y(t_cub *data);
int				ft_check_map_closure_x(t_cub *data);

/*
** [parsing] ft_data_get.c
*/

int				ft_map_parse(t_cub* data);
int				ft_map_check_line(t_cub* data);
int				ft_map_create(t_cub* data);


/*
** [parsing] ft_parse_file.c
*/

int				ft_parse_cubfile(t_cub	*data);

/*
** [parsing] ft_parse_utils.c
*/

int				ft_get_int(char **ptr);
int32_t			ft_get_color(char *ptr);
void			ft_print_data(t_cub	*data);
void			ft_print_map(t_cub	*data);
int				ft_error_parser(t_cub *data, char *str);
int				ft_error_map(t_cub *data, char *str, int y_e, int x_e);

/*
** [parsing] ft_strucut_cub.c
*/

void			ft_init_cub_struct(t_cub *data);
void			ft_free_cub_struct(t_cub *data);

#endif
