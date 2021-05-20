/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 10:38:58 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/17 16:53:24 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parse_map(t_cub *data, int empty)
{
	data->y_max++;
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

int	ft_create_map(t_cub *data)
{
	int				yx[2];
	register int	**map;
	register char	*line;

	map = malloc(sizeof(int *) * data->y_max);
	if (!(map))
		return (ft_error_parser(data, strerror(errno)));
	data->map = map;
	line = data->first->content;
	yx[0] = -1;
	while (++yx[0] < data->y_max)
	{
		map[yx[0]] = malloc(sizeof(int) * data->x_max);
		if (!(map[yx[0]]))
			return (ft_error_parser(data, strerror(errno)));
		yx[1] = -1;
		while (++yx[1] < data->x_max && line[yx[1]])
			map[yx[0]][yx[1]] = line[yx[1]] - '0';
		while (yx[1] < data->x_max)
			map[yx[0]][yx[1]++] = ' ' - '0';
		data->first = ft_lst_pop(data->first, &free);
		if (data->first)
			line = data->first->content;
	}
	return (0);
}
