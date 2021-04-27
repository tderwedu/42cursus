/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_ptr_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:50:38 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/27 12:10:38 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int	ft_create_ptr_map(t_mlx *mlx)
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
	if (ft_fill_ptr_map(mlx, ptr))
		return (1);
	return (0);
}

int	ft_fill_ptr_map(t_mlx *mlx, void ***ptr)
{
	int		y;
	int		x;
	t_door	*door;

	y = -1;
	while (++y < mlx->y_max)
	{
		x = -1;
		while (++x < mlx->x_max)
		{
			if (mlx->map[y][x] == 3)
			{
				door = malloc(sizeof(t_door));
				if (!(door))
					return (rc_error(mlx, strerror(errno)));
				door->updated = 0;
				door->angle = 90.0;
				door->moving = 0.0;
				ptr[y][x] = (void *)door;
			}
			else
				mlx->ptr[y][x] = NULL;
		}
	}
	return (0);
}

void	ft_update_ptr_map(t_mlx *mlx)
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
