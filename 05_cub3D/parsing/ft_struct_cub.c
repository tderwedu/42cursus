/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:23:04 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/09 18:08:10 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void				ft_init_cub_struct(t_cub *data)
{
	data->width = 0;
	data->height = 0;
	data->floor = 0;
	data->ceil = 0;
	data->tex_no = NULL;
	data->tex_so = NULL;
	data->tex_we = NULL;
	data->tex_ea = NULL;
	data->sprite = NULL;
	data->line = NULL;
	data->ptr = NULL;
	data->fd = 0;
	data->flag = 0;
	data->map = NULL;
	data->first = NULL;
	data->last = NULL;
	data->x_map = 0;
	data->y_map = 0;
	data->x_pos = 0;
	data->y_pos = 0;
	data->dir = 0;
}

static inline void	ft_free_map(t_cub *data)
{
	int y;
	
	y = -1;
	while (++y < data->y_map)
		if (data->map[y])
			free(data->map[y]);
	free(data->map);
}

void				ft_free_cub_struct(t_cub *data)
{
	if (data->map)
		ft_free_map(data);
	if (data->first)
		ft_lstclear(&data->first, &free);
	if (data->tex_no)
		free(data->tex_no);
	if (data->tex_so)
		free(data->tex_so);
	if (data->tex_we)
		free(data->tex_we);
	if (data->tex_ea)
		free(data->tex_ea);
	if (data->sprite)
		free(data->sprite);
	if (data->line)
		free(data->line);
}
