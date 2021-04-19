/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 21:57:56 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/19 17:12:59 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

static inline void	set_tex_rgb_b(t_img *img, t_tex *tex, t_rc *rc, int x_tex)
{
	int		eps;
	int		y_s;
	int		y_tex;
	t_u32	*dst;
	t_u32	*src;

	eps = 0;
	y_tex = 0;
	y_s = rc->y_s;
	dst = img->addr + rc->x;
	src = tex->addr + x_tex * tex->sl;
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
	t_u32	*dst;
	t_u32	*src;

	eps = 0;
	y_tex = 0;
	y_s = rc->y_s;
	dst = (t_u32 *)img->addr + rc->x;
	src = (t_u32 *)tex->addr + x_tex * tex->sl;
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

void	rc_raycasting(t_mlx *mlx, t_cam *cam)
{
	t_rc	rc;
	t_tex	*tex;
	int		x_tex;

	rc.x = -1;
	while (++rc.x < mlx->width)
	{
		rc.pc_plane = 2.0 * rc.x / (double)mlx->width - 1.0;
		rc.x_map = (int)cam->x_pos;
		rc.y_map = (int)cam->y_pos;
		rc.x_r_dir = cam->x_dir + cam->x_plane * rc.pc_plane;
		rc.y_r_dir = cam->y_dir + cam->y_plane * rc.pc_plane;
		rc.x_dt_dist = fabs(1.0 / rc.x_r_dir);
		rc.y_dt_dist = fabs(1.0 / rc.y_r_dir);
		rc.x_step = 1 - 2 * (rc.x_r_dir < 0);
		rc.y_step = 1 - 2 * (rc.y_r_dir < 0);
		if (rc.x_r_dir < 0)
			rc.x_dist = (cam->x_pos - rc.x_map) * rc.x_dt_dist;
		else
			rc.x_dist = (rc.x_map + 1.0 - cam->x_pos) * rc.x_dt_dist;
		if (rc.y_r_dir < 0)
			rc.y_dist = (cam->y_pos - rc.y_map) * rc.y_dt_dist;
		else
			rc.y_dist = (rc.y_map + 1.0 - cam->y_pos) * rc.y_dt_dist;
		rc.hit = 0;
		while (!(rc.hit == 1))
		{
			if (rc.x_dist < rc.y_dist)
			{
				rc.x_dist += rc.x_dt_dist;
				rc.x_map += rc.x_step;
				rc.side = 0;
			}
			else
			{
				rc.y_dist += rc.y_dt_dist;
				rc.y_map += rc.y_step;
				rc.side = 1;
			}
			rc.hit = mlx->map[rc.y_map][rc.x_map];
		}
		
		if (!rc.side)
			rc.w_dist = (rc.x_map - cam->x_pos + (1 - rc.x_step) / 2) / rc.x_r_dir;
		else
			rc.w_dist = (rc.y_map - cam->y_pos + (1 - rc.y_step) / 2) / rc.y_r_dir;
		rc.line_h = (int)(mlx->width / (2.0 * tan(mlx->fov) * rc.w_dist));
		rc.y_s = -rc.line_h / 2 + mlx->height / 2;
		rc.y_e = rc.line_h / 2 + mlx->height / 2;
		if (rc.y_e >= mlx->height)
			rc.y_e = mlx->height - 1;
		if (rc.side == 0)
			rc.pc_wall = mlx->cam->y_pos + rc.w_dist * rc.y_r_dir;
		else
			rc.pc_wall = mlx->cam->x_pos + rc.w_dist * rc.x_r_dir;
		rc.pc_wall -= floor(rc.pc_wall);
		
		if (rc.side && rc.y_r_dir > 0)
			tex = &mlx->tex[SO];
		else if (rc.side)
			tex = &mlx->tex[NO];
		else if (rc.x_r_dir > 0)
			tex = &mlx->tex[EA];
		else
			tex = &mlx->tex[WE];
		x_tex = (int)(rc.pc_wall * (double)tex->width);
		if ((rc.side == 0 && rc.x_r_dir < 0) || (rc.side && rc.y_r_dir > 0))
			x_tex = tex->width - x_tex - 1;
		
		if (rc.line_h > tex->height)
			set_tex_rgb_b(mlx->img, tex, &rc, x_tex);
		else
			set_tex_rgb_s(mlx->img, tex, &rc, x_tex);
		
		mlx->z_buff[rc.x] = rc.w_dist;
	}
}
