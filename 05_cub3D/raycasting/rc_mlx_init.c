/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:12:57 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/14 09:49:46 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int	rc_mlx_init(t_cub *data, t_mlx *mlx)
{
	int	i;

	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (rc_error_data(data, mlx, ERR_RC_INIT));
	mlx_get_screen_size(mlx->mlx, &mlx->width, &mlx->height);
	if (mlx->width > data->width)
		mlx->width = data->width;
	if (mlx->height > data->height)
		mlx->height = data->height;
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "cub3D");
	if (!mlx->win)
		return (rc_error_data(data, mlx, ERR_RC_WIN));
	i = -1;
	while (++i <= S)
		if (rc_get_wall_tex(data, mlx, i))
			return (1);
	rc_set_cam(data, mlx->cam);
	mlx->map = data->map;
	data->map = NULL;
	return (0);
}

void	rc_set_cam(t_cub *data, t_cam *cam)
{
	double	fov;

	fov = (FOV / 2.0) * M_PI / 180;
	cam->x_pos = (double)data->x_pos + 0.5;
	cam->y_pos = (double)data->y_pos + 0.5;
	cam->x_dir = 0.0;
	cam->y_dir = 0.0;
	if (data->dir == 'N')
		cam->y_dir = -1.0;
	else if (data->dir == 'W')
		cam->x_dir = -1.0;
	else if (data->dir == 'S')
		cam->y_dir = 1.0;
	else if (data->dir == 'E')
		cam->x_dir = 1.0;
	cam->x_plane = -cam->y_dir * tan(fov);
	cam->y_plane = cam->x_dir * tan(fov);
	if (DEBUG)
	{
		ft_printf("  POS| y: % .2f | x: % .2f\n", cam->y_pos, cam->x_pos);
		ft_printf("  DIR| y: % .2f | x: % .2f\n", cam->y_dir, cam->x_dir);
		ft_printf("PLANE| y: % .2f | x: % .2f\n", cam->y_plane, cam->x_plane);
	}
}

int	rc_get_wall_tex(t_cub *d, t_mlx *x, int i)
{
	t_tex	*t;

	t = &x->tex[i];
	if (!d->tex[i])
	{
		x->rgb[i] = d->rgb[i];
		t->img = NULL;
		t->addr = NULL;
		return (0);
	}
	x->rgb[i] = 0;
	t->img = mlx_xpm_file_to_image(x->mlx, d->tex[i], &t->width, &t->height);
	if (!t->img)
		return (rc_error_data(d, x, ERR_RC_IMG_XPM));
	t->addr = mlx_get_data_addr(t->img, &t->bpp, &t->sl, &t->endia);
	if (!t->addr)
		return (rc_error_data(d, x, ERR_RC_ADDR_XPM));
	t->bpp /= 8;
	t->sl /= 4;
	if (!(t->bpp == sizeof(int)))
		return (rc_error_data(d, x, ERR_RC_BPP));
	rc_rotate_wall_tex(t);
	return (0);
}

void	rc_rotate_wall_tex(t_tex *tex)
{
	t_ui			tmp;
	register int	x;
	register int	y;
	register t_ui	*addr;

	addr = (t_ui *)tex->addr;
	x = -1;
	while (++x < tex->width)
	{
		y = -1;
		while (++y < x)
		{
			tmp = *(addr + x * tex->height + y);
			*(addr + x * tex->height + y) = *(addr + y * tex->width + x);
			*(addr + y * tex->width + x) = tmp;
		}
	}
}
