/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:50:38 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/12 18:03:48 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ptr_map_create(t_mlx *mlx)
{
	int		y;
	void	***ptr;

	ptr = malloc(sizeof(void **) * mlx->y_max);
	if (!(ptr))
		return (rc_error(mlx, strerror(errno)));
	mlx->ptr = ptr;
	y = -1;
	while (++y < mlx->y_max)
	{
		ptr[y] = malloc(sizeof(void *) * mlx->x_max);
		if (!(ptr[y]))
			return (rc_error(mlx, strerror(errno)));
	}
	ptr_map_fill(mlx, ptr);
	return (0);
}

void	ptr_map_fill_door(t_mlx *mlx, void ***ptr, int y, int x)
{
	mlx->door->updated = 0;
	mlx->door->angle = 0.0;
	mlx->door->moving = 0.0;
	ptr[y][x] = (void *)mlx->door;
	mlx->door++;
}

void	ptr_map_fill_spr(t_mlx *mlx, void ***ptr, int y, int x)
{
	t_spr	*tab;

	tab = mlx->tab;
	while (tab)
	{
		if ((int)tab->y_pos == y && (int)tab->x_pos == x)
			break ;
		else
			tab++;
	}
	ptr[y][x] = (void *)tab;
}

void	ptr_map_fill(t_mlx *mlx, void ***ptr)
{
	int		y;
	int		x;
	t_door	*door;

	door = mlx->door;
	y = -1;
	while (++y < mlx->y_max)
	{
		x = -1;
		while (++x < mlx->x_max)
		{
			if (mlx->map[y][x] == m_door)
				ptr_map_fill_door(mlx, ptr, y, x);
			else if (mlx->map[y][x] >= m_spr && mlx->map[y][x] <= m_kfc)
				ptr_map_fill_spr(mlx, ptr, y, x);
			else
				mlx->ptr[y][x] = NULL;
		}
	}
	mlx->door = door;
}

void	ptr_map_update(t_mlx *mlx)
{
	int		y;
	int		x;

	y = -1;
	while (++y < mlx->y_max)
	{
		x = -1;
		while (++x < mlx->x_max)
		{
			if (mlx->map[y][x] == m_door)
				((t_door *)mlx->ptr[y][x])->updated = 0;
		}
	}
}
