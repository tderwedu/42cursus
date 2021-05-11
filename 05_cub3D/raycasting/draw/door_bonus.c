/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 09:45:24 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/11 16:00:45 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	door_extrema(t_door *door)
{
	if (door->y_leaf_1 > 0.0)
	{
		door->y_1_min = 0.0;
		door->y_1_max = door->y_leaf_1;
	}
	else
	{
		door->y_1_min = door->y_leaf_1;
		door->y_1_max = 0.0;
	}
	if (door->y_leaf_2 < 1.0)
	{
		door->y_2_min = door->y_leaf_2;
		door->y_2_max = 1.0;
	}
	else
	{
		door->y_2_min = 1.0;
		door->y_2_max = door->y_leaf_2;
	}
}

static inline void	move_door_leaf(t_cam *cam, t_ray *ray, t_door *door)
{
	double	slope;
	double	cos_leaf;
	double	sin_leaf;

	if (cam->x_pos >= (ray->x_map - 2) && cam->x_pos <= (ray->x_map + 3)
		&& cam->y_pos >= (ray->y_map - 2) && cam->y_pos <= (ray->y_map + 2))
		door->moving = 1.0;
	else
		door->moving = -1.0;
	door->angle += door->moving * DOOR_SPEED;
	if (door->angle > M_PI_2)
		door->angle = M_PI_2;
	else if (door->angle < 0.0)
		door->angle = 0.0;
	cos_leaf = 0.5 * cos(door->angle);
	sin_leaf = 0.5 * sin(door->angle);
	door->dx = ray->x_map + 0.5 - cam->x_pos;
	slope = (ray->y_map - cam->y_pos + cos_leaf) / (door->dx + sin_leaf);
	door->y_leaf_1 = cos_leaf - sin_leaf * slope;
	slope = (ray->y_map - cam->y_pos + 1.0 - cos_leaf) / (door->dx + sin_leaf);
	door->y_leaf_2 = 1.0 - cos_leaf - sin_leaf * slope;
	door_extrema(door);
	door->sin_leaf = sin_leaf;
	door->updated = 1;
}

static inline int	opened(t_cam *cam, t_ray *ray, t_door *door, double y_ray)
{
	double	tmp;

	if (y_ray > door->y_1_max && y_ray < door->y_2_min)
		return (0);
	ray->y_map += ray->y_step;
	tmp = (1.0 - ray->y_step) / 2.0;
	ray->w_dist = (ray->y_map - cam->y_pos + tmp) / ray->y_r_dir;
	ray->pc_wall = cam->x_pos + ray->w_dist * ray->x_r_dir;
	ray->pc_wall = (ray->pc_wall - (int)ray->pc_wall) - 0.5;
	return (1);
}

static inline int	leaf_1(t_ray *ray, t_door *door, double y_ray)
{
	double	tmp;

	ray->pc_wall = 0.5 * y_ray / door->y_leaf_1;
	tmp = (y_ray / door->y_leaf_1);
	ray->w_dist = (door->dx + door->sin_leaf * tmp) / ray->x_r_dir;
	return (1);
}

int	is_door(t_mlx *mlx, t_cam *cam, t_ray *ray)
{
	t_door	*door;
	double	y_ray;
	double	tmp;

	door = (t_door *)mlx->ptr[ray->y_map][ray->x_map];
	if (!door->updated)
		move_door_leaf(cam, ray, door);
	y_ray = door->dx * (ray->y_r_dir / ray->x_r_dir) + cam->y_pos - ray->y_map;
	if (y_ray < door->y_1_min || y_ray > door->y_2_max)
		return (0);
	if (door->angle == M_PI_2)
		return (opened(cam, ray, door, y_ray));
	if (y_ray <= door->y_1_max)
		return (leaf_1(ray, door, y_ray));
	if (y_ray >= door->y_2_min)
	{
		tmp = (y_ray - door->y_leaf_2) / (1.0 - door->y_leaf_2);
		ray->pc_wall = 0.5 * tmp + 0.5;
		tmp = ((1.0 - y_ray) / (1.0 - door->y_leaf_2));
		ray->w_dist = (door->dx + door->sin_leaf * tmp) / ray->x_r_dir;
		return (1);
	}
	return (0);
}
