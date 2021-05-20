/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:45:39 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/19 09:41:12 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mmap_draw_square(t_mlx *mlx, int y_0, int x_0, t_u32 rgb)
{
	int				x;
	int				y_max;
	register t_u32	*dst;

	y_0 *= mlx->sq;
	y_max = y_0 + mlx->sq;
	y_0--;
	while (++y_0 < y_max)
	{
		dst = mlx->img->addr + y_0 * mlx->img->sl + x_0 * mlx->sq;
		x = -1;
		while (++x < mlx->sq)
			*dst++ = rgb;
	}
}

void	mmap_draw_edge(t_mlx *mlx, t_mini *map)
{
	int	x;
	int	y_draw;

	x = map->x_min - 1;
	y_draw = map->y_max + 2 - map->y_min;
	while (++x < (map->x_max + 2))
	{
		mmap_draw_square(mlx, 1, x - map->x_min + 1, RGB_EDGE);
		mmap_draw_square(mlx, y_draw, x - map->x_min + 1, RGB_EDGE);
	}
}

void	mmap_draw_player_pos(t_mlx *mlx, t_img *img, t_mini *map)
{
	int				x;
	int				y_pos;
	int				x_pos;
	int				y_max;
	register t_u32	*dst;

	y_pos = (int)((mlx->cam->y_pos + 2.0 - map->y_min) * mlx->sq);
	y_pos -= mlx->sq / 2;
	x_pos = (int)((mlx->cam->x_pos + 2.0 - map->x_min) * mlx->sq);
	x_pos -= mlx->sq / 2;
	y_max = y_pos + mlx->sq / 2;
	while (++y_pos < y_max)
	{
		dst = img->addr + y_pos * img->sl + x_pos;
		x = -1;
		while (++x < (mlx->sq / 2))
			*dst++ = RGB_PLAYER;
	}
}
