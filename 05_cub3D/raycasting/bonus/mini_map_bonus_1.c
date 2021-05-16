/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 10:32:43 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/16 19:09:26 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_mini_map(t_mlx *mlx)
{
	t_mini	map;
	t_img *img;

	img = mlx->img;
	mmap_set_info(mlx, &map);
	if (map.update)
		mmap_upate_limits(mlx, &map);
	mmap_draw_mmap(mlx, img, &map);
	mmap_draw_edge(img, &map);
	mmap_draw_player_pos(mlx->cam, img, &map);
}

void	mmap_set_info(t_mlx *mlx, t_mini *map)
{
	if (mlx->width <= 320)
		map->size = mlx->width / 80;
	else
		map->size = 4 + mlx->width / 320;
	map->nb_y = mlx->height / (3 * map->size);
	map->nb_x = (mlx->width * 10) / (35 * map->size);
	if (map->nb_y > mlx->y_max)
		map->nb_y = mlx->y_max;
	if (map->nb_x > mlx->x_max)
		map->nb_x = mlx->x_max;
	map->y_min = 0;
	map->x_min = 0;
	map->y_max = map->nb_y;
	map->x_max = map->nb_x;
	map->update = 1;
	if (mlx->y_max <= map->nb_y && mlx->x_max <= map->nb_x)
		map->update = 0;
}

void	mmap_upate_limits(t_mlx *mlx, t_mini *map)
{
	int	tmp;

	tmp = (int)mlx->cam->y_pos;
	map->y_min = tmp - map->nb_y / 2;
	tmp = (int)mlx->cam->x_pos;
	map->x_min = tmp - map->nb_x / 2;
	if (map->y_min < 0)
		map->y_min = 0;
	map->y_max = map->y_min + map->nb_y;
	if (map->x_min < 0)
		map->x_min = 0;
	map->x_max = map->x_min + map->nb_x;
	if (map->y_max > mlx->y_max)
	{
		map->y_max = mlx->y_max;
		map->y_min = map->y_max - map->nb_y;
	}
	if (map->x_max > mlx->x_max)
	{
		map->x_max = mlx->x_max;
		map->x_min = map->x_max - map->nb_x;
	}
}

static inline void	mmap_get_rgb(t_img *img, int val, int y_draw, int x_draw)
{
	if (val == m_empty)
		mmap_draw_square(img, y_draw, x_draw, RGB_FLOOR);
	else if (val == m_wall || val == m_secret)
		mmap_draw_square(img, y_draw, x_draw, RGB_WALL);
	else if (val == m_spr)
		mmap_draw_square(img, y_draw, x_draw, RGB_SPRITE);
	else if (val == m_knife)
		mmap_draw_square(img, y_draw, x_draw, RGB_KNIFE);
	else if (val == m_door)
		mmap_draw_square(img, y_draw, x_draw, RGB_DOOR);
	else if (val == m_kfc)
		mmap_draw_square(img, y_draw, x_draw, RGB_KFC);
	else if (val < 0)
		mmap_draw_square(img, y_draw, x_draw, RGB_EMPTY);
}

void	mmap_draw_mmap(t_mlx *mlx, t_img *img, t_mini *map)
{
	int		y;
	int		x;
	int		y_draw;
	int		x_draw;

	y = map->y_min - 1;
	while (++y < map->y_max)
	{
		y_draw = y + 2 - map->y_min;
		mmap_draw_square(img, y_draw, 1, RGB_EDGE);
		x = map->x_min - 1;
		while (++x < map->x_max)
		{
			x_draw = x + 2 - map->x_min;
			mmap_get_rgb(img, mlx->map[y][x], y_draw, x_draw);
		}
		x_draw = x + 2 - map->x_min;
		mmap_draw_square(img, y_draw, x_draw, RGB_EDGE);
	}
}
