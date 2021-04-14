/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:17:33 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/14 09:50:58 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int	rc_key_hooks(int keycode, t_mlx *mlx)
{
	t_cam	*cam;

	cam = mlx->cam;
	if (keycode == KEY_ESCAPE)
	{
		rc_free_mlx(mlx);
		exit(0);
	}
	else if (keycode == KEY_WALK_FWD || keycode == KEY_WALK_BWK)
		rc_walk(keycode, mlx, cam);
	else if (keycode == KEY_STRAFE_L || keycode == KEY_STRAFE_R)
		rc_strafe(keycode, mlx, cam);
	else if (keycode == KEY_TURN_R || keycode == KEY_TURN_L)
		rc_turn(keycode, cam);
	else
		return (0);
	rc_draw_img(mlx);
	return (0);
}

void	rc_walk(int keycode, t_mlx *mlx, t_cam *cam)
{
	double	new_x;
	double	new_y;

	if (keycode == KEY_WALK_FWD)
	{
		new_x = cam->x_pos + cam->x_dir * WALK_SPEED * F_WALL;
		new_y = cam->y_pos + cam->y_dir * WALK_SPEED *F_WALL;
		if (mlx->map[(int)new_y][(int)new_x] == 0)
		{
			cam->x_pos = cam->x_pos + cam->x_dir * WALK_SPEED;
			cam->y_pos = cam->y_pos + cam->y_dir * WALK_SPEED;
		}
	}
	else
	{
		new_x = cam->x_pos - cam->x_dir * WALK_SPEED * F_WALL;
		new_y = cam->y_pos - cam->y_dir * WALK_SPEED * F_WALL;
		if (mlx->map[(int)new_y][(int)new_x] == 0)
		{
			cam->x_pos = cam->x_pos - cam->x_dir * WALK_SPEED;
			cam->y_pos = cam->y_pos - cam->y_dir * WALK_SPEED;
		}
	}
}

void	rc_strafe(int keycode, t_mlx *mlx, t_cam *cam)
{
	double	new_x;
	double	new_y;

	if (keycode == KEY_STRAFE_L)
	{
		new_x = cam->x_pos - cam->x_plane * WALK_SPEED * F_WALL;
		new_y = cam->y_pos - cam->y_plane * WALK_SPEED * F_WALL;
		if (mlx->map[(int)new_y][(int)new_x] == 0)
		{
			cam->x_pos = cam->x_pos - cam->x_plane * WALK_SPEED;
			cam->y_pos = cam->y_pos - cam->y_plane * WALK_SPEED;
		}
	}
	else
	{
		new_x = cam->x_pos + cam->x_plane * WALK_SPEED * F_WALL;
		new_y = cam->y_pos + cam->y_plane * WALK_SPEED * F_WALL;
		if (mlx->map[(int)new_y][(int)new_x] == 0)
		{
			cam->x_pos = cam->x_pos + cam->x_plane * WALK_SPEED;
			cam->y_pos = cam->y_pos + cam->y_plane * WALK_SPEED;
		}
	}
}

void	rc_turn(int keycode, t_cam *cam)
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
