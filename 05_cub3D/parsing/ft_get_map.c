/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 10:38:58 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/16 14:19:44 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int	ft_parse_map(t_cub *data, int empty)
{
	data->y_map++;
	if (data->first)
	{
		data->last->next = ft_lstnew(data->line);
		data->last = data->last->next;
	}
	else
	{
		data->first = ft_lstnew(data->line);
		data->last = data->first;
	}
	if (!data->last)
		return (ft_error_parser(data, strerror(errno)));
	if (ft_check_map_line(data, empty))
		return (1);
	return (0);
}

static inline int	ft_set_cam_pos(t_cub *data, char *ptr)
{
	if (data->dir)
		return (ft_error_parser(data, ERR_MAP_DIR2));
	data->y_pos = data->y_map;
	data->x_pos = ptr - data->line;
	data->dir = *ptr;
	*ptr = '0';
	return (0);
}

int	ft_check_map_line(t_cub *data, int empty)
{
	register char	*ptr;

	ptr = data->line;
	while (*ptr)
	{
		if (ft_strchr(VALID_NBR, *ptr))
		{
			empty = 0;
			data->nb_spr += (*ptr == '2');
		}
		else if (*ptr == ' ')
			;
		else if (ft_strchr(VALID_DIR, *ptr))
			ft_set_cam_pos(data, ptr);
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

int	ft_create_map(t_cub *data)
{
	int				yx[2];
	register int	**map;
	register char	*line;

	map = malloc(sizeof(int *) * data->y_map);
	if (!(map))
		return (ft_error_parser(data, strerror(errno)));
	data->map = map;
	line = data->first->content;
	yx[0] = -1;
	while (++yx[0] < data->y_map)
	{
		map[yx[0]] = malloc(sizeof(int) * data->x_map);
		if (!(map[yx[0]]))
			return (ft_error_parser(data, strerror(errno)));
		yx[1] = -1;
		while (++yx[1] < data->x_map && line[yx[1]])
			map[yx[0]][yx[1]] = line[yx[1]] - '0';
		while (yx[1] < data->x_map)
			map[yx[0]][yx[1]++] = ' ' - '0';
		data->first = ft_lst_pop(data->first, &free);
		if (data->first)
			line = data->first->content;
	}
	return (0);
}
