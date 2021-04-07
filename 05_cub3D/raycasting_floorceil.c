/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 21:57:56 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/05 16:33:14 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <mlx.h>

#define FOV	75

#define mapWidth		24
#define mapHeight		24
#define screenWidth		640
#define screenHeight	480

#define RED		0x00FF0000
#define GREEN	0x0000FF00
#define BLUE	0x000000FF
#define WHITE	0x00FFFFFF
#define YELLOW	0x00FFFF00

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
	t_tex		htex[2];
}				t_vars;

int worldMap[mapHeight][mapWidth] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int		ft_darker_color(int color)
{
	return ((color >> 1) & 0x7F7F7F);
}

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	ft_draw_vline(t_img *img, int x, int y_s, int y_e, int color)
{
	char	*dst;

	while (y_s <= y_e)
	{
		dst = img->addr + (y_s * img->ll + x * (img->bpp / 8));
		*(unsigned int*)dst = color;
		y_s++;
	}
}

void	ft_horizontalscanline(t_vars *vars)
{
	t_mlx		*mlx;
	t_player	*player;
	t_img		*img;
	t_tex		tex_floor;
	t_tex		tex_ceil;

	mlx = vars->mlx;
	player = vars->player;
	img = vars->img;
	tex_floor = vars->htex[0];
	tex_ceil = vars->htex[1];

	int		p;
	int		x;
	int		y;
	int		h;
	int		cell_x;
	int		cell_y;
	int		tex_x;
	int		tex_y;
	float	ray_dir_x0;
	float	ray_dir_y0;
	float	ray_dir_x1;
	float	ray_dir_y1;
	float	row_distance;
	float	floor_step_x;
	float	floor_step_y;
	float	floor_x;
	float	floor_y;
	float	pos_z;
	unsigned int	*dst;
	unsigned int	*src;

	y = -1;
	// rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
	ray_dir_x0 = player->dir_x - player->plane_x;
	ray_dir_y0 = player->dir_y - player->plane_y;
	ray_dir_x1 = player->dir_x + player->plane_x;
	ray_dir_y1 = player->dir_y + player->plane_y;
	h = screenHeight / 2;
	while (++y < h)
	{
		// Vertical position of the camera.
		pos_z = 0.5 * screenHeight;
		// Current y position compared to the center of the screen (the horizon)
		p = y - pos_z;
		// Horizontal distance from the camera to the floor for the current row.
		// 0.5 is the z position exactly in the middle between floor and ceiling.
		row_distance = pos_z / p;
		// calculate the real world step vector we have to add for each x (parallel to camera plane)
		// adding step by step avoids multiplications with a weight in the inner loop
		floor_step_x = row_distance * (ray_dir_x1 - ray_dir_x0) / screenWidth;
		floor_step_y = row_distance * (ray_dir_y1 - ray_dir_y0) / screenHeight;
		// real world coordinates of the leftmost column. This will be updated as we step to the right.
		floor_x = player->pos_x + row_distance * ray_dir_x0;
		floor_y = player->pos_y + row_distance * ray_dir_y0;
		x = -1;
		while (++x < screenWidth)
		{
			// the cell coord is simply got from the integer parts of floorX and floorY
			cell_x = (int)(floor_x);
			cell_y = (int)(floor_y);
			// FLOOR
			// get the texture coordinate from the fractional part
			tex_x = (int)(tex_ceil.width * (floor_x - cell_x)) & (tex_ceil.width - 1);
			tex_y = (int)(tex_ceil.height * (floor_y - cell_y)) & (tex_ceil.height - 1);
			dst = (int*)(img->addr + y * img->ll + x * (img->bpp / 8));
			src = (int*)tex_ceil.addr + tex_x * tex_ceil.height + tex_y;
			*dst = ft_darker_color(*src);

			// ceiling (symmetrical, at screenHeight - y - 1 instead of y)
			// get the texture coordinate from the fractional part
			tex_x = (int)(tex_floor.width * (floor_x - cell_x)) & (tex_floor.width - 1);
			tex_y = (int)(tex_floor.height * (floor_y - cell_y)) & (tex_floor.height - 1);
			dst = (int*)(img->addr + (screenHeight - 1 - y) * img->ll + x * (img->bpp / 8));
			src = (int*)tex_floor.addr + tex_x * tex_floor.height + tex_y;
			*dst = ft_darker_color(*src);
			floor_x += floor_step_x;
			floor_y += floor_step_y;
		}
	}
}

