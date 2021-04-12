/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:12:57 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/12 16:14:17 by tderwedu         ###   ########.fr       */
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
		if (rc_get_tex(data, mlx, i))
			return (1);
	rc_set_player(data, mlx->player);
	return (0);
}

void	rc_set_player(t_cub *data, t_player *player)
{
	double	fov;

	fov = (FOV / 2.0) * M_PI / 180;
	player->pos_x = data->x_pos;
	player->pos_y = data->x_pos;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	if (data->dir = 'N')
		player->dir_y = -1.0;
	else if (data->dir = 'W')
		player->dir_x = -1.0;
	else if (data->dir = 'S')
		player->dir_y = 1.0;
	else if (data->dir = 'E')
		player->dir_x = 1.0;
	player->plane_x = -player->dir_y * tan(fov);
	player->plane_y = player->dir_x * tan(fov);
}


int	rc_get_tex(t_cub *d, t_mlx *x, int i)
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
	t->addr = mlx_get_data_addr(t->img , &t->bpp, &t->sl, &t->endia);
	if (!t->addr)
		return (rc_error_data(d, x, ERR_RC_ADDR_XPM));
	t->bpp /= 8;
	if (!(t->bpp == sizeof(int)))
		return (rc_error_data(d, x, ERR_RC_BPP));
	rc_rotate_tex(t);
	return (0);
}

void	rc_rotate_tex(t_tex *tex)
{
	t_ui			tmp;
	register int	x;
	register int	y;
	register t_ui	*addr;
	
	addr = (t_ui*)tex->addr;
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
