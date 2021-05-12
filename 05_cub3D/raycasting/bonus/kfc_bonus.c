/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kfc_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 10:48:49 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/12 16:30:15 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	kfc_update_ptr(t_mlx *mlx, t_spr *spr, double y, double x)
{
	mlx->map[(int)spr->y_pos][(int)spr->x_pos] = m_empty;
	mlx->ptr[(int)spr->y_pos][(int)spr->x_pos] = NULL;
	mlx->map[(int)y][(int)x] = m_kfc;
	mlx->ptr[(int)y][(int)x] = (void *)spr;
	spr->y_pos = y;
	spr->x_pos = x;
}

void	kfc_move(t_mlx *mlx, t_cam *cam, t_spr *spr)
{
	int		tmp;
	double	new_y;
	double	new_x;
	double	new_dir;

	tmp = rand() % 120 - 60;
	if (tmp > -15 && tmp < 15)
	{
		new_dir = atan2(spr->y_dir, spr->x_dir) + tmp * M_PI / 180.0;
		spr->y_dir = sin(new_dir);
		spr->x_dir = cos(new_dir);
	}
	if (tmp > -30 && tmp < 30)
	{
		new_y = spr->y_pos + spr->y_dir * KFC_SPEED;
		new_x = spr->x_pos + spr->x_dir * KFC_SPEED;
		if (!check_4_collisions(mlx, new_y, new_x, 0.15))
			kfc_update_ptr(mlx, spr, new_y, new_x);
		else
		{
			spr->y_dir = -spr->y_dir;
			spr->x_dir = -spr->x_dir;
		}
	}
	kfc_tex(mlx, cam, spr);
}

void	kfc_tex(t_mlx *mlx, t_cam *cam, t_spr *spr)
{
	int		tex;
	double	dir;

	if (!spr->dead)
	{
		dir = atan2(cam->y_dir, cam->x_dir) - atan2(spr->y_dir, spr->x_dir);
		tex = ((int)(dir * 1800 / M_PI) + 2025) % 3600;
		if (tex < 0)
			tex += 3600;
		tex = tex / 450 + kfc_y000;
		spr->tex = &mlx->tex[tex];
	}
	else
		spr->tex = &mlx->tex[kfc_dead];
}
