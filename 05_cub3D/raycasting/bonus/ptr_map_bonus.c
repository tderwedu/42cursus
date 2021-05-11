/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:50:38 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/11 11:44:51 by tderwedu         ###   ########.fr       */
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

int	ptr_map_fill(t_mlx *mlx, void ***ptr)
{
	int		y;
	int		x;
	t_TEX_DOOR	*TEX_DOOR;

	y = -1;
	while (++y < mlx->y_max)
	{
		x = -1;
		while (++x < mlx->x_max)
		{
			if (mlx->map[y][x] == 3)
			{
				TEX_DOOR = malloc(sizeof(t_TEX_DOOR));
				if (!(TEX_DOOR))
					return (rc_error(mlx, strerror(errno)));
				TEX_DOOR->updated = 0;
				TEX_DOOR->angle = 90.0;
				TEX_DOOR->moving = 0.0;
				ptr[y][x] = (void *)TEX_DOOR;
			}
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
				((t_TEX_DOOR *)mlx->ptr[y][x])->updated = 0;
		}
	}
}
