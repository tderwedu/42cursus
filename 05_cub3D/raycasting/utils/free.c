/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:58:07 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/11 16:09:15 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rc_free_mlx(t_mlx *mlx)
{
	int		i;

	i = -1;
	while (++i <= arm_1)
		if (mlx->tex[i].img)
			mlx_destroy_image(mlx->mlx, mlx->tex[i].img);
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->z_buff)
		free(mlx->z_buff);
	if (mlx->tab)
		free(mlx->tab);
	if (mlx->map)
		rc_free_map(mlx);
	if (mlx->ptr)
		rc_free_ptr_map(mlx);
}

void	rc_free_map(t_mlx *mlx)
{
	int		y;

	y = -1;
	while (++y < mlx->y_max)
	{
		if (mlx->map[y])
			free(mlx->map[y]);
	}
	free(mlx->map);
}

void	rc_free_ptr_map(t_mlx *mlx)
{
	int		y;
	int		x;

	y = -1;
	while (++y < mlx->y_max)
	{
		x = -1;
		while (++x < mlx->x_max)
		{
			if (mlx->ptr[y][x])
				free(mlx->ptr[y][x]);
		}
		free(mlx->ptr[y]);
	}
	free(mlx->ptr);
}
