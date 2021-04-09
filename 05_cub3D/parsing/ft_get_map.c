/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 10:38:58 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/09 12:10:43 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

static inline int	ft_set_player_pos(t_cub* data, char *ptr)
{
	if (data->dir)
		return (ft_error_parser(data, ERR_MAP_DIR));
	data->y_pos = data->y_map;
	data->x_pos = ptr - data->line;
	data->dir = *ptr;
	*ptr = '0';
}

int					ft_map_check_line(t_cub* data)
{
	int				empty;
	register char	*ptr;

	ptr = data->line;
	empty = 1;
	while (*ptr)
	{
		if (ft_strchr(VALID_NBR, *ptr))
			empty = 0;
		else if (*ptr == ' ')
			;
		else if (ft_strchr(VALID_DIR, *ptr))
			ft_set_player_pos(data, ptr);
		else
			return (ft_error_parser(data, ERR_MAP_CHR));
		ptr++;
	}
	if (ptr - data->line > data->x_map)
		data->x_map = ptr - data->line;
	if (empty)
		return (ft_error_parser(data, ERR_MAP_EMPTY));
	return (0);
}

int					ft_map_create(t_cub* data)
{
	register int	x;
	register int	**map;
	register char	*line;

	if (!(map = malloc(sizeof(int) * data->y_map)))
		return (ft_error_parser(data, strerror(errno)));
	data->map = map;
	data->last = data->first;
	line = data->last->content;
	while ((map - data->map) < data->y_map)
	{
		if (!(map = malloc(sizeof(int) * data->x_map)))
			return (ft_error_parser(data, strerror(errno)));
		x = -1;
		while (++x < data->x_map && line[x])
			map[x] = line[x] - '0';
		while (++x < data->x_map)
			map[x] = ' ' - '0';
		data->last = data->last->next;
		line = data->last->content;
	}
	ft_lstclear(&data->first, &free);
	data->first = NULL;
	data->last = NULL;
	return (0);
}

int				ft_check_closure_x_bulk(t_cub *data, register int *map)
{
	int 			open;
	register int	x;

	open = 0;
	data->x_map--;
	if (map[0] > 1 || map[0] == '0')
		return (1);
	x = 0;
	while (++x < data->x_map)
	{
		if (map[x] > 1 || map[x] == '0')
		{
			if (open == 0 && (map[x - 1] > 1 || map[x - 1] == '0'))
				return (1);
			open = 1;
		}
		else if (map[x] == '1')
			open = 0;
	}
	if (open || (map[x] > 1 || map[x] == '0'))
		return (1);
	data->x_map++;
	return (0);
}

int				ft_map_check_closure_x(t_cub *data)
{
	int				*map;
	register int	x;

	map = data->map;
	x = -1;
	while (++x < data->x_map)
		if (map[x] > 1 || map[x] == '0')
			return ft_error_parser(data, ERR_MAP_NOTCL);
	data->y_map--;
	while ((++map - data->map) < data->y_map)
		if (ft_check_closure_x_bulk(data, map))
			return ft_error_parser(data, ERR_MAP_NOTCL);
	x = -1;
	while (++x < data->x_map)
		if (map[x] > 1 || map[x] == '0')
			return ft_error_parser(data, ERR_MAP_NOTCL);
	return (0);
}

int				ft_check_closure_y_bulk(t_cub *data, register int x)
{
	int 			open;
	int				**map;
	register int	y;

	open = 0;
	data->y_map--;
	if (map[0][x] > 1 || map[0][x] == '0')
		return (1);
	y = 0;
	while (++y < data->y_map)
	{
		if (map[y][x] > 1 || map[y][x] == '0')
		{
			if (open == 0 && (map[y- 1][x] > 1 || map[y- 1][x] == '0'))
				return (1);
			open = 1;
		}
		else if (map[y][x] == '1')
			open = 0;
	}
	if (open || (map[y][x] > 1 || map[y][x] == '0'))
		return (1);
	data->y_map++;
	return (0);
}

int				ft_map_check_closure_y(t_cub *data)
{
	int				**map;
	register int	y;

	map = data->map;
	y = -1;
	while (++y < data->y_map)
		if (map[y][0] > 1 || map[y][0] == '0')
			return ft_error_parser(data, ERR_MAP_NOTCL);
	y = 0;
	data->x_map--;
	while (++y < data->x_map)
		if (ft_check_closure_y_bulk(data, y))
			return ft_error_parser(data, ERR_MAP_NOTCL);
	while (++y < data->y_map)
		if (map[y][data->x_map - 1] > 1 || map[y][data->x_map - 1] == '0')
			return ft_error_parser(data, ERR_MAP_NOTCL);
	return (0);
}
