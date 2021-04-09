/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 10:38:58 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/09 17:57:31 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int					ft_map_parse(t_cub* data)
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
	if (ft_map_check_line(data))
		return (1);
	return (0);	
}


static inline int	ft_set_player_pos(t_cub* data, char *ptr)
{
	if (data->dir)
		return (ft_error_parser(data, ERR_MAP_DIR));
	data->y_pos = data->y_map;
	data->x_pos = ptr - data->line;
	data->dir = *ptr;
	*ptr = '0';
	return (0);
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
	register int	y;
	register int	**map;
	register char	*line;

	if (!(map = malloc(sizeof(int*) * data->y_map)))
		return (ft_error_parser(data, strerror(errno)));
	data->map = map;
	data->last = data->first;
	line = data->last->content;
	y = -1;
	while (++y < data->y_map)
	{
		if (!(map[y] = malloc(sizeof(int) * data->x_map)))
			return (ft_error_parser(data, strerror(errno)));
		x = -1;
		while (++x < data->x_map && line[x])
			map[y][x] = line[x] - '0';
		while (x < data->x_map)
			map[y][x++] = ' ' - '0';
		data->last = data->last->next;
		if (data->last)
			line = data->last->content;
	}
	return (0);
}
