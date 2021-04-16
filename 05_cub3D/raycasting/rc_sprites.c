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

void	rc_sprite_lst_add(t_mlx *mlx, t_spr *new)
{
	t_spr	*lst;

	lst = mlx->lst;
	if (!lst || (new->y_tr > lst->y_tr))
	{
		if (lst)
			new->next = mlx->lst;
		else
			new->next = NULL;
		mlx->lst = new;
	}
	else
	{
		while (new->y_tr < lst->y_tr && lst->next)
			lst = lst->next;
		if (lst->next)
			new->next = lst->next;
		else
			new->next = NULL;
		lst->next = new;
	}
}

void	rc_sprite_update(t_mlx *mlx, t_cam *cam)
{
	int		i;
	t_spr	*tab;
	double	det;
	double	dt_x;
	double	dt_y;

	det = 1.0 / (cam->x_plane * cam->y_dir - cam->y_plane * cam->x_dir);
	tab = mlx->tab;
	i = -1;
	while (++i < mlx->nb_spr)
	{
		dt_x = tab->x_map - cam->x_pos;
		dt_y = tab->y_map - cam->y_pos;
		tab->x_tr = det * (cam->y_dir * dt_x - cam->x_dir * dt_y);
		tab->y_tr = det * (-cam->y_plane * dt_x + cam->x_plane * dt_y);
		if (tab->y_tr > 0)
			rc_sprite_lst_add(mlx, tab);
		else
			tab->next = NULL;
		tab++;
	}
}

static inline void	rc_sprite_init_v(t_mlx *mlx, t_spr *lst, t_spmp *v)
{
	v->x_screen = (int)((mlx->width / 2) * (1 + lst->x_tr / lst->y_tr));
	v->spr_h = (int)(mlx->height / lst->y_tr);
	v->spr_w = (int)(mlx->height / lst->y_tr);
	v->y_s = -v->spr_h / 2 + mlx->height / 2;
	v->y_e = v->spr_h / 2 + mlx->height / 2;
	v->x_s = -v->spr_w / 2 + v->x_screen;
	v->x_e = v->spr_w / 2 + v->x_screen;
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

void	rc_sprite(t_mlx *mlx, t_img *img)
{
	t_spr	*lst;
	t_spmp	v;

	rc_sprite_update(mlx, mlx->cam);
	lst = mlx->lst;
	while (lst)
	{
		rc_sprite_init_v(mlx, lst, &v);
		while (++v.x_s < v.x_e && lst->y_tr < mlx->z_buff[v.x_s])
		{
			v.x_tex = (v.x_s - v.x_screen + v.spr_w / 2) * v.tex_w;
			v.x_tex /= v.spr_w;
			v.src = (t_ui *)lst->tex->addr + v.tex_w * v.x_tex;
			v.dst = (t_ui *)img->addr + v.x_s;
			v.y = v.y_s - 1;
			while (++v.y < v.y_e)
			{
				v.y_tex = (v.y - mlx->height / 2 + v.spr_h / 2) * v.tex_h;
				v.y_tex /= v.spr_h;
				if ((*(v.src + v.y_tex) & 0xFFFFFF) != 0)
					*(v.dst + img->sl * v.y) = *(v.src + v.y_tex);
			}
		}
		lst = lst->next;
	}
}
