/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:17:33 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/13 11:46:06 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int		rc_key_hook(int keycode, t_mlx *mlx)
{
	t_cam	*cam;
	double	f_wall;
	double	new_x;
	double	new_y;

	f_wall = 1.5;
	cam = mlx->cam;
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	// Translation : need to check for wall collision
	if (keycode == KEY_WALK_FORWARD)
	{
		new_x = cam->x_pos + cam->x_dir * WALK_SPEED * f_wall;
		new_y = cam->y_pos + cam->y_dir * WALK_SPEED *f_wall;
		if (mlx->map[(int)new_y][(int)new_x] == 0)
		{
			cam->x_pos = cam->x_pos + cam->x_dir * WALK_SPEED;
			cam->y_pos = cam->y_pos + cam->y_dir * WALK_SPEED;
		}
	}
	if (keycode == KEY_WALK_BACKWARD)
	{
		new_x = cam->x_pos - cam->x_dir * WALK_SPEED * f_wall;
		new_y = cam->y_pos - cam->y_dir * WALK_SPEED * f_wall;
		if (mlx->map[(int)new_y][(int)new_x] == 0)
		{
			cam->x_pos = cam->x_pos - cam->x_dir * WALK_SPEED;
			cam->y_pos = cam->y_pos - cam->y_dir * WALK_SPEED;
		}
	}
	if (keycode == KEY_STRAFE_LEFT)
	{
		new_x = cam->x_pos - cam->x_plane * WALK_SPEED * f_wall;
		new_y = cam->y_pos - cam->y_plane * WALK_SPEED * f_wall;
		if (mlx->map[(int)new_y][(int)new_x] == 0)
		{
			cam->x_pos = cam->x_pos - cam->x_plane * WALK_SPEED;
			cam->y_pos = cam->y_pos - cam->y_plane * WALK_SPEED;
		}
	}
	if (keycode == KEY_STRAFE_RIGHT)
	{
		new_x = cam->x_pos + cam->x_plane * WALK_SPEED * f_wall;
		new_y = cam->y_pos + cam->y_plane * WALK_SPEED * f_wall;
		if (mlx->map[(int)new_y][(int)new_x] == 0)
		{
			cam->x_pos = cam->x_pos + cam->x_plane * WALK_SPEED;
			cam->y_pos = cam->y_pos + cam->y_plane * WALK_SPEED;
		}
	}
	// Rotations : both camera direction and camera plane must be rotated
	if (keycode == KEY_TURN_RIGHT)
	{
		double old_x_dir = cam->x_dir;
		cam->x_dir = cam->x_dir * cos(-TURN_SPEED) - cam->y_dir * sin(-TURN_SPEED);
		cam->y_dir = old_x_dir * sin(-TURN_SPEED) + cam->y_dir * cos(-TURN_SPEED);
		double old_x_plane = cam->x_plane;
		cam->x_plane = cam->x_plane * cos(-TURN_SPEED) - cam->y_plane * sin(-TURN_SPEED);
		cam->y_plane = old_x_plane * sin(-TURN_SPEED) + cam->y_plane * cos(-TURN_SPEED);
	}
	if (keycode == KEY_TURN_LEFT)
	{
		double old_x_dir = cam->x_dir;
		cam->x_dir = cam->x_dir * cos(TURN_SPEED) - cam->y_dir * sin(TURN_SPEED);
		cam->y_dir = old_x_dir * sin(TURN_SPEED) + cam->y_dir * cos(TURN_SPEED);
		double old_x_plane = cam->x_plane;
		cam->x_plane = cam->x_plane * cos(TURN_SPEED) - cam->y_plane * sin(TURN_SPEED);
		cam->y_plane = old_x_plane * sin(TURN_SPEED) + cam->y_plane * cos(TURN_SPEED);
	}
	rc_draw_img(mlx);
	return (0);
}