void	ft_raycasting(t_vars *vars)
{
	t_mlx		*mlx;
	t_player	*player;
	t_img		*img;

	mlx = vars->mlx;
	player = vars->player;
	img = vars->img;

	int		width;
	double	fov;
	
	fov = (FOV / 2.0) * M_PI / 180;
	width = mlx->width;
	int		x;
	//which box of the map we're in
	int		map_x;
	int		map_y;
	//what direction to step in x or y-direction (either +1 or -1)
    int		step_x;
    int		step_y;
	//was there a wall hit?
    int		hit;
	//was a NS or a EW wall hit?
    int		side;

	double	ray_plane_pc;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	wall_dist;
	double	side_dist_x;
    double	side_dist_y;

	x = -1;
	while (++x < width)
	{
		hit = 0;
		ray_plane_pc = 2 * x / (double)width - 1;
		ray_dir_x = player->dir_x + player->plane_x * ray_plane_pc;
		ray_dir_y = player->dir_y + player->plane_y * ray_plane_pc;
		map_x = (int)player->pos_x;
		map_y = (int)player->pos_y;

		delta_dist_x = fabs(1.0 / ray_dir_x);
		delta_dist_y = fabs(1.0 / ray_dir_y);
		//calculate step and initial sideDist
		if (ray_dir_x < 0)
	 	{
		step_x = -1;
		side_dist_x = (player->pos_x - map_x) * delta_dist_x;
		}
		else
		{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - player->pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
	 	{
		step_y = -1;
		side_dist_y = (player->pos_y - map_y) * delta_dist_y;
		}
		else
		{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - player->pos_y) * delta_dist_y;
		}
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			//Check if ray has hit a wall
			if (worldMap[map_y][map_x] > 0) hit = 1;
		}
		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (side == 0)
			wall_dist = (map_x - player->pos_x + (1 - step_x) / 2) / ray_dir_x;
		else
			wall_dist = (map_y - player->pos_y + (1 - step_y) / 2) / ray_dir_y;
		//Calculate height of line to draw on screen
     	int		line_height;
		int		draw_start;
		int		draw_end;
		double	h;
		t_tex	tex;
		int		tex_x;
		int		tex_y;
		int		eps;
		unsigned int		*dst;
		unsigned int		*src;
		double	wall_x;
		
		h = mlx->width / (2 * tan(fov));
		// printf("h = %f \n", h);
		line_height = (int)(h/ wall_dist);
		//calculate lowest and highest pixel to fill in current stripe
		draw_start = -line_height / 2 + mlx->height / 2;
		// if (draw_start < 0)
		// 	draw_start = 0;
		draw_end = line_height / 2 + mlx->height / 2;
		if (draw_end >= mlx->height)
			draw_end = mlx->height - 1;
		//where exactly the wall was hit
		if (side == 0)
			wall_x = player->pos_y + wall_dist * ray_dir_y;
		else
			wall_x = player->pos_x + wall_dist * ray_dir_x;
		wall_x -= floor(wall_x);
		// texture Selection
		if (side)
			tex_x = (ray_dir_y > 0);
		else
			tex_x = 2 + (ray_dir_x > 0);
		tex = vars->tex[tex_x];
		tex_x = (int)(wall_x * (double)tex.width);
		if(side == 0 && ray_dir_x > 0)
			tex_x = tex.width - tex_x - 1;
		if(side == 1 && ray_dir_y < 0)
			tex_x = tex.width - tex_x - 1;
		/*
		** The Bresenham Algorithm
		*/
		eps = 0;
		tex_y = 0;
		if (tex.height < line_height)
		{
			while (draw_start <= draw_end)
			{	if (draw_start >= 0)
				{
					dst = (int*)(img->addr + draw_start * img->ll + x * (img->bpp / 8));
					src = (int*)tex.addr + tex_x * tex.height + tex_y;
					*dst = *src;
				}
				draw_start++;
				eps += tex.height;
				if ((eps << 1) >= line_height)
				{
					tex_y++;
					eps -= line_height;
				}
			}
		}
		else
		{
			dst = (int*)(img->addr + draw_start * img->ll + x * (img->bpp / 8));
			src = (int*)tex.addr + tex_x * tex.height + tex_y;
			*dst = *src;
			while (tex_y < tex.height)
			{
				eps += line_height;
				tex_y++;
				if ((eps << 1) >= tex.height)
				{
					dst = (int*)(img->addr + draw_start * img->ll + x * (img->bpp / 8));
					src = (int*)tex.addr + tex_x * tex.height + tex_y;
					*dst = *src;
					draw_start++;
					eps -= tex.height;
				}
			}
		}
	}
	
}


