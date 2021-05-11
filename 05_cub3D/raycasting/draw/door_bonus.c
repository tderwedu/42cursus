/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEX_DOOR_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 09:45:24 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/11 11:34:23 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	TEX_DOOR_extrema(t_TEX_DOOR *TEX_DOOR)
{
	if (TEX_DOOR->y_leaf_1 > 0.0)
	{
		TEX_DOOR->y_1_min = 0.0;
		TEX_DOOR->y_1_max = TEX_DOOR->y_leaf_1;
	}
	else
	{
		TEX_DOOR->y_1_min = TEX_DOOR->y_leaf_1;
		TEX_DOOR->y_1_max = 0.0;
	}
	if (TEX_DOOR->y_leaf_2 < 1.0)
	{
		TEX_DOOR->y_2_min = TEX_DOOR->y_leaf_2;
		TEX_DOOR->y_2_max = 1.0;
	}
	else
	{
		TEX_DOOR->y_2_min = 1.0;
		TEX_DOOR->y_2_max = TEX_DOOR->y_leaf_2;
	}
}

static inline void	move_TEX_DOOR_leaf(t_cam *cam, t_ray *ray, t_TEX_DOOR *TEX_DOOR)
{
	double	slope;
	double	cos_leaf;
	double	sin_leaf;

	if (cam->x_pos >= (ray->x_map - 2) && cam->x_pos <= (ray->x_map + 3) && 
		cam->y_pos >= (ray->y_map - 2) && cam->y_pos <= (ray->y_map + 2))
		TEX_DOOR->moving = 1.0;
	else
		TEX_DOOR->moving = -1.0;
	TEX_DOOR->angle += TEX_DOOR->moving * TEX_DOOR_SPEED;
	if (TEX_DOOR->angle > M_PI_2)
		TEX_DOOR->angle = M_PI_2;
	else if (TEX_DOOR->angle < 0.0)
		TEX_DOOR->angle = 0.0;
	cos_leaf = 0.5 * cos(TEX_DOOR->angle);
	sin_leaf = 0.5 * sin(TEX_DOOR->angle);
	TEX_DOOR->dx = ray->x_map + 0.5 - cam->x_pos;
	slope = (ray->y_map - cam->y_pos + cos_leaf) / (TEX_DOOR->dx + sin_leaf);
	TEX_DOOR->y_leaf_1 = cos_leaf - sin_leaf * slope;
	slope = (ray->y_map - cam->y_pos + 1.0 - cos_leaf) / (TEX_DOOR->dx + sin_leaf);
	TEX_DOOR->y_leaf_2 = 1.0 - cos_leaf - sin_leaf * slope;
	TEX_DOOR_extrema(TEX_DOOR);
	TEX_DOOR->sin_leaf = sin_leaf;
	TEX_DOOR->updated = 1;
}

static inline int	opened_TEX_DOOR(t_cam *cam, t_ray *ray, t_TEX_DOOR *TEX_DOOR, double y_ray)
{
	double	tmp;
	
	if (y_ray > TEX_DOOR->y_1_max && y_ray < TEX_DOOR->y_2_min)
		return (0);
	ray->y_map += ray->y_step;
	tmp = (1.0 - ray->y_step) / 2.0;
	ray->w_dist = (ray->y_map - cam->y_pos + tmp) / ray->y_r_dir;
	ray->pc_wall = cam->x_pos + ray->w_dist * ray->x_r_dir;
	ray->pc_wall = (ray->pc_wall - (int)ray->pc_wall) - 0.5;
	return (1);
}

static inline int	leaf_1(t_ray *ray, t_TEX_DOOR *TEX_DOOR, double y_ray)
{
	double	tmp;

	ray->pc_wall = 0.5 * y_ray / TEX_DOOR->y_leaf_1;
	tmp = (y_ray / TEX_DOOR->y_leaf_1);
	ray->w_dist = (TEX_DOOR->dx + TEX_DOOR->sin_leaf * tmp) / ray->x_r_dir;
	return (1);
}

int	is_TEX_DOOR(t_mlx *mlx, t_cam *cam, t_ray *ray)
{
	t_TEX_DOOR	*TEX_DOOR;
	double	y_ray;
	double	tmp;

	TEX_DOOR = (t_TEX_DOOR *)mlx->ptr[ray->y_map][ray->x_map];
	if (!TEX_DOOR->updated)
		move_TEX_DOOR_leaf(cam, ray, TEX_DOOR);
	y_ray = TEX_DOOR->dx * (ray->y_r_dir / ray->x_r_dir) + cam->y_pos - ray->y_map;
	if (y_ray < TEX_DOOR->y_1_min || y_ray > TEX_DOOR->y_2_max)
		return (0);
	if (TEX_DOOR->angle == M_PI_2)
		return (opened_TEX_DOOR(cam, ray, TEX_DOOR, y_ray));
	if (y_ray <= TEX_DOOR->y_1_max)
		return (leaf_1(ray, TEX_DOOR, y_ray));
	if (y_ray >= TEX_DOOR->y_2_min)
	{
		tmp = (y_ray - TEX_DOOR->y_leaf_2) / (1.0 - TEX_DOOR->y_leaf_2);
		ray->pc_wall = 0.5 * tmp + 0.5;
		tmp = ((1.0 - y_ray) / (1.0 - TEX_DOOR->y_leaf_2));
		ray->w_dist = (TEX_DOOR->dx + TEX_DOOR->sin_leaf * tmp) / ray->x_r_dir;
		return (1);
	}
	return (0);
}

