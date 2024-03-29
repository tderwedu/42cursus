/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 10:21:47 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/17 18:32:27 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int	spr_new_lst(t_cub *data, t_mlx *mlx)
{
	int		y;
	int		x;
	t_spr	*tab;

	tab = malloc(sizeof(t_spr) * data->nb_spr);
	if (!tab && !data->nb_spr)
		return (rc_error_data(data, mlx, ERR_MALLOC));
	mlx->tab = tab;
	y = -1;
	while (++y < data->y_max)
	{
		x = -1;
		while (++x < data->x_max)
		{
			if (data->map[y][x] >= m_spr && data->map[y][x] <= m_kfc)
				*tab++ = (t_spr){data->map[y][x], 0, 1, y + 0.5, x + 0.5, 1.0,
					0.0, 0.0, 0.0, 0.0, &mlx->tex[data->map[y][x] - m_spr + S],
					NULL};
		}
	}
	tab = NULL;
	return (0);
}

void	spr_lst_add(t_mlx *mlx, t_spr *new)
{
	t_spr	*lst;
	t_spr	*prev;

	lst = mlx->lst;
	if (!lst || (new->dist >= lst->dist))
	{
		new->next = mlx->lst;
		mlx->lst = new;
		return ;
	}
	prev = mlx->lst;
	while (new->dist < lst->dist && lst->next)
	{
		prev = lst;
		lst = lst->next;
	}
	if (!lst->next && new->dist < lst->dist)
	{
		lst->next = new;
		new->next = NULL;
		return ;
	}
	prev->next = new;
	new->next = lst;
}

void	spr_lst_sort(t_mlx *mlx, t_cam *cam)
{
	int			i;
	t_spr		*tab;
	double		det;
	double		dt_x;
	double		dt_y;

	i = -1;
	tab = mlx->tab;
	det = 1.0 / (cam->x_plane * cam->y_dir - cam->y_plane * cam->x_dir);
	while (++i < mlx->nb_spr)
	{
		if (tab->id == m_kfc && !tab->dead)
			kfc_move(mlx, cam, tab);
		dt_y = tab->y_pos - cam->y_pos;
		dt_x = tab->x_pos - cam->x_pos;
		tab->y_tr = det * (-cam->y_plane * dt_x + cam->x_plane * dt_y);
		if (tab->y_tr > 0 && tab->show)
		{
			tab->x_tr = det * (cam->y_dir * dt_x - cam->x_dir * dt_y);
			tab->dist = tab->y_tr * tab->y_tr + tab->x_tr * tab->x_tr;
			spr_lst_add(mlx, tab);
		}
		tab++;
	}
}

void	spr_draw(t_mlx *mlx)
{
	t_spr	*lst;
	t_loop	box;
	int		x_screen;
	int		z_move;

	spr_lst_sort(mlx, mlx->cam);
	lst = mlx->lst;
	while (lst)
	{
		if (lst->show)
		{
			box = (t_loop){0, 0, 0, 0, lst->tex->height, 0, 0,
				(int)(mlx->ratio / lst->y_tr), 0, lst->tex->width, 0x22B14C};
			x_screen = (int)((mlx->width / 2) * (1 + lst->x_tr / lst->y_tr));
			z_move = mlx->cam->pitch + mlx->cam->z_pos / lst->y_tr;
			box.y_range = (int)(mlx->ratio / lst->y_tr);
			box.y = -box.y_range / 2 + mlx->height_2 + z_move;
			box.x = -box.x_range / 2 + x_screen;
			if (box.y_tex_range < box.y_range)
				set_tex_xy_x_loop(mlx, lst->tex, &box, lst->y_tr);
			else
				set_tex_xy_x_tex_loop(mlx, lst->tex, &box, lst->y_tr);
		}
		lst = lst->next;
	}
}
