/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_mmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:18:25 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/19 17:15:14 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

# define RGB_FLOOR	0x00FDAE80
# define RGB_WALL	0x00721A16
# define RGB_SPRITE	0x00945D45
# define RGB_EMPTY	0x002C0C0B
# define RGB_PLAYER	0x000FFFFFF
# define RGB_EDGE	0x00000000
// # define RGB_PLAYER	0x0002517F

# define SQ	6

typedef struct s_mini
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;
	int	nb_x;
	int	nb_y;
	int	size;
	int	update;
}				t_mini;

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
			if (mlx->map[y][x] == 0)
				mmap_draw_square(img, y_draw, x_draw, RGB_FLOOR);
			else if (mlx->map[y][x] == 1)
				mmap_draw_square(img, y_draw, x_draw, RGB_WALL);
			else if (mlx->map[y][x] == 2)
				mmap_draw_square(img, y_draw, x_draw, RGB_SPRITE);
			else if (mlx->map[y][x] < 0)
				mmap_draw_square(img, y_draw, x_draw, RGB_EMPTY);
		}
		x_draw = x + 2 - map->x_min;
		mmap_draw_square(img, y_draw, x_draw, RGB_EDGE);
	}
}

void	mmap_draw_edge(t_img *img, t_mini *map)
{
	int	x;
	int	y_draw;

	x = map->x_min - 1;
	y_draw = map->y_max + 2  - map->y_min;
	while (++x < (map->x_max + 2))
	{
		mmap_draw_square(img, 1, x - map->x_min + 1, RGB_EDGE);
		mmap_draw_square(img, y_draw, x - map->x_min + 1, RGB_EDGE);
	}
}

void	rc_draw_mini_map(t_mlx *mlx, t_img *img)
{
	t_mini	map;

	mmap_set_info(mlx, &map);
	if (map.update)
		mmap_upate_limits(mlx, &map);
	mmap_draw_mmap(mlx, img, &map);
	mmap_draw_edge(img, &map);
	mmap_draw_player_pos(mlx->cam, img, &map);
}