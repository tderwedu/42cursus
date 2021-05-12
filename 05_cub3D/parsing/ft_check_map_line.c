/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 09:06:10 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/12 09:50:05 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline int	ft_set_cam_pos(t_cub *data, char *ptr)
{
	if (data->dir)
		return (ft_error_parser(data, ERR_MAP_DIR2));
	data->y_pos = data->y_max;
	data->x_pos = ptr - data->line;
	data->dir = *ptr;
	*ptr = '0';
	return (0);
}

static inline void	ft_check_map_nbr(t_cub *data, int *empty, int val)
{
	*empty = 0;
	if (val >= m_spr && val <= m_kfc)
		data->nb_spr++;
	else if (val == m_door)
		data->nb_door++;
}

int	ft_check_map_line(t_cub *data, int empty)
{
	register char	*ptr;

	ptr = data->line - 1;
	while (*++ptr)
	{
		if (ft_strchr(VALID_NBR, *ptr))
			ft_check_map_nbr(data, &empty, *ptr - '0');
		else if (*ptr == ' ')
			;
		else if (ft_strchr(VALID_DIR, *ptr))
		{
			if (ft_set_cam_pos(data, ptr))
				return (1);
		}
		else
			return (ft_error_parser(data, ERR_MAP_CHR));
	}
	if (ptr - data->line > data->x_max)
		data->x_max = ptr - data->line;
	if (empty)
		return (ft_error_parser(data, ERR_MAP_EMPTY));
	return (0);
}
