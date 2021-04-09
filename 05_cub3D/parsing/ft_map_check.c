/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:58:06 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/09 18:16:53 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

static inline int	ft_map_closure_x_bulk(t_cub *data, register int y)
{
	int 			open;
	int				**map;
	register int	x;

	open = 0;
	map = data->map;
	if (map[y][0] > 1 || map[y][0] == 0)
		return (1);
	x = 0;
	while (++x < (data->x_map - 1))
	{
		if (map[y][x] == 1)
			open = 0;
		else if (map[y][x] < 0 && open)
			return (ft_error_map(data, ERR_MAP_NOTCL, y, x));
		else if (map[y][x] == 0 || map[y][x] > 1)
		{
			if (!open && !(map[y][x - 1] == 1))
				return (ft_error_map(data, ERR_MAP_NOTCL, y, x - 1));
			open = 1;
		}
	}
	if (open && !(map[y][x] == 1))
		return (ft_error_map(data, ERR_MAP_NOTCL, y, x));
	return (0);
}

int					ft_check_map_closure_x(t_cub *data)
{
	int				**map;
	register int	x;

	map = data->map;
	x = -1;
	while (++x < data->x_map)
		if (map[0][x] > 1 || map[0][x] == 0)
			return (ft_error_map(data, ERR_MAP_NOTCL, 0, x));
	x = 0;
	while (++x < (data->y_map - 1))
		if (ft_map_closure_x_bulk(data, x))
			return (1);
	x = -1;
	while (++x < data->x_map)
		if (map[data->y_map - 1][x] > 1 || map[data->y_map - 1][x] == 0)
			return (ft_error_map(data, ERR_MAP_NOTCL, data->y_map - 1, x));
	return (0);
}

static inline int	ft_map_closure_y_bulk(t_cub *data, register int x)
{
	int 			open;
	int				**map;
	register int	y;

	open = 0;
	map = data->map;
	if (map[0][x] > 1 || map[0][x] == 0)
		return (1);
	y = 0;
	while (++y < (data->y_map - 1))
	{
		if (map[y][x] == 1)
			open = 0;
		else if (map[y][x] < 0 && open)
			return (ft_error_map(data, ERR_MAP_NOTCL, y, x));
		else if (map[y][x] == 0 || map[y][x] > 1)
		{
			if (!open && !(map[y - 1][x] == 1))
				return (ft_error_map(data, ERR_MAP_NOTCL, y - 1, x));
			open = 1;
		}
	}
	if (open && !(map[y][x] == 1))
		return (ft_error_map(data, ERR_MAP_NOTCL, y, x));
	return (0);
}

int					ft_check_map_closure_y(t_cub *data)
{
	int				**map;
	register int	y;

	map = data->map;
	y = -1;
	while (++y < data->y_map)
		if (map[y][0] > 1 || map[y][0] == 0)
			return (ft_error_map(data, ERR_MAP_NOTCL, y, 0));
	y = 0;
	while (++y < (data->x_map - 1))
		if (ft_map_closure_y_bulk(data, y))
			return (1);
	y = -1;
	while (++y < data->y_map)
		if (map[y][data->x_map - 1] > 1 || map[y][data->x_map - 1] == 0)
			return (ft_error_map(data, ERR_MAP_NOTCL, y, data->x_map - 1));
	return (0);
}
