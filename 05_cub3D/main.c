/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:58:46 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/29 18:15:35 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <mlx.h>

/*
** X11 keycodes
*/
# define XK_LATIN1
# define XK_MISCELLANY
# include <X11/keysymdef.h>
# include <X11/X.h>

# define KEY_WALK_FORWARD		XK_Up

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_vars
{
    void	*mlx;
    void	*win;
	int		x;
    int		y;
}				t_vars;


void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_mxl_draw_yline(t_img *img, int xmin, int xmax, int y, int color)
{
	while (xmin <= xmax)
		ft_mlx_pixel_put(img, xmin++, y, color);
}

void	ft_mxl_draw_xline(t_img *img, int x, int ymin, int ymax, int color)
{
	while (ymin <= ymax)
		ft_mlx_pixel_put(img, x, ymin++, color);
}

void	ft_mxl_draw_diamond(t_img *img, int pos_x, int pos_y, int radius, int width, int color)
{
	int y;
	int delta;

	y = 0;
	width /= 2;
	while (y <= radius)
	{
		delta = radius - y;
		ft_mxl_draw_yline(img, -delta - width + pos_x, -delta + width + pos_x, pos_y + y, color);
		ft_mxl_draw_yline(img, delta - width + pos_x, delta + width + pos_x, pos_y + y, color);
		ft_mxl_draw_yline(img, -delta - width + pos_x, -delta + width + pos_x, pos_y - y, color);
		ft_mxl_draw_yline(img, delta - width + pos_x, delta + width + pos_x, pos_y - y, color);
		y++;
	}
}

int		key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
    printf("Hello from key_hook!\n");
	printf("key: %c\n", keycode);
	return(0);
}

int		mouse_hook(int button, int x, int y, t_vars *param)
{
	int nx;
	int ny;

	mlx_mouse_get_pos(param->mlx, param->win, &nx, &ny);
	printf("BUTTON: %i\n", button);
	printf("X: %i - Y: %i\n", x, y);
	printf("Angle: %f\n", 180 * atan((double)(ny - param->y)/(double)(x - param->x)) / M_PI_2);
	return(0);
}

int		enter_notify_hook(t_vars *vars)
{
	printf("Hello! \n");
}

int		leave_notify_hook(t_vars *vars)
{
	printf("Bye! \n");
}

int		close_hook(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
}

int		main(void)
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 360, "Hello world!");
	mlx_mouse_get_pos(vars.mlx, vars.win, &vars.x, &vars.y);

	// Printing a new image
	img.img = mlx_new_image(vars.mlx,  640, 360);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	ft_mxl_draw_diamond(&img, 200, 200, 50, 10, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	// Mouse specific Hook
	mlx_mouse_hook (vars.win, mouse_hook, &vars);
	// General Purpose Hook
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_hook(vars.win, 7, 1L<<4, enter_notify_hook, &vars);
	mlx_hook(vars.win, 8, 1L<<5, leave_notify_hook, &vars);
	mlx_hook(vars.win, 17, 1L<<17, leave_notify_hook, &vars);
	mlx_loop(vars.mlx);
}