void	ft_generate_img(t_vars *vars)
{
	t_mlx		*mlx;
	t_img		img;

	mlx = vars->mlx;
	img.img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	img.addr = mlx_get_data_addr(img.img , &img.bpp, &img.ll, &img.endian);
	vars->img = &img;
	ft_horizontalscanline(vars);
	ft_raycasting(vars);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, 0, 0);
	mlx_destroy_image(mlx->mlx, img.img);
	vars->img = NULL;
}

int		ft_key_hook(int keycode, t_vars *vars)
{
	t_mlx		*mlx;
	t_player	*player;
	double		f_wall;
	double		new_x;
	double		new_y;

	f_wall = 1.5;
	mlx = vars->mlx;
	player = vars->player;
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	// Translation : need to check for wall collision
	if (keycode == KEY_WALK_FORWARD)
	{
		new_x = player->pos_x + player->dir_x * WALK_SPEED * f_wall;
		new_y = player->pos_y + player->dir_y * WALK_SPEED *f_wall;
		if (worldMap[(int)new_y][(int)new_x] == 0)
		{
			player->pos_x = player->pos_x + player->dir_x * WALK_SPEED;
			player->pos_y = player->pos_y + player->dir_y * WALK_SPEED;
		}
	}
	if (keycode == KEY_WALK_BACKWARD)
	{
		new_x = player->pos_x - player->dir_x * WALK_SPEED * f_wall;
		new_y = player->pos_y - player->dir_y * WALK_SPEED * f_wall;
		if (worldMap[(int)new_y][(int)new_x] == 0)
		{
			player->pos_x = player->pos_x - player->dir_x * WALK_SPEED;
			player->pos_y = player->pos_y - player->dir_y * WALK_SPEED;
		}
	}
	if (keycode == KEY_STRAFE_LEFT)
	{
		new_x = player->pos_x - player->plane_x * WALK_SPEED * f_wall;
		new_y = player->pos_y - player->plane_y * WALK_SPEED * f_wall;
		if (worldMap[(int)new_y][(int)new_x] == 0)
		{
			player->pos_x = player->pos_x - player->plane_x * WALK_SPEED;
			player->pos_y = player->pos_y - player->plane_y * WALK_SPEED;
		}
	}
	if (keycode == KEY_STRAFE_RIGHT)
	{
		new_x = player->pos_x + player->plane_x * WALK_SPEED * f_wall;
		new_y = player->pos_y + player->plane_y * WALK_SPEED * f_wall;
		if (worldMap[(int)new_y][(int)new_x] == 0)
		{
			player->pos_x = player->pos_x + player->plane_x * WALK_SPEED;
			player->pos_y = player->pos_y + player->plane_y * WALK_SPEED;
		}
	}
	// Rotatations : both camera direction and camera plane must be rotated
	if (keycode == KEY_TURN_RIGHT)
	{
		double old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(-TURN_SPEED) - player->dir_y * sin(-TURN_SPEED);
		player->dir_y = old_dir_x * sin(-TURN_SPEED) + player->dir_y * cos(-TURN_SPEED);
		double old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(-TURN_SPEED) - player->plane_y * sin(-TURN_SPEED);
		player->plane_y = old_plane_x * sin(-TURN_SPEED) + player->plane_y * cos(-TURN_SPEED);
	}
	if (keycode == KEY_TURN_LEFT)
	{
		double old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(TURN_SPEED) - player->dir_y * sin(TURN_SPEED);
		player->dir_y = old_dir_x * sin(TURN_SPEED) + player->dir_y * cos(TURN_SPEED);
		double old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(TURN_SPEED) - player->plane_y * sin(TURN_SPEED);
		player->plane_y = old_plane_x * sin(TURN_SPEED) + player->plane_y * cos(TURN_SPEED);
	}
	ft_generate_img(vars);
}

