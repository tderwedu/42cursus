/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:17:33 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/11 18:34:46 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_mlx *mlx)
{
	t_cam	*cam;

	cam = mlx->cam;
	if (keycode == KEY_ESCAPE)
		rc_exit(mlx);
	else if (keycode == KEY_WALK_FWD || keycode == KEY_WALK_BWK)
		rc_press_walk(keycode, mlx, cam);
	else if (keycode == KEY_STRAFE_L || keycode == KEY_STRAFE_R)
		rc_press_strafe(keycode, mlx, cam);
	else if (keycode == KEY_TURN_R || keycode == KEY_TURN_L)
		rc_press_turn(keycode, cam);
	else if (keycode == KEY_CTRL)
		rc_press_crouch(mlx, cam);
	else if (keycode == KEY_CTRL)
		rc_press_crouch(mlx, cam);
	else if (keycode == KEY_SPACE)
		rc_press_jump(mlx, cam);
	else
		return (0);
	new_frame(mlx);
	return (0);
}

void	press_walk(int keycode, t_mlx *mlx, t_cam *cam)
{
	double	new_x;
	double	new_y;

	if (keycode == KEY_WALK_FWD)
	{
		new_x = cam->x_pos + cam->x_dir * WALK_SPEED * F_WALL;
		new_y = cam->y_pos + cam->y_dir * WALK_SPEED * F_WALL;
		if (mlx->map[(int)new_y][(int)new_x] != 1)
		{
			cam->x_pos = cam->x_pos + cam->x_dir * WALK_SPEED;
			cam->y_pos = cam->y_pos + cam->y_dir * WALK_SPEED;
		}
	}
	else
	{
		new_x = cam->x_pos - cam->x_dir * WALK_SPEED * F_WALL;
		new_y = cam->y_pos - cam->y_dir * WALK_SPEED * F_WALL;
		if (mlx->map[(int)new_y][(int)new_x] != 1)
		{
			cam->x_pos = cam->x_pos - cam->x_dir * WALK_SPEED;
			cam->y_pos = cam->y_pos - cam->y_dir * WALK_SPEED;
		}
	}
}

void	press_strafe(int keycode, t_mlx *mlx, t_cam *cam)
{
	double	new_x;
	double	new_y;

	if (keycode == KEY_STRAFE_L)
	{
		new_x = cam->x_pos - cam->x_plane * WALK_SPEED * F_WALL;
		new_y = cam->y_pos - cam->y_plane * WALK_SPEED * F_WALL;
		if (mlx->map[(int)new_y][(int)new_x] != 1)
		{
			cam->x_pos = cam->x_pos - cam->x_plane * WALK_SPEED;
			cam->y_pos = cam->y_pos - cam->y_plane * WALK_SPEED;
		}
	}
	else
	{
		new_x = cam->x_pos + cam->x_plane * WALK_SPEED * F_WALL;
		new_y = cam->y_pos + cam->y_plane * WALK_SPEED * F_WALL;
		if (mlx->map[(int)new_y][(int)new_x] != 1)
		{
			cam->x_pos = cam->x_pos + cam->x_plane * WALK_SPEED;
			cam->y_pos = cam->y_pos + cam->y_plane * WALK_SPEED;
		}
	}
}

void	press_turn(int keycode, t_cam *cam)
{
	double	old_x_dir;
	double	old_x_plane;
	double	rc_cos;
	double	rc_sin;

	rc_cos = cos(TURN_SPEED);
	rc_sin = sin(TURN_SPEED);
	if (keycode == KEY_TURN_R)
	{
		old_x_dir = cam->x_dir;
		old_x_plane = cam->x_plane;
		cam->x_dir = cam->x_dir * rc_cos + cam->y_dir * rc_sin;
		cam->y_dir = old_x_dir * -rc_sin + cam->y_dir * rc_cos;
		cam->x_plane = cam->x_plane * rc_cos + cam->y_plane * rc_sin;
		cam->y_plane = old_x_plane * -rc_sin + cam->y_plane * rc_cos;
	}
	if (keycode == KEY_TURN_L)
	{
		old_x_dir = cam->x_dir;
		old_x_plane = cam->x_plane;
		cam->x_dir = cam->x_dir * rc_cos - cam->y_dir * rc_sin;
		cam->y_dir = old_x_dir * rc_sin + cam->y_dir * rc_cos;
		cam->x_plane = cam->x_plane * rc_cos - cam->y_plane * rc_sin;
		cam->y_plane = old_x_plane * rc_sin + cam->y_plane * rc_cos;
	}
}
