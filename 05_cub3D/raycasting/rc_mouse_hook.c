/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:44:02 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/23 08:50:26 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"


void	rc_mouse_hook(t_mlx *mlx)
{
	int x;
	int y;

	mlx_mouse_get_pos(mlx->mlx, mlx->win, &x, &y);
	rc_mouse_pitch(mlx, mlx->cam, y);
	rc_mouse_yaw(mlx, mlx->cam, x);
}

void	rc_mouse_pitch(t_mlx *mlx, t_cam *cam, int y)
{
	double	delta;

	delta = mlx->height_2 - y;
	if (delta > 0.35 * mlx->height_2)
		delta = 0.30 * mlx->height_2;
	else if (delta > 0.05 * mlx->height_2)
		delta -= 0.05 * mlx->height_2;
	else if (delta < -0.35 * mlx->height_2)
		delta = -0.35 * mlx->height_2;
	else if (delta < -0.05 * mlx->height_2)
		delta += 0.05 * mlx->height_2;
	else
		delta = 0.0;
	cam->pitch = delta;
	cam->height_pitch = mlx->height_2 + cam->pitch;
}

void	rc_mouse_yaw(t_mlx *mlx, t_cam *cam, int x)
{
	double	delta;
	double	old_x_dir;
	double	old_x_plane;
	double	rc_cos;
	double	rc_sin;

	delta = mlx->width_2 - x;
	if (delta > 0.125 * mlx->width_2)
		delta /= mlx->width_2;
	else if (delta < -0.125 * mlx->width_2)
		delta /= mlx->width_2;
	else
		delta = 0.0;
	rc_sin = sin(TURN_SPEED * delta / 256);
	rc_cos = cos(TURN_SPEED * delta / 256);
	old_x_dir = cam->x_dir;
	old_x_plane = cam->x_plane;
	cam->x_dir = cam->x_dir * rc_cos + cam->y_dir * rc_sin;
	cam->y_dir = old_x_dir * -rc_sin + cam->y_dir * rc_cos;
	cam->x_plane = cam->x_plane * rc_cos + cam->y_plane * rc_sin;
	cam->y_plane = old_x_plane * -rc_sin + cam->y_plane * rc_cos;
}
