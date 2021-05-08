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

int	spr_new_lst(t_cub *data, t_mlx *mlx)
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
				*tab = (t_spr_lst){x + 0.5, y + 0.5, 0.0, 0.0,
					0.0, 1, &mlx->tex[S], NULL};
				tab++;
			}
		}
	}
	return (0);
}

void	spr_lst_add(t_mlx *mlx, t_spr_lst *new)
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

void	spr_lst_sort(t_mlx *mlx, t_cam *cam)
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
		tab->y_tr = det * (-cam->y_plane * dt_x + cam->x_plane * dt_y);
		if (tab->y_tr > 0 && tab->show)
		{
			tab->x_tr = det * (cam->y_dir * dt_x - cam->x_dir * dt_y);
			tab->dist = tab->y_tr * tab->y_tr + tab->x_tr * tab->x_tr; 
			spr_lst_add(mlx, tab);
		}
		else
			tab->next = NULL;
		tab++;
	}
}


void	spr_draw(t_mlx *mlx)
{
	t_spr_lst	*lst;
	t_loop		box;
	int			x_screen;
	int			z_move;

	spr_lst_sort(mlx, mlx->cam);
	lst = mlx->lst;
	while (lst)
	{
		if (lst->show)
		{
			box = (t_loop){0, 0, 0, 0, lst->tex->height, 0, 0,
				(int)(mlx->ratio / lst->y_tr), 0, lst->tex->width};
			x_screen = (int)((mlx->width / 2) * (1 + lst->x_tr / lst->y_tr));
			z_move = mlx->cam->pitch + mlx->cam->z_pos / lst->y_tr;
			box.y_range = (int)(mlx->ratio / lst->y_tr);
			box.y = -box.y_range / 2 + mlx->height_2 + z_move;
			box.x = -box.x_range / 2 + x_screen;
			if (box.y_tex_range < box.y_range)
				xy_set_tex_x_loop(mlx, lst->tex, &box, 0x0, lst->y_tr);
			else
				xy_set_tex_x_tex_loop(mlx, lst->tex, &box, 0x0, lst->y_tr);
		}
		lst = lst->next;
	}
}

// void	spr_draw(t_mlx *mlx)
// {
// 	t_spr_lst	*lst;
// 	t_loop		box;
// 	int			x_screen;
// 	int			z_move;

// 	spr_lst_sort(mlx, mlx->cam);
// 	lst = mlx->lst;
// 	while (lst)
// 	{
// 		box = (t_loop){0, 0, 0, 0, lst->tex->height, 0, (int)(mlx->ratio / lst->y_tr), 0, 0, lst->tex->width};
// 		x_screen = (int)((mlx->width / 2) * (1 + lst->x_tr / lst->y_tr));
// 		z_move = mlx->cam->pitch + mlx->cam->z_pos / lst->y_tr;
// 		box.y_range = (int)(mlx->ratio / lst->y_tr);
// 		box.y = -box.y_range / 2 + mlx->height_2 + z_move;
// 		// box.y_tex = 0;
// 		// box.y_tex_range = lst->tex->height;
// 		// box.x_range = (int)(mlx->ratio / lst->y_tr);
// 		box.x = -box.x_range / 2 + x_screen;
// 		// box.x_tex = 0;
// 		// box.x_tex_range = lst->tex->width;
// 		if (box.y_tex_range < box.y_range)
// 			xy_set_tex_x_loop(mlx, lst->tex, &box, 0x0, lst->y_tr);
// 		else
// 			xy_set_tex_x_tex_loop(mlx, lst->tex, &box, 0x0, lst->y_tr);
// 		lst = lst->next;
// 	}
// }

// static inline void	spr_init_vars(t_mlx *mlx, t_spr_lst *lst, t_spr_vars *vars)
// {
// 	vars->x_screen = (int)((mlx->width / 2) * (1 + lst->x_tr / lst->y_tr));
// 	vars->spr_h = (int)(mlx->ratio / lst->y_tr) / 2;
// 	vars->spr_w = (int)(mlx->ratio / lst->y_tr) / 2;
// 	vars->z_move = mlx->cam->pitch + mlx->cam->z_pos / lst->y_tr;
// 	vars->y_s = -vars->spr_h + mlx->height_2 + vars->z_move;
// 	vars->y_e = vars->spr_h  + mlx->height_2 + vars->z_move;
// 	vars->x_s = -vars->spr_w + vars->x_screen;
// 	vars->x_e = vars->spr_w + vars->x_screen;
// 	if (vars->y_s < 0)
// 		vars->y_s = 0;
// 	if (vars->y_e >= mlx->height)
// 		vars->y_e = mlx->height - 1;
// 	if (vars->x_s < 0)
// 		vars->x_s = 0;
// 	if (vars->x_e >= mlx->width)
// 		vars->x_e = mlx->width - 1;
// 	vars->x_s--;
// 	vars->tex_h = lst->tex->height;
// 	vars->tex_w = lst->tex->width;
// }

// void	spr_draw(t_mlx *mlx, t_img *img)
// {
// 	t_spr_lst	*lst;
// 	t_spr_vars	v;

// 	spr_lst_sort(mlx, mlx->cam);
// 	lst = mlx->lst;
// 	while (lst)
// 	{
// 		spr_init_vars(mlx, lst, &v);
// 		while (++v.x_s < v.x_e)
// 		{
// 			if (lst->y_tr < mlx->z_buff[v.x_s])
// 			{
// 				v.x_tex = (v.x_s - v.x_screen + v.spr_w) * v.tex_w;
// 				v.x_tex /= (v.spr_w << 1);
// 				v.src = lst->tex->addr + lst->tex->sl * v.x_tex;
// 				v.dst = img->addr + v.x_s;
// 				v.y = v.y_s - 1;
// 				while (++v.y < v.y_e)
// 				{
// 					v.y_tex = (v.y - mlx->height_2 + v.spr_h - v.z_move) * v.tex_h;
// 					v.y_tex /= (v.spr_h << 1);
// 					if (*(v.src + v.y_tex))
// 					{
// 						if (SHADOW)
// 							*(v.dst + v.y * img->sl) = rc_shadow_effect(*(v.src + v.y_tex), lst->y_tr);
// 						else
// 							*(v.dst + v.y * img->sl) = *(v.src + v.y_tex);
// 					}
// 				}
// 			}
// 		}
// 		lst = lst->next;
// 	}
// }
