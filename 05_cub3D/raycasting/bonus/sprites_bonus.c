/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 10:48:49 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/09 11:23:09 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include "cub3d.h"


void	spr_b_get_dist(t_mlx *mlx, t_cam *cam, t_spr_lst *spr)
{
	int		tmp;
	double	det;
	double	dt_x;
	double	dt_y;

	det = 1.0 / (cam->x_plane * cam->y_dir - cam->y_plane * cam->x_dir);
	dt_x = spr->x_map - cam->x_pos;
	dt_y = spr->y_map - cam->y_pos;
	spr->y_tr = det * (-cam->y_plane * dt_x + cam->x_plane * dt_y);
	if (spr->y_tr > 0)
	{
		if (spr->show)
		{
			spr->x_tr = det * (cam->y_dir * dt_x - cam->x_dir * dt_y);
			spr->dist = spr->y_tr * spr->y_tr + spr->x_tr * spr->x_tr;
			tmp = (int)((atan2(spr->y_tr, spr->x_tr) + M_PI) * 1800 / M_PI) + 225;
			if (tmp > 3600)
				tmp -= 3600;
			spr->tex = &mlx->tex_b[tmp / 450];
		}
		else
			spr->tex = &mlx->tex_b[0];
	}
}


void	spr_b_draw(t_mlx *mlx)
{
	t_spr_lst	*spr;
	t_loop		box;
	int			x_screen;
	int			z_move;

	spr = mlx->spr_b;
	spr_b_get_dist(mlx, mlx->cam, spr);
	if (spr->y_tr > 0)
	{
		box = (t_loop){0, 0, 0, 0, spr->tex->height, 0, 0,
			(int)(mlx->ratio / spr->y_tr), 0, spr->tex->width};
		x_screen = (int)((mlx->width / 2) * (1 + spr->x_tr / spr->y_tr));
		z_move = mlx->cam->pitch + mlx->cam->z_pos / spr->y_tr;
		box.y_range = (int)(mlx->ratio / spr->y_tr);
		box.y = -box.y_range / 2 + mlx->height_2 + z_move;
		box.x = -box.x_range / 2 + x_screen;
		if (box.y_tex_range < box.y_range)
			xy_set_tex_x_loop(mlx, spr->tex, &box, 0x0, spr->y_tr);
		else
			xy_set_tex_x_tex_loop(mlx, spr->tex, &box, 0x0, spr->y_tr);
	}
}
