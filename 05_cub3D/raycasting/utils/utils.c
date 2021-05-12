/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:00:50 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/12 10:01:01 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_4_collisions(t_mlx *mlx, double new_y, double new_x, double dt)
{
	int		map;
	double	y;
	double	x;
	t_spr	*spr;

	map = mlx->map[(int)new_y][(int)new_x];
	if (map == m_wall)
		return (1);
	else if (map == m_spr || map == m_kfc)
	{
		spr = mlx->ptr[(int)new_y][(int)new_x];
		y = new_y - spr->y_pos;
		x = new_x - spr->x_pos;
		if (map == m_spr)
			dt += 0.4;
		else
			dt += 0.15;
		if ((y >= -dt && y <= dt) && (x >= -dt && x <= dt))
			return (1);
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
