/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:23:04 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/20 11:59:45 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	ft_init_data(t_cub *data)
{
	int	i;

	i = -1;
	while (++i <= S)
		if (data->tex[i])
			data->tex[i] = NULL;
	data->fd = 0;
	data->dir = 0;
	data->flag = 0;
	data->x_map = 0;
	data->y_map = -1;
	data->x_pos = 0;
	data->y_pos = 0;
	data->width = 0;
	data->height = 0;
	data->nb_spr = 0;
	data->map = NULL;
	data->ptr = NULL;
	data->line = NULL;
	data->last = NULL;
	data->first = NULL;
}

static inline void	ft_free_map(t_cub *data)
{
	int	y;

	y = -1;
	while (++y < data->y_map)
		if (data->map[y])
			free(data->map[y]);
	free(data->map);
	data->map = NULL;
}

void	ft_free_data(t_cub *data)
{
	int	i;

	i = -1;
	while (++i <= S)
		if (data->tex[i])
			free(data->tex[i]);
	if (data->fd)
		close(data->fd);
	if (data->map)
		ft_free_map(data);
	if (data->first)
		ft_lstclear(&data->first, &free);
	else if (data->line)
		free(data->line);
}
