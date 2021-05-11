/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:50:38 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/11 19:19:57 by tderwedu         ###   ########.fr       */
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
	if (ptr_map_fill(mlx, ptr))
		return (1);
	return (0);
}

int	ptr_map_fill_door(t_mlx *mlx, void ***ptr, int y, int x)
{
	t_door	*door;

	door = malloc(sizeof(t_door));
	if (!door)
		return (rc_error(mlx, strerror(errno)));
	door->updated = 0;
	door->angle = 90.0;
	door->moving = 0.0;
	ptr[y][x] = (void *)door;
	return (0);
}

void	ptr_map_fill_spr(t_mlx *mlx, void ***ptr, int y, int x)
{
	t_spr	*tab;

	tab = mlx->tab;
	while (tab)
	{
		if ((int)tab->y_pos == y && (int)tab->x_pos == x)
			break;
		else
			tab++;
	}
	ptr[y][x] = (void *)tab;
}

int	ptr_map_fill(t_mlx *mlx, void ***ptr)
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
				if (ptr_map_fill_door(mlx, ptr, y, x))
					return (1);
			else if (mlx->map[y][x] == m_spr || mlx->map[y][x] == m_kfc)
				ptr_map_fill_spr(mlx, ptr, y, x);
			else
				mlx->ptr[y][x] = NULL;
		}
	}
	return (0);
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
			if (mlx->map[y][x] == 3)
				((t_door *)mlx->ptr[y][x])->updated = 0;
		}
	}
}
