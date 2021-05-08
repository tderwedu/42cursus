/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tex_yx_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:12:37 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/08 17:34:52 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	yx_set_tex_x_loop(t_mlx *mlx, t_tex *tex, t_loop *box, t_u32 rgb)
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
	box->x_max = box->x_range + box->x;
	if (box->x_max > mlx->width)
		box->x_max = mlx->width;
	while (++x < box->x_max)
	{
		// printf("x: %i \n", x);
		if (*(src + x_tex) != rgb)
			*(dst + x) = *(src + x_tex);
		eps += box->x_tex_range;
		if ((eps << 1) >= box->x_range)
		{
			x_tex++;
			eps -= box->x_range;
		}
	}
}

void	yx_set_tex_x_tex_loop(t_mlx *mlx, t_tex *tex, t_loop *box, t_u32 rgb)
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
	box->x_max = box->x_range + box->x;
	if (box->x_max > mlx->width)
		box->x_max = mlx->width;
	while (x < box->x_max)
	{
		x_tex++;
		eps += box->x_range;
		if ((eps << 1) >= box->x_tex_range)
		{
			if (*(src + x_tex) != rgb)
				*(dst + x) = *(src + x_tex);
			x++;
			eps -= box->x_tex_range;
		}
	}
}

void	yx_set_tex_y_loop(t_mlx *mlx, t_tex *tex, t_loop *box, t_u32 rgb)
{
	int	eps;

	eps = 0;
	box->y_max = box->y_range + box->y;
	if (box->y_max > mlx->height)
		box->y_max = mlx->height;
	box->y--;
	while (++box->y < box->y_max)
	{
		// printf("y: %i \n", box->y);
		if (box->x_tex_range < box->x_range)
		{
			// ft_printf("1\n");
			yx_set_tex_x_loop(mlx, tex, box, rgb);
		}
		else
		{
			// ft_printf("1\n");
			yx_set_tex_x_tex_loop(mlx, tex, box, rgb);
		}
		eps +=  box->y_tex_range;
		if ((eps << 1) >= box->y_range)
		{
			box->y_tex++;
			eps -= box->y_range;
		}
	}
}

void	yx_set_tex_y_tex_loop(t_mlx *mlx, t_tex *tex, t_loop *box, t_u32 rgb)
{
	int	eps;

	eps = 0;
	box->y_max = box->y_range + box->y;
	if (box->y_max > mlx->height)
		box->y_max = mlx->height;
	while (box->y < box->y_max)
	{
		box->y_tex++;
		eps += box->y_range;
		if ((eps << 1) >= box->y_tex_range)
		{
			if (box->x_tex_range < box->x_range)
				yx_set_tex_x_loop(mlx, tex, box, rgb);
			else
				yx_set_tex_x_tex_loop(mlx, tex, box, rgb);
			box->y++;
			eps -= box->y_tex_range;
		}
	}
}
