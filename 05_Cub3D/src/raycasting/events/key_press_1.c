/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:17:33 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/25 08:58:29 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_mlx *mlx)
{
	t_cam	*cam;

	cam = mlx->cam;
	if (BONUS)
	{
		if (keycode == K_CTRL)
			press_crouch(mlx, cam);
		else if (keycode == K_SPACE)
			press_jump(mlx, cam);
	}
	if (keycode == K_ESC)
		rc_exit(mlx);
	if (keycode == K_W_FWD || keycode == K_W_BWD
		|| keycode == A_W_FWD || keycode == A_W_BWD)
		press_walk(keycode, mlx, cam);
	if (keycode == K_S_L || keycode == K_S_R)
		press_strafe(keycode, mlx, cam);
	if (keycode == K_T_R || keycode == K_T_L
		|| keycode == A_T_R || keycode == A_T_L)
		press_turn(keycode, cam);
	new_frame(mlx);
	return (1);
}

void	press_walk(int keycode, t_mlx *mlx, t_cam *cam)
{
	double	new_x;
	double	new_y;

	new_y = 0.0;
	new_x = 0.0;
	if (keycode == K_W_FWD || keycode == A_W_FWD)
	{
		new_x = cam->x_pos + cam->x_dir * WALK_SPEED;
		new_y = cam->y_pos + cam->y_dir * WALK_SPEED;
	}
	else
	{
		new_x = cam->x_pos - cam->x_dir * WALK_SPEED;
		new_y = cam->y_pos - cam->y_dir * WALK_SPEED;
	}
	if (!check_4_collisions(mlx, new_y, new_x, 0.25))
	{
		cam->x_pos = new_x;
		cam->y_pos = new_y;
		if (!mlx->knife)
			check_4_knife(mlx, cam);
		check_4_kfc(mlx, cam);
	}
}

void	press_strafe(int keycode, t_mlx *mlx, t_cam *cam)
{
	double	new_x;
	double	new_y;

	new_y = 0.0;
	new_x = 0.0;
	if (keycode == K_S_L)
	{
		new_x = cam->x_pos - cam->x_plane * WALK_SPEED;
		new_y = cam->y_pos - cam->y_plane * WALK_SPEED;
	}
	else
	{
		new_x = cam->x_pos + cam->x_plane * WALK_SPEED;
		new_y = cam->y_pos + cam->y_plane * WALK_SPEED;
	}
	if (!check_4_collisions(mlx, new_y, new_x, 0.25))
	{
		cam->x_pos = new_x;
		cam->y_pos = new_y;
		if (!mlx->knife)
			check_4_knife(mlx, cam);
		check_4_kfc(mlx, cam);
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
	if (keycode == K_T_R || keycode == A_T_R)
	{
		old_x_dir = cam->x_dir;
		old_x_plane = cam->x_plane;
		cam->x_dir = cam->x_dir * rc_cos + cam->y_dir * rc_sin;
		cam->y_dir = old_x_dir * -rc_sin + cam->y_dir * rc_cos;
		cam->x_plane = cam->x_plane * rc_cos + cam->y_plane * rc_sin;
		cam->y_plane = old_x_plane * -rc_sin + cam->y_plane * rc_cos;
	}
	else
	{
		old_x_dir = cam->x_dir;
		old_x_plane = cam->x_plane;
		cam->x_dir = cam->x_dir * rc_cos - cam->y_dir * rc_sin;
		cam->y_dir = old_x_dir * rc_sin + cam->y_dir * rc_cos;
		cam->x_plane = cam->x_plane * rc_cos - cam->y_plane * rc_sin;
		cam->y_plane = old_x_plane * rc_sin + cam->y_plane * rc_cos;
	}
}
