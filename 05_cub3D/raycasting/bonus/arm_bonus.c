/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arm_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:30:10 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/17 12:05:34 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	arm_move(t_mlx *mlx, t_loop *box)
{
	if (mlx->strike == 1 || mlx->strike == 9)
	{
		box->x_tex_range /= 2;
		box->y_tex_range /= 2;
	}
	else if (mlx->strike == 2 || mlx->strike == 8)
	{
		box->x_tex_range = (2 * box->x_tex_range) / 3;
		box->y_tex_range = (2 * box->y_tex_range) / 3;
	}
	else if (mlx->strike == 3 || mlx->strike == 7)
	{
		box->x_tex_range = (3 * box->x_tex_range) / 4;
		box->y_tex_range = (3 * box->y_tex_range) / 4;
	}
	if (mlx->strike == 4)
		check_strike(mlx);
}

void	arm(t_mlx *mlx)
{
	int		i;
	double	ratio;
	t_loop	box;

	i = arm_0 + (mlx->strike > 0);
	box = (t_loop){0, mlx->height, mlx->height, 0, mlx->tex[i].height, 0,
		0, 0, 0, mlx->tex[i].width, 0x22B14C};
	ratio = mlx->height / 360.0;
	arm_move(mlx, &box);
	box.y_range = box.y_tex_range * ratio;
	box.y = mlx->height - box.y_range;
	box.x_range = box.x_tex_range * ratio;
	box.x = mlx->width - box.x_range;
	if (box.y_tex_range < box.y_range)
		set_tex_yx_y_loop(mlx, &mlx->tex[i], &box);
	else
		set_tex_yx_y_tex_loop(mlx, &mlx->tex[i], &box);
	if (mlx->strike > 0)
		mlx->strike++;
	if (mlx->strike > 9)
		mlx->strike = 0;
}

void	check_strike_spr(t_mlx *mlx, double y, double x, double dt)
{
	t_spr	*spr;

	spr = (t_spr *)mlx->ptr[(int)y][(int)x];
	y -= spr->y_pos;
	x -= spr->x_pos;
	if ((y >= -dt && y <= dt) && (x >= -dt && x <= dt))
	{
		spr->dead = 1;
		if (spr->id == m_spr)
			spr->tex =&mlx->tex[S_broken];
		else if (spr->id == m_kfc)
			spr->tex =&mlx->tex[kfc_dead];
	}
}

void	check_strike(t_mlx *mlx)
{
	int		val;
	double	y;
	double	x;

	y = mlx->cam->y_pos;
	x = mlx->cam->x_pos;
	val = mlx->map[(int)y][(int)x];
	if (val == m_spr)
		check_strike_spr(mlx, y, x, 0.3);
	else if (val == m_kfc && mlx->cam->z_pos == -mlx->height / 4)
		check_strike_spr(mlx, y, x, 0.3);
	y = mlx->cam->y_pos + mlx->cam->y_dir / 2;
	x = mlx->cam->x_pos + mlx->cam->x_dir / 2;
	val = mlx->map[(int)y][(int)x];
	if (val == m_spr)
		check_strike_spr(mlx, y, x, 0.3);
	else if (val == m_kfc && mlx->cam->z_pos == -mlx->height / 4)
		check_strike_spr(mlx, y, x, 0.3);
}
