/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_scanline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:39:02 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/12 19:32:38 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	rc_scanline(t_mlx *mlx, t_cam *cam, t_img *img)
{
	if (mlx->rgb[C] || mlx->rgb[F])
		rc_scanline_rgb(mlx, mlx->cam, mlx->img);
	if (mlx->tex[C].addr || mlx->tex[F].addr)
		rc_scanline_tex(mlx, mlx->cam, mlx->img);
}

void	rc_scanline_rgb(t_mlx *mlx, t_cam *cam, t_img *img)
{
	register int	x;
	int				y;
	int				h;
	t_ui			rgb[2];
	t_ui			*addr[2];

	y = -1;
	h = mlx->height / 2;
	rgb[0] = ((mlx->rgb[C] >> 1) & 0x7F7F7F);
	rgb[1] = ((mlx->rgb[F] >> 1) & 0x7F7F7F);
	while (++y < h)
	{
		addr[0] = (t_ui *)(img->addr + y * img->sl);
		addr[1] = (t_ui *)(img->addr + (mlx->height - 1 - y) * img->sl);
		x = -1;
		while (++x < mlx->width)
		{
			*(addr[0] + img->bpp * x) = rgb[0];
			*(addr[1] + img->bpp * x) = rgb[1];
		}
	}
}

typedef struct s_scan
{
	int		x;
	int		y;
	int		h;
	double	x_pxl_stepx;
	double	y_pxl_stepx;
	double	x_pxl;
	double	y_pxl;
	int		x_tex;
	int		y_tex;
	double	factor;
}				t_scan;

static inline void	rc_get_tex_rgb(t_img *img, t_tex *tex, t_scan *sc)
{
	t_ui	*src;
	t_ui	*dst;
	double x_pc;
	double y_pc;

	x_pc = (double)(sc->x_pxl - (int)sc->x_pxl);
	y_pc = (double)(sc->y_pxl - (int)sc->y_pxl);
	sc->x_tex = (int)(tex->width * x_pc) & (tex->width - 1);
	sc->y_tex = (int)(tex->height * y_pc) & (tex->height - 1);	
	dst = (t_ui *)img->addr + img->sl * sc->y + img->bpp * sc->x;
	src = (t_ui *)tex->addr + tex->height * sc->x_tex + sc->y_tex;
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
		sc.x_pxl = cam->x_pos + sc.factor * (cam->x_dir - cam->x_plane);
		sc.y_pxl = cam->y_pos + sc.factor * (cam->y_dir - cam->y_plane);
		sc.x_pxl_stepx = (sc.factor * 2.0 * cam->x_plane) / mlx->width;
		sc.y_pxl_stepx = (sc.factor * 2.0 * cam->y_plane) / mlx->height;
		sc.x = -1;
		while (++sc.x < mlx->width)
		{
			if (mlx->tex[C].addr)
				rc_get_tex_rgb(img, &mlx->tex[C], &sc);
			if (mlx->tex[F].addr)
				rc_get_tex_rgb(img, &mlx->tex[F], &sc);
			sc.x_pxl += sc.x_pxl_stepx;
			sc.y_pxl += sc.y_pxl_stepx;
		}
	}
}
