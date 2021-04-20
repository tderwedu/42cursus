/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_scanline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:39:02 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/20 16:51:22 by tderwedu         ###   ########.fr       */
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
	{
		y = -1;
		y_max = mlx->height / 2;
	}
	else
	{
		y = mlx->height / 2 - 1;
		y_max = mlx->height - 1;
	}
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
	t_scan			sc;

	if (type == C)
		sc.y = 0;
	else
		sc.y = mlx->height / 2;
	sc.y_max = sc.y + mlx->height / 2;
	sc.y--;
	while (++sc.y < sc.y_max)
	{
		sc.factor = mlx->height / (2.0 * sc.y - mlx->height);
		sc.x_grid = cam->x_pos + sc.factor * (cam->x_dir - cam->x_plane);
		sc.y_grid = cam->y_pos + sc.factor * (cam->y_dir - cam->y_plane);
		sc.x_grid_step = (sc.factor * 2.0 * cam->x_plane) / mlx->width;
		sc.y_grid_step = (sc.factor * 2.0 * cam->y_plane) / mlx->width;
		sc.x = -1;
		while (++sc.x < mlx->width)
		{
			set_tex_rgb(img, &mlx->tex[type], &sc);
			sc.x_grid += sc.x_grid_step;
			sc.y_grid += sc.y_grid_step;
		}
	}
}
