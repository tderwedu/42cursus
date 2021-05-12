/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_spr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:38:51 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/16 09:42:19 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	rc_sprite_lst_add(t_mlx *mlx, t_spr_lst *new)
{
	t_spr_lst	*lst;
	t_spr_lst	*prev;

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

void	rc_sprite_update_lst(t_mlx *mlx, t_cam *cam)
{
	int			i;
	t_spr_lst	*tab;
	double		det;
	double		dt_x;
	double		dt_y;

	det = 1.0 / (cam->x_plane * cam->y_dir - cam->y_plane * cam->x_dir);
	tab = mlx->tab;
	i = -1;
	while (++i < mlx->nb_spr)
	{
		dt_x = tab->x_map - cam->x_pos;
		dt_y = tab->y_map - cam->y_pos;
		tab->x_tr = det * (cam->y_dir * dt_x - cam->x_dir * dt_y);
		tab->y_tr = det * (-cam->y_plane * dt_x + cam->x_plane * dt_y);
		tab->dist = tab->y_tr * tab->y_tr + tab->x_tr * tab->x_tr; 
		if (tab->y_tr > 0)
			rc_sprite_lst_add(mlx, tab);
		else
			tab->next = NULL;
		tab++;
	}
}

static inline void	rc_sprite_init_v(t_mlx *mlx, t_spr_lst *lst, t_spr_vars *v)
{
	v->x_screen = (int)((mlx->width / 2) * (1 + lst->x_tr / lst->y_tr));
	v->spr_h = (int)(mlx->ratio / lst->y_tr) / 2;
	v->spr_w = (int)(mlx->ratio / lst->y_tr) / 2;
	// v->x_screen = (int)((mlx->width / 8) * (1 + lst->x_tr / lst->y_tr));
	// v->spr_h = (int)(mlx->ratio / lst->y_tr) / 8;
	// v->spr_w = (int)(mlx->ratio / lst->y_tr) / 8;
	v->z_move = mlx->cam->pitch + mlx->cam->z_pos / lst->y_tr;
	v->y_s = -v->spr_h + mlx->height_2 + v->z_move;
	v->y_e = v->spr_h  + mlx->height_2 + v->z_move;
	v->x_s = -v->spr_w + v->x_screen;
	v->x_e = v->spr_w + v->x_screen;
	if (v->y_s < 0)
		v->y_s = 0;
	if (v->y_e >= mlx->height)
		v->y_e = mlx->height - 1;
	if (v->x_s < 0)
		v->x_s = 0;
	if (v->x_e >= mlx->width)
		v->x_e = mlx->width - 1;
	v->x_s--;
	v->tex_h = lst->tex->height;
	v->tex_w = lst->tex->width;
}

int	rc_spr_init(t_cub *data, t_mlx *mlx)
{
	int			y;
	int			x;
	t_spr_lst	*tab;

	tab = malloc(sizeof(t_spr_lst) * data->nb_spr);
	if (!tab)
		return (rc_error_data(data, mlx, ERR_MALLOC));
	mlx->tab = tab;
	y = -1;
	mlx->nb_spr = data->nb_spr;
	while (++y < data->y_map)
	{
		x = -1;
		while (++x < data->x_map)
		{
			if (data->map[y][x] == 2)
			{
				tab->x_map = x + 0.5;
				tab->y_map = y + 0.5;
				tab->tex = &mlx->tex[S];
				tab++;
			}
		}
	}
	return (0);
}

void	rc_sprite(t_mlx *mlx, t_img *img)
{
	t_spr_lst	*lst;
	t_spr_vars	v;

	rc_sprite_update_lst(mlx, mlx->cam);
	lst = mlx->lst;
	while (lst)
	{
		rc_sprite_init_v(mlx, lst, &v);
		while (++v.x_s < v.x_e)
		{
			if (lst->y_tr < mlx->z_buff[v.x_s])
			{
				v.x_tex = (v.x_s - v.x_screen + v.spr_w) * v.tex_w;
				v.x_tex /= (v.spr_w << 1);
				v.src = lst->tex->addr + lst->tex->sl * v.x_tex;
				v.dst = img->addr + v.x_s;
				v.y = v.y_s - 1;
				while (++v.y < v.y_e)
				{
					v.y_tex = (v.y - mlx->height_2 + v.spr_h - v.z_move) * v.tex_h;
					v.y_tex /= (v.spr_h << 1);
					if (*(v.src + v.y_tex)) // if ((*(v.src + v.y_tex) & 0xFFFFFF) != 0)
					{
						if (SHADOW)
							*(v.dst + v.y * img->sl) = rc_shadow_effect(*(v.src + v.y_tex), lst->y_tr );
						else
							*(v.dst + v.y * img->sl) = *(v.src + v.y_tex);
					}
				}
			}
		}
		lst = lst->next;
	}
}