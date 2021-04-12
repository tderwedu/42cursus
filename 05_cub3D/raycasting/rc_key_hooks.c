/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:17:33 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/12 16:26:36 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int		ft_key_hook(int keycode, t_mlx *mlx)
{
	t_player	*player;
	double		f_wall;
	double		new_x;
	double		new_y;

	f_wall = 1.5;
	player = mlx->player;
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	// Translation : need to check for wall collision
	if (keycode == KEY_WALK_FORWARD)
	{
		new_x = player->pos_x + player->dir_x * WALK_SPEED * f_wall;
		new_y = player->pos_y + player->dir_y * WALK_SPEED *f_wall;
		if (worldMap[(int)new_y][(int)new_x] == 0)
		{
			player->pos_x = player->pos_x + player->dir_x * WALK_SPEED;
			player->pos_y = player->pos_y + player->dir_y * WALK_SPEED;
		}
	}
	if (keycode == KEY_WALK_BACKWARD)
	{
		new_x = player->pos_x - player->dir_x * WALK_SPEED * f_wall;
		new_y = player->pos_y - player->dir_y * WALK_SPEED * f_wall;
		if (worldMap[(int)new_y][(int)new_x] == 0)
		{
			player->pos_x = player->pos_x - player->dir_x * WALK_SPEED;
			player->pos_y = player->pos_y - player->dir_y * WALK_SPEED;
		}
	}
	if (keycode == KEY_STRAFE_LEFT)
	{
		new_x = player->pos_x - player->plane_x * WALK_SPEED * f_wall;
		new_y = player->pos_y - player->plane_y * WALK_SPEED * f_wall;
		if (worldMap[(int)new_y][(int)new_x] == 0)
		{
			player->pos_x = player->pos_x - player->plane_x * WALK_SPEED;
			player->pos_y = player->pos_y - player->plane_y * WALK_SPEED;
		}
	}
	if (keycode == KEY_STRAFE_RIGHT)
	{
		new_x = player->pos_x + player->plane_x * WALK_SPEED * f_wall;
		new_y = player->pos_y + player->plane_y * WALK_SPEED * f_wall;
		if (worldMap[(int)new_y][(int)new_x] == 0)
		{
			player->pos_x = player->pos_x + player->plane_x * WALK_SPEED;
			player->pos_y = player->pos_y + player->plane_y * WALK_SPEED;
		}
	}
	// Rotations : both camera direction and camera plane must be rotated
	if (keycode == KEY_TURN_RIGHT)
	{
		double old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(-TURN_SPEED) - player->dir_y * sin(-TURN_SPEED);
		player->dir_y = old_dir_x * sin(-TURN_SPEED) + player->dir_y * cos(-TURN_SPEED);
		double old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(-TURN_SPEED) - player->plane_y * sin(-TURN_SPEED);
		player->plane_y = old_plane_x * sin(-TURN_SPEED) + player->plane_y * cos(-TURN_SPEED);
	}
	if (keycode == KEY_TURN_LEFT)
	{
		double old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(TURN_SPEED) - player->dir_y * sin(TURN_SPEED);
		player->dir_y = old_dir_x * sin(TURN_SPEED) + player->dir_y * cos(TURN_SPEED);
		double old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(TURN_SPEED) - player->plane_y * sin(TURN_SPEED);
		player->plane_y = old_plane_x * sin(TURN_SPEED) + player->plane_y * cos(TURN_SPEED);
	}
	ft_draw_img(vars);
}
