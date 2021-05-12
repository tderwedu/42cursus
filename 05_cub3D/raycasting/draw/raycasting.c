/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 21:57:56 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/12 11:54:22 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	rc_init(t_mlx *mlx, t_cam *cam, t_ray *ray, t_loop *box)
{
	ray->pc_plane = 2.0 * box->x / (double)mlx->width - 1.0;
	ray->x_map = (int)cam->x_pos;
	ray->y_map = (int)cam->y_pos;
	ray->x_r_dir = cam->x_dir + cam->x_plane * ray->pc_plane;
	ray->y_r_dir = cam->y_dir + cam->y_plane * ray->pc_plane;
	ray->x_dt_dist = fabs(1.0 / ray->x_r_dir);
	ray->y_dt_dist = fabs(1.0 / ray->y_r_dir);
	ray->x_step = 1 - 2 * (ray->x_r_dir < 0);
	ray->y_step = 1 - 2 * (ray->y_r_dir < 0);
	if (ray->x_r_dir < 0)
		ray->x_dist = (cam->x_pos - ray->x_map) * ray->x_dt_dist;
	else
		ray->x_dist = (ray->x_map + 1.0 - cam->x_pos) * ray->x_dt_dist;
	if (ray->y_r_dir < 0)
		ray->y_dist = (cam->y_pos - ray->y_map) * ray->y_dt_dist;
	else
		ray->y_dist = (ray->y_map + 1.0 - cam->y_pos) * ray->y_dt_dist;
	ray->hit = 0;
}

static inline void	rc_dda(t_mlx *mlx, t_cam *cam, t_ray *ray)
{
	while (ray->hit != m_wall)
	{
		if (ray->x_dist < ray->y_dist)
		{
			ray->x_dist += ray->x_dt_dist;
			ray->x_map += ray->x_step;
			ray->side = 0;
		}
		else
		{
			ray->y_dist += ray->y_dt_dist;
			ray->y_map += ray->y_step;
			ray->side = 1;
		}
		ray->hit = mlx->map[ray->y_map][ray->x_map];
		if (ray->hit == m_door)
			if (is_door(mlx, cam, ray))
				break ;
		if (ray->hit == m_secret)
			ray->hit = m_wall;
	}
}

static inline void	rc_range(t_mlx *mlx, t_cam *cam, t_ray *ray, t_loop *box)
{
	if (ray->hit != 3)
	{
		if (!ray->side)
			ray->w_dist = (ray->x_map - cam->x_pos + (1.0 - ray->x_step)
					/ 2.0) / ray->x_r_dir;
		else
			ray->w_dist = (ray->y_map - cam->y_pos + (1.0 - ray->y_step)
					/ 2.0) / ray->y_r_dir;
		if (ray->side == 0)
			ray->pc_wall = cam->y_pos + ray->w_dist * ray->y_r_dir;
		else
			ray->pc_wall = cam->x_pos + ray->w_dist * ray->x_r_dir;
		ray->pc_wall = ray->pc_wall - (int)ray->pc_wall;
	}
	ray->line_h = (int)(mlx->ratio / ray->w_dist);
	box->rgb = 0xFF000000;
	box->y = -ray->line_h / 2 + cam->height_pitch + cam->z_pos / ray->w_dist;
	box->y_max = ray->line_h / 2 + cam->height_pitch + cam->z_pos / ray->w_dist;
	if (box->y_max >= mlx->height)
		box->y_max = mlx->height;
	if (box->y >= 0)
		box->y_range = box->y_max - box->y;
	else 
		box->y_range = box->y_max;
}

static inline void	rc_tex(t_mlx *mlx, t_cam *cam, t_ray *ray, t_loop *box)
{
	if (ray->hit == m_door)
		ray->tex = &mlx->tex[tex_door];
	else if (ray->side && ray->y_r_dir > 0)
		ray->tex = &mlx->tex[SO];
	else if (ray->side)
		ray->tex = &mlx->tex[NO];
	else if (ray->x_r_dir > 0)
		ray->tex = &mlx->tex[EA];
	else
		ray->tex = &mlx->tex[WE];
	if (mlx->map[(int)cam->y_pos][(int)cam->x_pos] == m_door &&
		(int)cam->x_pos == ray->x_map && ray->pc_wall > 0.5)
	{
		ray->tex = &mlx->tex[tex_door];
		ray->pc_wall -= 0.5;
	}
	box->y_tex = 0;
	box->x_tex = (int)(ray->pc_wall * (double)ray->tex->width);
	box->y_tex_range = ray->tex->height;
	if ((ray->side == 0 && ray->x_r_dir < 0)
		|| (ray->side && ray->y_r_dir > 0))
		box->x_tex = ray->tex->width - box->x_tex - 1;
}

void	raycasting(t_mlx *mlx, t_cam *cam)
{
	t_ray	ray;
	t_loop	box;

	ptr_map_update(mlx);
	box.x = -1;
	while (++box.x < mlx->width)
	{
		rc_init(mlx, cam, &ray, &box);
		rc_dda(mlx, cam, &ray);
		rc_range(mlx, cam, &ray, &box);
		rc_tex(mlx, cam, &ray, &box);
		if (ray.line_h > ray.tex->height)
			xy_set_tex_y_loop(mlx, ray.tex, &box);
		else
			xy_set_tex_y_tex_loop(mlx, ray.tex, &box);
		mlx->z_buff[box.x] = ray.w_dist;
	}
}
