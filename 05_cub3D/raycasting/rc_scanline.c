/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_scanline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:39:02 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/02 12:34:58 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	rc_scanline(t_mlx *mlx)
{
	if (mlx->rgb[C])
		rc_scanline_rgb(mlx, mlx->img, C);
	else if (mlx->tex[C].width > mlx->tex[C].height)
		rc_skybox(mlx, &mlx->tex[C], mlx->cam);
	else
		rc_scanline_tex(mlx, mlx->cam, mlx->img, C);
	if (mlx->rgb[F])
		rc_scanline_rgb(mlx, mlx->img, F);
	else
		rc_scanline_tex(mlx, mlx->cam, mlx->img, F);
}

void	rc_scanline_rgb(t_mlx *mlx, t_img *img, int type)
{
	register int	x;
	int				y;
	int				y_max;
	t_u32			rgb;
	t_u32			*addr;

	// rgb = (mlx->rgb[type] >> 1) & 0x7F7F7F;
	rgb = mlx->rgb[type];
	if (type == C)
		y = 0;
	else
		y = mlx->height_2;
	y_max = y + mlx->height_2;
	y--;
	while (++y < y_max)
	{
		addr = (img->addr + y * img->sl);
		x = -1;
		while (++x < mlx->width)
			*(addr + x) = rgb;
	}
}

void	rc_scanline_tex(t_mlx *mlx, t_cam *cam, t_img *img, int type)
{
	t_scan	sc;
	t_tex	*tex;
	t_u32	*dst;
	double	x_pc;
	double	y_pc;

	tex= &mlx->tex[type];
	if (type == C)
	{
		sc.y = -1;
		sc.y_max = cam->height_pitch;
		sc.z_cam = mlx->height_2 - cam->z_pos;
	}
	else
	{
		sc.y = cam->height_pitch - 1;
		sc.y_max = mlx->height;
		sc.z_cam = mlx->height_2 + cam->z_pos;
	}
	while (++sc.y < sc.y_max)
	{
		if (type == C)
			sc.p = cam->height_pitch - sc.y;
		else
			sc.p = sc.y - cam->height_pitch;
		sc.row_dist = sc.z_cam / sc.p;
		sc.x_grid = cam->x_pos + sc.row_dist * (cam->x_dir - cam->x_plane);
		sc.y_grid = cam->y_pos + sc.row_dist * (cam->y_dir - cam->y_plane);
		sc.x_grid_step = (sc.row_dist * cam->x_plane) / (double)mlx->width_2;
		sc.y_grid_step = (sc.row_dist * cam->y_plane) / (double)mlx->width_2;
		dst = img->addr + sc.y * img->sl;
		sc.x = -1;
		while (++sc.x < mlx->width)
		{
			x_pc = (double)(sc.x_grid - (int)sc.x_grid);
			y_pc = (double)(sc.y_grid - (int)sc.y_grid);
			sc.x_tex = (int)(tex->width * x_pc) & tex->w_mask;
			sc.y_tex = (int)(tex->height * y_pc) & tex->h_mask;
			if (SHADOW && type == F)
				*(dst + sc.x) = rc_shadow_effect(*(tex->addr + sc.x_tex + sc.y_tex * tex->sl), sc.row_dist);
			else
				*(dst + sc.x) = *(tex->addr + sc.x_tex + sc.y_tex * tex->sl);
			// *(dst + sc.x) = *(tex->addr + sc.x_tex + sc.y_tex* tex->sl);

			sc.x_grid += sc.x_grid_step;
			sc.y_grid += sc.y_grid_step;
		}
	}
}
