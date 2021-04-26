/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_doors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 09:45:24 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/26 15:58:41 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

#define APERTURE	90.0 * M_PI / 180

int	rc_is_door_leaf(t_cam *cam, t_ray *ray)
{
	double	dt_x;
	double	slope;
	double	y_ray;
	double	cos_leaf;
	double	sin_leaf;
	double	y_leaf_1;
	double	y_leaf_2;

	dt_x = ray->x_map + 0.5 - cam->x_pos;
	y_ray = dt_x * (ray->y_r_dir / ray->x_r_dir) + cam->y_pos - ray->y_map;
	
	cos_leaf = 0.5 * cos(APERTURE);
	sin_leaf = 0.5 * sin(APERTURE);
	slope = (ray->y_map - cam->y_pos + cos_leaf) / (ray->x_map + 0.5 + sin_leaf - cam->x_pos);
	y_leaf_1 = cos_leaf - sin_leaf * slope;
	slope = (ray->y_map - cam->y_pos + 1.0 - cos_leaf) / (ray->x_map + 0.5 + sin_leaf - cam->x_pos);
	y_leaf_2 = 1.0 - cos_leaf - sin_leaf * slope;

	if (y_ray >= 0.0 && y_ray <= y_leaf_1)
	{
		ray->pc_wall = 0.5 * y_ray / y_leaf_1;
		ray->w_dist = (dt_x + (sin_leaf) * (y_ray / y_leaf_1)) / ray->x_r_dir;
		return 1;
	}
	if (y_ray >= y_leaf_2 && y_ray <= 1.0)
	{
		ray->pc_wall = 0.5 * (y_ray - y_leaf_2) / (1.0 - y_leaf_2) + 0.5;
		ray->w_dist = (dt_x + (sin_leaf) * ((1.0 - y_ray) / (1.0 - y_leaf_2))) / ray->x_r_dir;
		return 1;
	}
	return 0;
}

// int	rc_is_door_leaf(t_cam *cam, t_ray *ray)
// {
// 	double	dt_x;
// 	double	y_ray;
	
// 	dt_x = ray->x_map + 0.5 - cam->x_pos;
// 	y_ray = dt_x * (ray->y_r_dir / ray->x_r_dir) + cam->y_pos - ray->y_map;
// 	printf("cos: %4.6f \n", cos(APERTURE) / 2.0);
// 	if (APERTURE == 90.0)
// 	{
// 		ray->side = 1;
// 		ray->w_dist = (ray->y_map - cam->y_pos + (1.0 - ray->y_step) / 2.0) / ray->y_r_dir;
// 		ray->pc_wall = cam->x_pos + ray->w_dist * ray->x_r_dir;
// 		return 1;
// 	}
// 	if (y_ray >= 0.0 && y_ray <= cos(APERTURE) / 2.0)
// 	{
// 		ray->pc_wall = y_ray / cos(APERTURE);
// 		ray->w_dist = (ray->x_map - cam->x_pos + 0.5 + tan(APERTURE) * y_ray / 2.0) / ray->x_r_dir;
// 		// printf("y_ray: %4.6f | pc_wall: %4.2f | w_dist: %4.2f\n", y_ray, ray->pc_wall, ray->w_dist);
// 		return 1;
// 	}
// 	y_ray = 1.0 - y_ray;
// 	if (y_ray >= 0.0 && y_ray <= cos(APERTURE) / 2.0)
// 	{
// 		ray->pc_wall = 1.0 - y_ray / cos(APERTURE);
// 		ray->w_dist = (ray->x_map - cam->x_pos + 0.5 + tan(APERTURE) * y_ray / 2.0) / ray->x_r_dir;
// 		// printf(" y_ray: %4.6f | pc_wall: %4.2f | w_dist: %4.2f\n", y_ray, ray->pc_wall, ray->w_dist);
// 		return 1;
// 	}
// 	return 0;
// }

// int	rc_is_door_leaf(t_mlx *mlx, t_cam *cam, t_ray *ray)
// {
// 	double	dt_x;
// 	double	y_ray;
// 	double	y_mid;
	
// 	(void)mlx;
// 	dt_x = ray->x_map + 0.5 - cam->x_pos;
// 	y_ray = dt_x * (ray->y_r_dir / ray->x_r_dir) + cam->y_pos;
// 	y_mid = ray->y_map + APERTURE / 2.0;
// 	if (y_ray > ray->y_map && y_ray < y_mid)
// 		ray->x_step = 0;
// 	y_mid = ray->y_map + 1.0 - APERTURE / 2.0;
// 	if (y_ray > y_mid && y_ray < (ray->y_map + 1))
// 		ray->x_step = 0;
// 	if (!ray->x_step)
// 		return 1;
// 	return 0;
// }
