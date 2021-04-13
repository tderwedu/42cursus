/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 21:57:56 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/13 22:01:08 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

static inline void	rc_wall_hit(t_mlx *mlx, t_cam *cam, t_rc *rc)
{
	if (rc->x_r_dir < 0)
		rc->x_dist = (cam->x_pos - rc->x_map) * rc->x_dt_dist;
	else
		rc->x_dist = (rc->x_map + 1.0 - cam->x_pos) * rc->x_dt_dist;
	if (rc->y_r_dir < 0)
		rc->y_dist = (cam->y_pos - rc->y_map) * rc->y_dt_dist;
	else
		rc->y_dist = (rc->y_map + 1.0 - cam->y_pos) * rc->y_dt_dist;
	while (!(mlx->map[rc->y_map][rc->x_map] == 1))
	{
		if (rc->x_dist < rc->y_dist)
		{
			rc->x_dist += rc->x_dt_dist;
			rc->x_map += rc->x_step;
			rc->side = 0;
		}
		else
		{
			rc->y_dist += rc->y_dt_dist;
			rc->y_map += rc->y_step;
			rc->side = 1;
		}
	}
}

static inline void	set_tex_rgb_b(t_img *img, t_tex *tex, t_rc *rc, int x_tex)
{
	int		eps;
	int		y_s;
	int		y_tex;
	t_ui	*dst;
	t_ui	*src;

	eps = 0;
	y_tex = 0;
	y_s = rc->y_s;
	dst = (t_ui *)img->addr + rc->x;
	src = (t_ui *)tex->addr + x_tex * tex->width;
	while (y_s <= rc->y_e)
	{	
		if (y_s >= 0)
			*(dst + y_s * img->sl) = *(src + y_tex);
		y_s++;
		eps += tex->height;
		if ((eps << 1) >= rc->line_h)
		{
			y_tex++;
			eps -= rc->line_h;
		}
	}
}

static inline void	set_tex_rgb_s(t_img *img, t_tex *tex, t_rc *rc, int x_tex)
{
	int		eps;
	int		y_s;
	int		y_tex;
	t_ui	*dst;
	t_ui	*src;

	eps = 0;
	y_tex = 0;
	y_s = rc->y_s;
	dst = (t_ui *)img->addr + rc->x;
	src = (t_ui *)tex->addr + x_tex * tex->width;
	*(dst + y_s * img->sl) = *(src + y_tex);
	while (y_tex <= tex->height)
	{
		y_tex++;
		eps += rc->line_h;
		if ((eps << 1) >= tex->height)
		{
			*(dst + y_s * img->sl) = *(src + y_tex);
			y_s++;
			eps -= tex->height;
		}
	}
}

void	rc_set_tex(t_mlx *mlx, t_rc *rc)
{
	t_tex	*tex;
	int		x_tex;

	if (rc->y_e >= mlx->height)
		rc->y_e = mlx->height - 1;
	if (rc->side == 0)
		rc->pc_wall = mlx->cam->y_pos + rc->w_dist * rc->y_r_dir;
	else
		rc->pc_wall = mlx->cam->x_pos + rc->w_dist * rc->x_r_dir;
	rc->pc_wall -= floor(rc->pc_wall);
	if (rc->side && rc->y_r_dir > 0)
		tex = &mlx->tex[SO];
	else if (rc->side)
		tex = &mlx->tex[NO];
	else if (rc->x_r_dir > 0)
		tex = &mlx->tex[EA];
	else
		tex = &mlx->tex[WE];
	x_tex = (int)(rc->pc_wall * (double)tex->width);
	if ((rc->side == 0 && rc->x_r_dir < 0) || (rc->side && rc->y_r_dir > 0))
		x_tex = tex->width - x_tex - 1;
	if (rc->line_h > tex->height)
		set_tex_rgb_b(mlx->img, tex, rc, x_tex);
	else
		set_tex_rgb_s(mlx->img, tex, rc, x_tex);
}

void	rc_raycasting(t_mlx *mlx, t_cam *cam)
{
	t_rc	r;

	r.fov = (FOV / 2.0) * M_PI / 180;
	r.x = -1;
	while (++r.x < mlx->width)
	{
		r.pc_plane = 2.0 * r.x / (double)mlx->width - 1.0;
		r.x_map = (int)cam->x_pos;
		r.y_map = (int)cam->y_pos;
		r.x_r_dir = cam->x_dir + cam->x_plane * r.pc_plane;
		r.y_r_dir = cam->y_dir + cam->y_plane * r.pc_plane;
		r.x_dt_dist = fabs(1.0 / r.x_r_dir);
		r.y_dt_dist = fabs(1.0 / r.y_r_dir);
		r.x_step = 1 - 2 * (r.x_r_dir < 0);
		r.y_step = 1 - 2 * (r.y_r_dir < 0);
		rc_wall_hit(mlx, mlx->cam, &r);
		if (!r.side)
			r.w_dist = (r.x_map - cam->x_pos + (1 - r.x_step) / 2) / r.x_r_dir;
		else
			r.w_dist = (r.y_map - cam->y_pos + (1 - r.y_step) / 2) / r.y_r_dir;
		r.line_h = (int)(mlx->width / (2.0 * tan(r.fov) * r.w_dist));
		r.y_s = -r.line_h / 2 + mlx->height / 2;
		r.y_e = r.line_h / 2 + mlx->height / 2;
		rc_set_tex(mlx, &r);
	}
}
