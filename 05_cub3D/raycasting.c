/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 21:57:56 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/02 22:15:03 by tderwedu         ###   ########.fr       */
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

# define WALK_SPEED 1
# define TURN_SPEED 25

# define XK_MISCELLANY
# include <X11/keysymdef.h>
# include <X11/X.h>

# define KEY_WALK_FORWARD		XK_Up
# define KEY_WALK_BACKWARD		XK_Down
# define KEY_TURN_LEFT			XK_Left
# define KEY_TURN_RIGHT			XK_Right
# define KEY_STRAFE_LEFT		XK_a
# define KEY_STRAFE_RIGHT		XK_d
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

typedef struct	s_vars
{
	t_mlx		*mlx;
	t_player	*player;
}				t_vars;

int worldMap[mapHeight][mapWidth] =
{
  {1,2,3,4,3,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {3,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {2,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,4,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int		ft_darker_color(int color)
{
	int t;
	int r;
	int g;
	int b;

	t = color & 0xFF000000;
	r = (color & 0x00FF0000) >> 16;
	g = (color & 0x0000FF00) >> 8;
	b = color & 0x00000FF;
	return (t << 24 | (r / 2) << 16 | (g / 2) << 8 | (b / 2));
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

void	ft_raycasting(t_mlx *mlx, t_player *player)
{
	int		width;
	double	fov;
	t_img	img;

	img.img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	img.addr = mlx_get_data_addr(img.img , &img.bpp, &img.ll, &img.endian);
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
		
		h = mlx->width / (2 * tan(fov));
		// printf("h = %f \n", h);
		line_height = (int)(h/ wall_dist);

		//calculate lowest and highest pixel to fill in current stripe
		draw_start = -line_height / 2 + mlx->height / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + mlx->height / 2;
		if (draw_end >= mlx->height)
			draw_end = mlx->height - 1;
		
		//choose wall color
		int color;
		switch(worldMap[map_y][map_x])
		{
			case 1:  color = RED; break;
			case 2:  color = GREEN; break;
			case 3:  color = BLUE; break;
			case 4:  color = YELLOW; break;
			default: color = WHITE; break;
      }
		//give x and y sides different brightness
		if (side == 1)
			color = ft_darker_color(color);
		//draw the pixels of the stripe as a vertical line
		ft_draw_vline(&img, x, draw_start, draw_end, color);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, 0, 0);
	mlx_destroy_image(mlx->mlx, img.img );
}

int		ft_key_hook(int keycode, t_vars *vars)
{
	t_mlx	*mlx;
	t_player *player;

	mlx = vars->mlx;
	player = vars->player;

	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	if (keycode == KEY_WALK_FORWARD)
	{
		if(worldMap[(int)(player->pos_x + player->dir_x * WALK_SPEED)][(int)(player->pos_y)] == 0) player->pos_x += player->dir_x * WALK_SPEED;
		if(worldMap[(int)(player->pos_x)][(int)(player->pos_y + player->dir_y * WALK_SPEED)] == 0) player->pos_y += player->dir_y * WALK_SPEED;
	}
	//move backwards if no wall behind you
	if (keycode == KEY_WALK_BACKWARD)
	{
		if(worldMap[(int)(player->pos_x - player->dir_x * WALK_SPEED)][(int)(player->pos_y)] == 0) player->pos_x -= player->dir_x * WALK_SPEED;
		if(worldMap[(int)(player->pos_x)][(int)(player->pos_y - player->dir_y * WALK_SPEED)] == 0) player->pos_y -= player->dir_y * WALK_SPEED;
	}
	//rotate to the right
	if (keycode == KEY_TURN_RIGHT)
	{
	//both camera direction and camera plane must be rotated
		double old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(-TURN_SPEED) - player->dir_y * sin(-TURN_SPEED);
		player->dir_y = old_dir_x * sin(-TURN_SPEED) + player->dir_y * cos(-TURN_SPEED);
		double old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(-TURN_SPEED) - player->plane_y * sin(-TURN_SPEED);
		player->plane_y = old_plane_x * sin(-TURN_SPEED) + player->plane_y * cos(-TURN_SPEED);
	}
	//rotate to the left
	if (keycode == KEY_TURN_LEFT)
	{
		//both camera direction and camera plane must be rotated
		double old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(TURN_SPEED) - player->dir_y * sin(TURN_SPEED);
		player->dir_y = old_dir_x * sin(TURN_SPEED) + player->dir_y * cos(TURN_SPEED);
		double old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(TURN_SPEED) - player->plane_y * sin(TURN_SPEED);
		player->plane_y = old_plane_x * sin(TURN_SPEED) + player->plane_y * cos(TURN_SPEED);
	}
	ft_raycasting(mlx, player);
}

int main(void)
{
	t_mlx	mlx;
	t_player player;
	
	mlx.width = screenWidth;
	mlx.height = screenHeight;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "RayCasting");

	double	time;
	double	old_time;
	int		alpha = 225;
	double	fov;

	fov = (FOV / 2.0) * M_PI / 180;
	player.pos_x = 20.5;
	player.pos_y = 20.5;
	player.dir_x = cos(alpha * M_PI / 180);
	player.dir_y = sin(alpha * M_PI / 180);
	player.plane_x = -player.dir_y * tan(fov);
	player.plane_y = player.dir_x * tan(fov);

	ft_raycasting(&mlx, &player);
	t_vars vars;
	vars.mlx = &mlx;
	vars.player = &player;
	mlx_hook(mlx.win, 2, 1L<<0, ft_key_hook, &vars);
	mlx_loop(mlx.mlx);
}
