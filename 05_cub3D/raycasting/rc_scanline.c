/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_scanline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:39:02 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/21 10:03:12 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	rc_scanline(t_mlx *mlx)
{
	if (mlx->rgb[C])
		rc_scanline_rgb(mlx, mlx->img, C);
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

	rgb = (mlx->rgb[type] >> 1) & 0x7F7F7F;
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

static inline void	set_tex_rgb(t_img *img, t_tex *tex, t_scan *sc)
{
	t_u32	*src;
	t_u32	*dst;
	double	x_pc;
	double	y_pc;

	x_pc = (double)(sc->x_grid - (int)sc->x_grid);
	y_pc = (double)(sc->y_grid - (int)sc->y_grid);
	sc->x_tex = (int)(tex->width * x_pc) & (tex->width - 1);
	sc->y_tex = (int)(tex->height * y_pc) & (tex->height - 1);
	dst = img->addr + sc->y * img->sl + sc->x;
	src = tex->addr + sc->x_tex * tex->sl + sc->y_tex;
	*dst = ((*src >> 1) & 0x7F7F7F);
}

void	rc_scanline_tex(t_mlx *mlx, t_cam *cam, t_img *img, int type)
{
	t_scan	sc;

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
		sc.x_grid_step = (sc.row_dist * 2.0 * cam->x_plane) / mlx->width;
		sc.y_grid_step = (sc.row_dist * 2.0 * cam->y_plane) / mlx->width;
		sc.x = -1;
		while (++sc.x < mlx->width)
		{
			set_tex_rgb(img, &mlx->tex[type], &sc);
			sc.x_grid += sc.x_grid_step;
			sc.y_grid += sc.y_grid_step;
		}
	}
}