void	ft_swap_tex(t_tex *tex)
{
	int		x;
	int		y;
	int		tmp;
	
	x = -1;
	while (++x < tex->width)
	{
		y = -1;
		while (++y < x)
		{
			tmp = *((unsigned int*)tex->addr + x * tex->height + y);
			*((unsigned int*)tex->addr + x * tex->height + y) = *((unsigned int*)tex->addr + y * tex->width + x);
			*((unsigned int*)tex->addr + y * tex->width + x) = tmp;
		}
	}
}

int main(void)
{
	t_mlx		mlx;
	t_player	player;
	t_tex		*tex;
	t_vars		vars;
	
	mlx.width = screenWidth;
	mlx.height = screenHeight;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "RayCasting");

	double	time;
	double	old_time;
	int		alpha = -90;
	double	fov;

	fov = (FOV / 2.0) * M_PI / 180;
	player.pos_x = 2.5;
	player.pos_y = 2.5;
	player.dir_x = cos(alpha * M_PI / 180);
	player.dir_y = sin(alpha * M_PI / 180);
	player.plane_x = -player.dir_y * tan(fov);
	player.plane_y = player.dir_x * tan(fov);
	

	/*
	** <| Wall textures |>
	** Need to:
	** - adapt if bpp != 32
	*/
	int		ll;
	int		bpp;
	int		endian;
	tex = &vars.tex[0];
	tex->img = mlx_xpm_file_to_image(mlx.mlx, "./textures/redbrick.xpm", &tex->width, &tex->height);
	tex->addr = mlx_get_data_addr(tex->img , &bpp, &ll, &endian);
	ft_swap_tex(tex);

	tex = &vars.tex[1];
	tex->img = mlx_xpm_file_to_image(mlx.mlx, "./textures/purplestone.xpm", &tex->width, &tex->height);
	tex->addr = mlx_get_data_addr(tex->img , &bpp, &ll, &endian);
	ft_swap_tex(tex);

	tex = &vars.tex[2];
	tex->img = mlx_xpm_file_to_image(mlx.mlx, "./textures/colorstone.xpm", &tex->width, &tex->height);
	tex->addr = mlx_get_data_addr(tex->img , &bpp, &ll, &endian);
	ft_swap_tex(tex);

	tex = &vars.tex[3];
	tex->img = mlx_xpm_file_to_image(mlx.mlx, "./textures/greystone.xpm", &tex->width, &tex->height);
	tex->addr = mlx_get_data_addr(tex->img , &bpp, &ll, &endian);
	ft_swap_tex(tex);

	/*
	** <| Wall textures |>
	*/

	tex = &vars.htex[0];
	tex->img = mlx_xpm_file_to_image(mlx.mlx, "./textures/mossy.xpm", &tex->width, &tex->height);
	tex->addr = mlx_get_data_addr(tex->img , &bpp, &ll, &endian);
	tex = &vars.htex[1];
	tex->img = mlx_xpm_file_to_image(mlx.mlx, "./textures/wood.xpm", &tex->width, &tex->height);
	tex->addr = mlx_get_data_addr(tex->img , &bpp, &ll, &endian);

	vars.mlx = &mlx;
	vars.player = &player;

	ft_generate_img(&vars);
	
	mlx_hook(mlx.win, 2, 1L<<0, ft_key_hook, &vars);
	mlx_loop(mlx.mlx);
}