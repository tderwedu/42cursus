/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tex_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:36:12 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/04 18:16:18 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	set_tex_x_loop(t_mlx *mlx, t_tex *tex, t_loop *box, t_u32 rgb)
{
	int		eps;
	int		x;
	int		x_tex;
	t_u32	*dst;
	t_u32	*src;

	eps = 0;
	x = box->x - 1;
	x_tex = box->x_tex;
	dst = mlx->img->addr + box->y * mlx->img->sl;
	src = tex->addr + box->y_tex * tex->sl;
	while (++x < (box->x_max + box->x))
	{
		if (*(src + x_tex) != rgb)
			*(dst + x) = *(src + x_tex);
		eps += box->x_tex_max;
		if ((eps << 1) >= box->x_max)
		{
			x_tex++;
			eps -= box->x_max;
		}
	}
}

void	set_tex_x_tex_loop(t_mlx *mlx, t_tex *tex, t_loop *box, t_u32 rgb)
{
	int		eps;
	int		x;
	int		x_tex;
	t_u32	*dst;
	t_u32	*src;

	eps = 0;
	x = box->x;
	x_tex = box->x_tex;
	dst = mlx->img->addr + box->y * mlx->img->sl;
	src = tex->addr + box->y_tex * tex->sl;
	if (*(src + x_tex) != rgb)
		*(dst + x) = *(src + x_tex);
	while (x < (box->x_max + box->x))
	{
		x_tex++;
		eps += box->x_max;
		if ((eps << 1) >= box->x_tex_max)
		{
			if (*(src + x_tex) != rgb)
				*(dst + x) = *(src + x_tex);
			x++;
			eps -= box->x_tex_max;
		}
	}
}

void	set_tex_y_loop(t_mlx *mlx, t_tex *tex, t_loop *box, t_u32 rgb)
{
	int	eps;
	int	y_max;

	eps = 0;
	y_max = box->y_max + box->y;
	box->y--;
	while (++box->y < y_max)
	{
		if (box->x_tex_max < (box->x_max - box->x))
			set_tex_x_loop(mlx, tex, box, rgb);
		else
			set_tex_x_tex_loop(mlx, tex, box, rgb);
		eps +=  box->y_tex_max;
		if ((eps << 1) >= box->y_max)
		{
			box->y_tex++;
			eps -= box->y_max;
		}
	}
}

void	set_tex_y_tex_loop(t_mlx *mlx, t_tex *tex, t_loop *box, t_u32 rgb)
{
	int	eps;
	int	y_max;

	eps = 0;
	y_max = box->y_max + box->y;
	while (box->y < y_max)
	{
		box->y_tex++;
		eps += box->y_max;
		if ((eps << 1) >= box->y_tex_max)
		{
			if (box->x_tex_max < (box->x_max - box->x))
				set_tex_x_loop(mlx, tex, box, rgb);
			else
				set_tex_x_tex_loop(mlx, tex, box, rgb);
			box->y++;
			eps -= box->y_tex_max;
		}
	}
}
