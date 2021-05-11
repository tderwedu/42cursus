/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:45:39 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/11 15:54:33 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mmap_draw_square(t_img *img, int y_0, int x_0, t_u32 rgb)
{
	int				x;
	int				y_max;
	register t_u32	*dst;

	y_0 *= SQ;
	y_max = y_0 + SQ;
	y_0--;
	while (++y_0 < y_max)
	{
		dst = img->addr + y_0 * img->sl + x_0 * SQ;
		x = -1;
		while (++x < SQ)
			*dst++ = rgb;
	}
}

void	mmap_draw_edge(t_img *img, t_mini *map)
{
	int	x;
	int	y_draw;

	x = map->x_min - 1;
	y_draw = map->y_max + 2 - map->y_min;
	while (++x < (map->x_max + 2))
	{
		mmap_draw_square(img, 1, x - map->x_min + 1, RGB_EDGE);
		mmap_draw_square(img, y_draw, x - map->x_min + 1, RGB_EDGE);
	}
}

void	mmap_draw_player_pos(t_cam *cam, t_img *img, t_mini *map)
{
	int				x;
	int				y_pos;
	int				x_pos;
	int				y_max;
	register t_u32	*dst;

	y_pos = (int)((cam->y_pos + 2.0 - map->y_min) * (double)SQ) - SQ / 2;
	x_pos = (int)((cam->x_pos + 2.0 - map->x_min) * (double)SQ) - SQ / 2;
	y_max = y_pos + SQ / 2;
	while (++y_pos < y_max)
	{
		dst = img->addr + y_pos * img->sl + x_pos;
		x = -1;
		while (++x < (SQ / 2))
			*dst++ = RGB_PLAYER;
	}
}
