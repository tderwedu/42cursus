/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tex_xy_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:36:12 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/12 13:56:54 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_tex_xy_y_loop(t_mlx *mlx, t_tex *tex, t_loop *box)
{
	int		eps;
	int		y;
	int		y_tex;
	t_u32	*dst;
	t_u32	*src;

	eps = 0;
	y = box->y - 1;
	y_tex = box->y_tex;
	dst = mlx->img->addr + box->x;
	src = tex->addr + box->x_tex * tex->sl;
	box->y_max = box->y_range + box->y;
	if (box->y_max > mlx->height)
		box->y_max = mlx->height;
	while (++y < box->y_max)
	{
		if (y > 0 && *(src + y_tex) != box->rgb)
			*(dst + y * mlx->img->sl) = *(src + y_tex);
		eps += box->y_tex_range;
		if ((eps << 1) >= box->y_range)
		{
			y_tex++;
			eps -= box->y_range;
		}
	}
}

static inline void 	y_max(t_mlx *mlx, t_loop *box)
{
	box->y_max = box->y_range + box->y;
	if (box->y_max > mlx->height)
		box->y_max = mlx->height;
}

void	set_tex_xy_y_tex_loop(t_mlx *mlx, t_tex *tex, t_loop *box)
{
	int		eps;
	int		y;
	int		y_tex;
	t_u32	*dst;
	t_u32	*src;

	eps = 0;
	y = box->y;
	y_tex = box->y_tex;
	dst = mlx->img->addr + box->x;
	src = tex->addr + box->x_tex * tex->sl;
	y_max(mlx, box);
	while (y < box->y_max)
	{
		y_tex++;
		eps += box->y_range;
		if ((eps << 1) >= box->y_tex_range)
		{
			if (y > 0 && *(src + y_tex) != box->rgb)
				*(dst + y * mlx->img->sl) = *(src + y_tex);
			y++;
			eps -= box->y_tex_range;
		}
	}
}

void	set_tex_xy_x_loop(t_mlx *mlx, t_tex *tex, t_loop *box, double dist)
{
	int	eps;

	eps = 0;
	box->x_max = box->x_range + box->x;
	if (box->x_max > mlx->width)
		box->x_max = mlx->width;
	box->x--;
	while (++box->x < box->x_max)
	{
		if (box->x > 0 && dist < mlx->z_buff[box->x])
		{
			if (box->y_tex_range < box->y_range)
				set_tex_xy_y_loop(mlx, tex, box);
			else
				set_tex_xy_y_tex_loop(mlx, tex, box);
		}
		eps += box->x_tex_range;
		if ((eps << 1) >= box->x_range)
		{
			box->x_tex++;
			eps -= box->x_range;
		}
	}
}

void	set_tex_xy_x_tex_loop(t_mlx *mlx, t_tex *tex, t_loop *box, double dist)
{
	int	eps;

	eps = 0;
	box->x_max = box->x_range + box->x;
	if (box->x_max > mlx->width)
		box->x_max = mlx->width;
	while (box->x < box->x_max)
	{
		box->x_tex++;
		eps += box->x_range;
		if ((eps << 1) >= box->x_tex_range)
		{
			if (box->x > 0 && dist < mlx->z_buff[box->x])
			{
				if (box->y_tex_range < box->y_range)
					set_tex_xy_y_loop(mlx, tex, box);
				else
					set_tex_xy_y_tex_loop(mlx, tex, box);
			}
			box->x++;
			eps -= box->x_tex_range;
		}
	}
}
