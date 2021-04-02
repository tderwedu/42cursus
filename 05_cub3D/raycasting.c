/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 21:57:56 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/02 21:05:04 by tderwedu         ###   ########.fr       */
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
	t_img	img;
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

void	ft_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->img.addr + (y * mlx->img.ll + x * (mlx->img.bpp / 8));
	*(unsigned int*)dst = color;
}

void	ft_draw_vline(t_mlx *mlx, int x, int y_s, int y_e, int color)
{
	char	*dst;

	while (y_s <= y_e)
	{
		dst = mlx->img.addr + (y_s * mlx->img.ll + x * (mlx->img.bpp / 8));
		*(unsigned int*)dst = color;
		y_s++;
	}
}

int		ft_key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return(0);
}



int main(void)
{
	t_mlx	mlx;
	
	int 	width;
	int 	height;
	double	fov;

	width = screenWidth;
	height = screenHeight;
	fov = (FOV / 2.0) * M_PI / 180;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, width, height, "RayCasting");
	mlx_hook(mlx.win, 2, 1L<<0, ft_key_hook, &mlx);
	mlx.img.img = mlx_new_image(mlx.mlx, width, height);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img , &mlx.img.bpp, &mlx.img.ll, &mlx.img.endian);

	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	double	time;
	double	old_time;

	// pos_x = 22;
	// pos_y = 12;
	// dir_x = -1;
	// dir_y = 0;

	pos_x = 20.5;
	pos_y = 20.5;
	int alpha = 225;
	dir_x = cos(alpha * M_PI / 180);
	dir_y = sin(alpha * M_PI / 180);
	plane_x = -dir_y * tan(fov);
	plane_y = dir_x * tan(fov);


	time = 0.0;
	old_time = 0.0;
	
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
		ray_dir_x = dir_x + plane_x * ray_plane_pc;
		ray_dir_y = dir_y + plane_y * ray_plane_pc;
		map_x = (int)pos_x;
		map_y = (int)pos_y;

		delta_dist_x = fabs(1.0 / ray_dir_x);
		delta_dist_y = fabs(1.0 / ray_dir_y);
		//calculate step and initial sideDist
		if (ray_dir_x < 0)
	 	{
		step_x = -1;
		side_dist_x = (pos_x - map_x) * delta_dist_x;
		}
		else
		{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
	 	{
		step_y = -1;
		side_dist_y = (pos_y - map_y) * delta_dist_y;
		}
		else
		{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - pos_y) * delta_dist_y;
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
			wall_dist = (map_x - pos_x + (1 - step_x) / 2) / ray_dir_x;
		else
			wall_dist = (map_y - pos_y + (1 - step_y) / 2) / ray_dir_y;


		//Calculate height of line to draw on screen
     	int		line_height;
		int		draw_start;
		int		draw_end;
		double	h;
		
		h = width / (2 * tan(fov));
		// printf("h = %f \n", h);
		line_height = (int)(h/ wall_dist);

		//calculate lowest and highest pixel to fill in current stripe
		draw_start = -line_height / 2 + height / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + height / 2;
		if (draw_end >= height)
			draw_end = height - 1;
		
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
		ft_draw_vline(&mlx, x, draw_start, draw_end, color);
	}
	printf("Ray Casting OK \n");
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	mlx_loop(mlx.mlx);
}
