/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:17:33 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/12 18:14:16 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int		ft_key_hook(int keycode, t_mlx *mlx)
{
	t_cam	*cam;
	double		f_wall;
	double		new_x;
	double		new_y;

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
		new_x = cam->pos_x + cam->dir_x * WALK_SPEED * f_wall;
		new_y = cam->pos_y + cam->dir_y * WALK_SPEED *f_wall;
		if (worldMap[(int)new_y][(int)new_x] == 0)
		{
			cam->pos_x = cam->pos_x + cam->dir_x * WALK_SPEED;
			cam->pos_y = cam->pos_y + cam->dir_y * WALK_SPEED;
		}
	}
	if (keycode == KEY_WALK_BACKWARD)
	{
		new_x = cam->pos_x - cam->dir_x * WALK_SPEED * f_wall;
		new_y = cam->pos_y - cam->dir_y * WALK_SPEED * f_wall;
		if (worldMap[(int)new_y][(int)new_x] == 0)
		{
			cam->pos_x = cam->pos_x - cam->dir_x * WALK_SPEED;
			cam->pos_y = cam->pos_y - cam->dir_y * WALK_SPEED;
		}
	}
	if (keycode == KEY_STRAFE_LEFT)
	{
		new_x = cam->pos_x - cam->plane_x * WALK_SPEED * f_wall;
		new_y = cam->pos_y - cam->plane_y * WALK_SPEED * f_wall;
		if (worldMap[(int)new_y][(int)new_x] == 0)
		{
			cam->pos_x = cam->pos_x - cam->plane_x * WALK_SPEED;
			cam->pos_y = cam->pos_y - cam->plane_y * WALK_SPEED;
		}
	}
	if (keycode == KEY_STRAFE_RIGHT)
	{
		new_x = cam->pos_x + cam->plane_x * WALK_SPEED * f_wall;
		new_y = cam->pos_y + cam->plane_y * WALK_SPEED * f_wall;
		if (worldMap[(int)new_y][(int)new_x] == 0)
		{
			cam->pos_x = cam->pos_x + cam->plane_x * WALK_SPEED;
			cam->pos_y = cam->pos_y + cam->plane_y * WALK_SPEED;
		}
	}
	// Rotations : both camera direction and camera plane must be rotated
	if (keycode == KEY_TURN_RIGHT)
	{
		double old_dir_x = cam->dir_x;
		cam->dir_x = cam->dir_x * cos(-TURN_SPEED) - cam->dir_y * sin(-TURN_SPEED);
		cam->dir_y = old_dir_x * sin(-TURN_SPEED) + cam->dir_y * cos(-TURN_SPEED);
		double old_plane_x = cam->plane_x;
		cam->plane_x = cam->plane_x * cos(-TURN_SPEED) - cam->plane_y * sin(-TURN_SPEED);
		cam->plane_y = old_plane_x * sin(-TURN_SPEED) + cam->plane_y * cos(-TURN_SPEED);
	}
	if (keycode == KEY_TURN_LEFT)
	{
		double old_dir_x = cam->dir_x;
		cam->dir_x = cam->dir_x * cos(TURN_SPEED) - cam->dir_y * sin(TURN_SPEED);
		cam->dir_y = old_dir_x * sin(TURN_SPEED) + cam->dir_y * cos(TURN_SPEED);
		double old_plane_x = cam->plane_x;
		cam->plane_x = cam->plane_x * cos(TURN_SPEED) - cam->plane_y * sin(TURN_SPEED);
		cam->plane_y = old_plane_x * sin(TURN_SPEED) + cam->plane_y * cos(TURN_SPEED);
	}
	ft_draw_img(vars);
}
