/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 21:57:56 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/07 16:31:39 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

static inline void	set_tex_rgb_b(t_img *img, t_tex *tex, t_ray *ray, int x_tex)
{
	int		eps;
	int		y_s;
	int		y_tex;
	t_u32	*dst;
	t_u32	*src;

	eps = 0;
	y_tex = 0;
	y_s = ray->y_s;
	dst = img->addr + ray->x;
	src = tex->addr + x_tex * tex->sl;
	while (y_s <= ray->y_e)
	{	
		if (y_s >= 0)
		{
			// *(dst + y_s * img->sl) = *(src + y_tex);
			if (SHADOW)
				*(dst + y_s * img->sl) = rc_shadow_effect(*(src + y_tex), ray->w_dist);
			else
				*(dst + y_s * img->sl) = *(src + y_tex);
		}
		y_s++;
		eps += tex->height;
		if ((eps << 1) >= ray->line_h)
		{
			y_tex++;
			eps -= ray->line_h;
			if (y_tex >=  tex->height)
				y_tex = tex->height - 1;
		}
	}
}

static inline void	set_tex_rgb_s(t_img *img, t_tex *tex, t_ray *ray, int x_tex)
{
	int		eps;
	int		y_s;
	int		y_tex;
	t_u32	*dst;
	t_u32	*src;

	eps = 0;
	y_tex = 0;
	y_s = ray->y_s;
	dst = (t_u32 *)img->addr + ray->x;
	src = (t_u32 *)tex->addr + x_tex * tex->sl;
	if (SHADOW)
		*(dst + y_s * img->sl) = rc_shadow_effect(*(src + y_tex), ray->w_dist);
	else
		*(dst + y_s * img->sl) = *(src + y_tex);
	while (y_tex < tex->height)
	{
		y_tex++;
		eps += ray->line_h;
		if ((eps << 1) >= tex->height)
		{
			if (SHADOW)
				*(dst + y_s * img->sl) = rc_shadow_effect(*(src + y_tex), ray->w_dist);
			else
				*(dst + y_s * img->sl) = *(src + y_tex);
			y_s++;
			eps -= tex->height;
		}
	}
}

void	rc_raycasting(t_mlx *mlx, t_cam *cam)
{
	t_ray	ray;

	ft_update_ptr_map(mlx);
	ray.x = -1;
	while (++ray.x < mlx->width)
	{
		ray.pc_plane = 2.0 * ray.x / (double)mlx->width - 1.0;
		ray.x_map = (int)cam->x_pos;
		ray.y_map = (int)cam->y_pos;
		ray.x_r_dir = cam->x_dir + cam->x_plane * ray.pc_plane;
		ray.y_r_dir = cam->y_dir + cam->y_plane * ray.pc_plane;
		ray.x_dt_dist = fabs(1.0 / ray.x_r_dir);
		ray.y_dt_dist = fabs(1.0 / ray.y_r_dir);
		ray.x_step = 1 - 2 * (ray.x_r_dir < 0);
		ray.y_step = 1 - 2 * (ray.y_r_dir < 0);
		if (ray.x_r_dir < 0)
			ray.x_dist = (cam->x_pos - ray.x_map) * ray.x_dt_dist;
		else
			ray.x_dist = (ray.x_map + 1.0 - cam->x_pos) * ray.x_dt_dist;
		if (ray.y_r_dir < 0)
			ray.y_dist = (cam->y_pos - ray.y_map) * ray.y_dt_dist;
		else
			ray.y_dist = (ray.y_map + 1.0 - cam->y_pos) * ray.y_dt_dist;
		ray.hit = 0;
		while (ray.hit != 1)
		{
			if (ray.x_dist < ray.y_dist)
			{
				ray.x_dist += ray.x_dt_dist;
				ray.x_map += ray.x_step;
				ray.side = 0;
			}
			else
			{
				ray.y_dist += ray.y_dt_dist;
				ray.y_map += ray.y_step;
				ray.side = 1;
			}
			ray.hit = mlx->map[ray.y_map][ray.x_map];
			if (ray.hit == 3)
			{
				if (rc_is_door_leaf(mlx, cam, &ray))
					break;
			}
			else if (ray.hit == 5)
				ray.hit = 1;
		}
		
		if (ray.hit != 3)
		{
			if (!ray.side)
				ray.w_dist = (ray.x_map - cam->x_pos + (1.0 - ray.x_step) / 2.0) / ray.x_r_dir;
			else
				ray.w_dist = (ray.y_map - cam->y_pos + (1.0 - ray.y_step) / 2.0) / ray.y_r_dir;
			if (ray.side == 0)
				ray.pc_wall = cam->y_pos + ray.w_dist * ray.y_r_dir;
			else
				ray.pc_wall = cam->x_pos + ray.w_dist * ray.x_r_dir;
			ray.pc_wall = ray.pc_wall - (int)ray.pc_wall;
		}
		
		ray.line_h = (int)(mlx->ratio / ray.w_dist);
		ray.y_s = -ray.line_h / 2 + cam->height_pitch + cam->z_pos / ray.w_dist;
		ray.y_e = ray.line_h / 2 + cam->height_pitch + cam->z_pos / ray.w_dist;
		if (ray.y_e >= mlx->height)
			ray.y_e = mlx->height - 1;
		if (ray.hit == 3)
			ray.tex = &mlx->tex[D];
		else if (ray.side && ray.y_r_dir > 0)	
			ray.tex = &mlx->tex[SO];
		else if (ray.side)
			ray.tex = &mlx->tex[NO];
		else if (ray.x_r_dir > 0)
			ray.tex = &mlx->tex[EA];
		else
			ray.tex = &mlx->tex[WE];
		// Opened Door handling
		if (mlx->map[(int)cam->y_pos][(int)cam->x_pos] == 3 && 
			(int)cam->x_pos == ray.x_map && ray.pc_wall > 0.5)
		{
			ray.tex = &mlx->tex[D];
			ray.pc_wall -= 0.5;
		}
		
		ray.x_tex = (int)(ray.pc_wall * (double)ray.tex->width);
		if ((ray.side == 0 && ray.x_r_dir < 0) || (ray.side && ray.y_r_dir > 0))
			ray.x_tex = ray.tex->width - ray.x_tex - 1;
		
		if (ray.line_h > ray.tex->height)
			set_tex_rgb_b(mlx->img, ray.tex, &ray, ray.x_tex);
		else
			set_tex_rgb_s(mlx->img, ray.tex, &ray, ray.x_tex);
		
		mlx->z_buff[ray.x] = ray.w_dist;
	}
}
