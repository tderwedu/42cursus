/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_4_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:00:50 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/14 19:28:34 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_4_walls(t_mlx *mlx, double new_y, double new_x, double dt)
{
	int	y;
	int	x;

	x = (int)(new_x);
	y = (int)(new_y);
	if (mlx->map[y][x] == m_secret)
		return (0);
	y = (int)(new_y + dt);
	if (mlx->map[y][x] == m_wall)
		return (1);
	y = (int)(new_y - dt);
	if (mlx->map[y][x] == m_wall)
		return (1);
	y = (int)(new_y);
	x = (int)(new_x + dt);
	if (mlx->map[y][x] == m_wall)
		return (1);
	x = (int)(new_x - dt);
	if (mlx->map[y][x] == m_wall)
		return (1);
	return (0);
}

int	check_4_collisions(t_mlx *mlx, double new_y, double new_x, double dt)
{
	int		map;
	double	y;
	double	x;
	t_spr	*spr;
	t_door	*door;

	map = mlx->map[(int)new_y][(int)new_x];
	if (check_4_walls(mlx, new_y, new_x, dt))
		return (1);
	else if (map == m_spr)
	{
		spr = mlx->ptr[(int)new_y][(int)new_x];
		y = new_y - spr->y_pos;
		x = new_x - spr->x_pos;
		dt += 0.25;
		if ((y >= -dt && y <= dt) && (x >= -dt && x <= dt))
			return (1);
	}
	else if (map == m_door)
	{
		door = mlx->ptr[(int)new_y][(int)new_x];
		return ((door->angle == 0.0));
	}
	return (0);
}

void	check_4_knife(t_mlx *mlx, t_cam *cam)
{
	int		y_map;
	int		x_map;
	t_spr	*spr;
	double	y;
	double	x;

	y_map = (int)cam->y_pos;
	x_map = (int)cam->x_pos;
	if (mlx->map[y_map][x_map] == m_knife)
	{
		y = cam->y_pos - y_map;
		x = cam->x_pos - x_map;
		if (y >= 0.25 && y <= 0.75 && x >= 0.25 && x <= 0.75)
		{
			mlx->knife = 1;
			spr = (t_spr *)mlx->ptr[y_map][x_map];
			spr->dead = 1;
			spr->show = 0;
		}
	}
}

void	check_4_kfc(t_mlx *mlx, t_cam *cam)
{
	double	y;
	double	x;
	t_spr	*spr;

	if (mlx->map[(int)cam->y_pos][(int)cam->x_pos] == m_kfc)
	{
		spr = (t_spr *)mlx->ptr[(int)cam->y_pos][(int)cam->x_pos];
		y = cam->y_pos - spr->y_pos;
		x = cam->x_pos - spr->x_pos;
		if (y >= -0.15 && y <= 0.15 && x >= -0.15 && x <= 0.15)
		{
			if (spr->dead && spr->show)
			{
				mlx->life_bar += 2;
				spr->show = 0;
			}
			else if (!spr->dead)
				mlx->life_bar--;
			if (mlx->life_bar > 8)
				mlx->life_bar = 8;
		}
	}
}
