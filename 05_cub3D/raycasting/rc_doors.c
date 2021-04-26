/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_doors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 09:45:24 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/26 19:46:33 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

#define DOOR_SPEED	5.0 * M_PI / 180


typedef struct	s_door
{
	int		updated;
	double	angle;
	double	moving;
	double	y_ray;
	double	dx;
	double	y_leaf_1;
	double	y_leaf_2;
	double	y_1_min;
	double	y_1_max;
	double	y_2_min;
	double	y_2_max;
}				t_door;

static inline void	rc_set_limits(t_door *door)
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

void	rc_update_door_leaf(t_cam *cam, t_ray *ray, t_door *door)
{
	double	slope;
	double	cos_leaf;
	double	sin_leaf;

	if (door->moving)
		door->angle += door->moving * DOOR_SPEED;
	if (door->angle > M_PI_2)
		door->angle = M_PI_2;
	else if (door->angle < 0.0)
		door->angle = 0.0;
	cos_leaf = 0.5 * cos(door->angle);
	sin_leaf = 0.5 * sin(door->angle);
	door->dx = ray->x_map + 0.5 - cam->x_pos;
	door->y_ray = (ray->y_r_dir / ray->x_r_dir) + cam->y_pos - ray->y_map;
	door->y_ray *= door->dx;
	slope = (ray->y_map - cam->y_pos + cos_leaf) / (door->dx + sin_leaf);
	door->y_leaf_1 = cos_leaf - sin_leaf * slope;
	slope = (ray->y_map - cam->y_pos + 1.0 - cos_leaf) / (door->dx + sin_leaf);
	door->y_leaf_2 = 1.0 - cos_leaf - sin_leaf * slope;
	rc_set_limits(door);
	door->updated = 1;
}

int	rc_is_door_leaf(t_cam *cam, t_ray *ray)
{

	t_door	door;

	if (y_ray < y_1_min || y_ray > y_2_max)
		return (0);
	if (angle == 90.0 * M_PI / 180.0)
	{
		if (y_ray > y_1_max && y_ray < y_2_min)
			return (0);
		ray->y_map += ray->y_step;
		ray->w_dist = (ray->y_map - cam->y_pos + (1.0 - ray->y_step) / 2.0) / ray->y_r_dir;
		ray->pc_wall = cam->x_pos + ray->w_dist * ray->x_r_dir;
		ray->pc_wall = ray->pc_wall - (int)ray->pc_wall;
		return 1;
	}
	if (y_ray <= y_1_max)
	{
		ray->pc_wall = 0.5 * y_ray / y_leaf_1;
		ray->w_dist = (dx + sin_leaf * (y_ray / y_leaf_1)) / ray->x_r_dir;
		return 1;
	}
	else if(y_ray >= y_2_min)
	{
		ray->pc_wall = 0.5 * (y_ray - y_leaf_2) / (1.0 - y_leaf_2) + 0.5;
		ray->w_dist = (dx + sin_leaf * ((1.0 - y_ray) / (1.0 - y_leaf_2))) / ray->x_r_dir;
		return 1;
	}
	return 0;
}
