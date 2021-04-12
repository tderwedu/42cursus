/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_scanline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:39:02 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/12 16:49:41 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int		ft_darker_color(int color)
{
	return ((color >> 1) & 0x7F7F7F);
}


void	ft_scanline(t_mlx *mlx, t_player *player, t_img *img)
{
	
}

void	ft_scanline_rgb(t_mlx *mlx, t_player *player, t_img *img)
{
	int		y;
	int		h;
	t_ui	*ceil;
	t_ui	*floor;
	register int x;

	y = -1;
	h = mlx->height / 2;
	while (++y < h)
	{
		ceil = (t_ui*)(img->addr + y * img->sl);
		floor = (t_ui*)(img->addr + (mlx->height - 1 - y) * img->sl);
		x = -1;
		while (++x < mlx->width)
		{
			*(ceil + img->bpp * x) = (mlx->rgb[C] >> 1) & 0x7F7F7F);
			*(floor + img->bpp * x) = (mlx->rgb[F] >> 1) & 0x7F7F7F);
		}
	}
}

void	ft_scanline_tex(t_mlx *mlx, t_player *player, t_img *img)
{
	t_tex		floor;
	t_tex		ceil;

	floor = mlx->tex[F];
	ceil = mlx->tex[C];

	int		x;
	int		y;
	int		h;
	int		cell_x;
	int		cell_y;
	int		tex_x;
	int		tex_y;
	double	row_dist;
	double	ceil_step_x;
	double	ceil_step_y;
	double	ceil_x;
	double	ceil_y;
	t_ui	*dst;
	t_ui	*src;

	y = -1;
	// rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
	h = mlx->height / 2;
	while (++y < h)
	{
		// Scaling factor. Grows as y -> the horizon
		row_dist = mlx->height / (2.0 * y - mlx->height);
		// calculate the real world step vector we have to add for each x (parallel to camera plane)
		// adding step by step avoids multiplications with a weight in the inner loop
		ceil_step_x = (row_dist * 2.0 * player->plane_x) / mlx->width;
		ceil_step_y = (row_dist * 2.0 * player->plane_y) / mlx->height;
		// real world coordinates of the leftmost column. This will be updated as we step to the right.
		ceil_x = player->pos_x + row_dist * (player->dir_x - player->plane_x);
		ceil_y = player->pos_y + row_dist * (player->dir_y - player->plane_y);

		x = -1;
		while (++x < mlx->width)
		{
			// the cell coord is simply got from the integer parts of floorX and floorY
			cell_x = (int)(ceil_x);
			cell_y = (int)(ceil_y);
			// CEIL
			// get the texture coordinate from the fractional part
			tex_x = (int)(ceil.width * (ceil_x - cell_x)) & (ceil.width - 1);
			tex_y = (int)(ceil.height * (ceil_y - cell_y)) & (ceil.height - 1);
			dst = (int*)(img->addr + y * img->sl + x * (img->bpp / 8));
			src = (int*)ceil.addr + tex_x * ceil.height + tex_y;
			*dst = ft_darker_color(*src);

			// FLOOR (symmetrical, at mlx->height - y - 1 instead of y)
			// get the texture coordinate from the fractional part
			tex_x = (int)(floor.width * (ceil_x - cell_x)) & (floor.width - 1);
			tex_y = (int)(floor.height * (ceil_y - cell_y)) & (floor.height - 1);
			dst = (int*)(img->addr + (mlx->height - 1 - y) * img->sl + x * (img->bpp / 8));
			src = (int*)floor.addr + tex_x * floor.height + tex_y;
			*dst = ft_darker_color(*src);
			ceil_x += ceil_step_x;
			ceil_y += ceil_step_y;
		}
	}
}
