/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_skybox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:24:45 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/04 09:45:34 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

static inline void	skybox_x_loop(t_mlx *mlx, t_tex *tex, t_sky *box)
{
	int		eps;
	int		x_tex;
	t_u32	*dst;
	t_u32	*src;

	eps = 0;
	box->x = -1;
	x_tex = box->x_tex;
	dst = mlx->img->addr + box->y * mlx->img->sl;
	src = tex->addr + box->y_tex * tex->sl;
	while (++box->x < mlx->width)
	{
		*(dst + box->x) = *(src + x_tex);
		eps += box->dt_x_tex;
		if ((eps << 1) >= mlx->width)
		{
			x_tex = ((x_tex + 1) & tex->w_mask);
			eps -=  mlx->width;
		}
	}
}

static inline void	skybox_x_tex_loop(t_mlx *mlx, t_tex *tex, t_sky *box)
{
	int		eps;
	int		x_tex;
	t_u32	*dst;
	t_u32	*src;

	eps = 0;
	box->x = 0;
	x_tex = box->x_tex;
	dst = mlx->img->addr + box->y * mlx->img->sl;
	src = tex->addr + box->y_tex * tex->sl;
	*(dst + box->x) = *(src + x_tex);
	while (box->x < mlx->width)
	{
		x_tex = ((x_tex + 1) & tex->w_mask);
		eps += mlx->width;
		if ((eps << 1) >= box->dt_x_tex)
		{
			*(dst + box->x) = *(src + x_tex);
			box->x++;
			eps -= box->dt_x_tex;
		}
	}
}

void	skybox_y_loop(t_mlx *mlx, t_tex *tex, t_sky *box)
{
	int	eps;

	eps = 0;
	box->y = -1;
	while (++box->y < mlx->cam->height_pitch)
	{
		if (box->dt_x_tex <= mlx->width)
			skybox_x_loop(mlx, tex, box);
		else
			skybox_x_tex_loop(mlx, tex, box);
		eps +=  box->dt_y_tex;
		if ((eps << 1) >= mlx->cam->height_pitch)
		{
			box->y_tex = ((box->y_tex + 1) & tex->h_mask);
			eps -= mlx->cam->height_pitch;
		}
	}
}

void	skybox_y_tex_loop(t_mlx *mlx, t_tex *tex, t_sky *box)
{
	int	eps;

	eps = 0;
	box->y = 0;
	while (box->y < mlx->cam->height_pitch)
	{
		box->y_tex = ((box->y_tex + 1) & tex->h_mask);
		eps += mlx->cam->height_pitch;
		if ((eps << 1) >= box->dt_y_tex)
		{
			if (box->dt_x_tex <= mlx->width)
				skybox_x_loop(mlx, tex, box);
			else
				skybox_x_tex_loop(mlx, tex, box);
			box->y++;
			eps -= box->dt_y_tex;
		}
	}
}

void	rc_skybox(t_mlx *mlx, t_tex *tex, t_cam *cam)
{
	double	x_dir;
	double	y_dir;
	t_sky	box;

	box.y = 0;
	box.y_tex = ((0.30 * mlx->height_2 - cam->pitch) * tex->height) / mlx->width;
	box.dt_y_tex = (cam->height_pitch * tex->height) / mlx->width;
	x_dir = cam->x_dir;
	y_dir = cam->y_dir;
	box.x_tex = (int)((atan2(y_dir, x_dir) + M_PI)/(2 * M_PI) * tex->width);
	box.x_tex -= tex->width / 8;
	if (box.x_tex < 0)
		box.x_tex += tex->width;
	box.dt_x_tex = tex->width / 4;
	if (box.dt_y_tex < cam->height_pitch)
		skybox_y_loop(mlx, tex, &box);
	else
		skybox_y_tex_loop(mlx, tex, &box);
}
