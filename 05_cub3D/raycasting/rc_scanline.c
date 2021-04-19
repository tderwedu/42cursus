/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_scanline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:39:02 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/19 17:10:33 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	rc_scanline(t_mlx *mlx)
{
	if (mlx->rgb[C] || mlx->rgb[F])
		rc_scanline_rgb(mlx, mlx->img);
	if (mlx->tex[C].addr || mlx->tex[F].addr)
		rc_scanline_tex(mlx, mlx->cam, mlx->img);
}

void	rc_scanline_rgb(t_mlx *mlx, t_img *img)
{
	register int	x;
	int				y;
	int				h;
	t_u32			rgb[2];
	t_u32			*addr[2];

	y = -1;
	h = mlx->height / 2;
	rgb[0] = ((mlx->rgb[C] >> 1) & 0x7F7F7F);
	rgb[1] = ((mlx->rgb[F] >> 1) & 0x7F7F7F);
	while (++y < h)
	{
		addr[0] = (img->addr + y * img->sl);
		addr[1] = (img->addr + (mlx->height - 1 - y) * img->sl);
		x = -1;
		while (++x < mlx->width)
		{
			*(addr[0] + x) = rgb[0];
			*(addr[1] + x) = rgb[1];
		}
	}
}

static inline void	set_tex_rgb(t_img *img, t_tex *tex, t_scan *sc)
{
	t_u32	*src;
	t_u32	*dst;
	double	x_pc;
	double	y_pc;

	x_pc = (double)(sc->x_tex - (int)sc->x_tex);
	y_pc = (double)(sc->y_tex - (int)sc->y_tex);
	sc->x_pxl = (int)(tex->width * x_pc) & (tex->width - 1);
	sc->y_pxl = (int)(tex->height * y_pc) & (tex->height - 1);
	dst = img->addr + sc->y * img->height + sc->x;
	src = tex->addr + sc->x_pxl * tex->width + sc->y_pxl;
	*dst = ((*src >> 1) & 0x7F7F7F);
}

void	rc_scanline_tex(t_mlx *mlx, t_cam *cam, t_img *img)
{
	t_scan			sc;

	sc.y = -1;
	sc.h = mlx->height / 2;
	while (++sc.y < sc.h)
	{
		sc.factor = mlx->height / (2.0 * sc.y - mlx->height);
		sc.x_tex = cam->x_pos + sc.factor * (cam->x_dir - cam->x_plane);
		sc.y_tex = cam->y_pos + sc.factor * (cam->y_dir - cam->y_plane);
		sc.x_tex_stepx = (sc.factor * 2.0 * cam->x_plane) / mlx->width;
		sc.y_tex_stepx = (sc.factor * 2.0 * cam->y_plane) / mlx->height;
		sc.x = -1;
		while (++sc.x < mlx->width)
		{
			if (mlx->tex[C].addr)
				set_tex_rgb(img, &mlx->tex[C], &sc);
			if (mlx->tex[F].addr)
				set_tex_rgb(img, &mlx->tex[F], &sc);
			sc.x_tex += sc.x_tex_stepx;
			sc.y_tex += sc.y_tex_stepx;
		}
	}
}
