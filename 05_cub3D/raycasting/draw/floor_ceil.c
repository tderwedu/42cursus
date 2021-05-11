/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:39:02 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/11 15:57:12 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_ceil(t_mlx *mlx)
{
	if (mlx->rgb[0])
		floor_ceil_rgb(mlx, mlx->img, C);
	else if (mlx->tex[C].width > mlx->tex[C].height)
		skybox(mlx, &mlx->tex[C], mlx->cam);
	else
		floor_ceil_tex(mlx, mlx->cam, mlx->img, C);
	if (mlx->rgb[1])
		floor_ceil_rgb(mlx, mlx->img, F);
	else
		floor_ceil_tex(mlx, mlx->cam, mlx->img, F);
}

void	floor_ceil_rgb(t_mlx *mlx, t_img *img, int id)
{
	register int	x;
	int				y;
	int				y_max;
	t_u32			rgb;
	t_u32			*addr;

	rgb = mlx->rgb[id];
	if (!id)
	{
		y = -1;
		y_max = mlx->cam->height_pitch;
	}
	else
	{
		y = mlx->cam->height_pitch - 1;
		y_max = mlx->height;
	}
	while (++y < y_max)
	{
		addr = (img->addr + y * img->sl);
		x = -1;
		while (++x < mlx->width)
			*(addr + x) = rgb;
	}
}

static inline void	floor_ceil_part_1(t_mlx *mlx, t_floor *sc, int id)
{
	if (id == C)
	{
		sc->y = -1;
		sc->y_max = mlx->cam->height_pitch;
		sc->z_cam = mlx->height_2 - mlx->cam->z_pos;
	}
	else
	{
		sc->y = mlx->cam->height_pitch - 1;
		sc->y_max = mlx->height;
		sc->z_cam = mlx->height_2 + mlx->cam->z_pos;
	}
}

static inline void	floor_ceil_part_2(t_tex *tex, t_floor *sc, t_u32 *dst)
{
	double	x_pc;
	double	y_pc;

	x_pc = (double)(sc->x_grid - (int)sc->x_grid);
	y_pc = (double)(sc->y_grid - (int)sc->y_grid);
	sc->x_tex = (int)(tex->width * x_pc) & tex->w_mask;
	sc->y_tex = (int)(tex->height * y_pc) & tex->h_mask;
	*(dst + sc->x) = *(tex->addr + sc->x_tex + sc->y_tex * tex->sl);
	sc->x_grid += sc->x_grid_step;
	sc->y_grid += sc->y_grid_step;
}

void	floor_ceil_tex(t_mlx *mlx, t_cam *cam, t_img *img, int id)
{
	t_floor	sc;
	t_tex	*tex;
	t_u32	*dst;

	tex = &mlx->tex[id];
	floor_ceil_part_1(mlx, &sc, id);
	while (++sc.y < sc.y_max)
	{
		if (id == C)
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
			floor_ceil_part_2(tex, &sc, dst);
	}
}
