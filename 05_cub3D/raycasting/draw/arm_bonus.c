/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arm_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:30:10 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/11 15:57:03 by tderwedu         ###   ########.fr       */
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
}

void	arm(t_mlx *mlx)
{
	int		i;
	double	ratio;
	t_loop	box;

	i = arm_0 + (mlx->strike > 0);
	box = (t_loop){0, mlx->height, mlx->height, 0, mlx->tex[i].height, 0,
		0, 0, 0, mlx->tex[i].width, 0x22B14C};
	ratio = 1.5 * box.y_tex_range / mlx->height;
	arm_move(mlx, &box);
	box.y = mlx->height - box.y_tex_range * ratio;
	box.x = mlx->width - box.x_tex_range * ratio;
	box.x_range = box.x_tex_range * ratio;
	box.y_range = box.y_tex_range * ratio;
	if (box.y_tex_range < box.y_range)
		yx_set_tex_y_loop(mlx, &mlx->tex[i], &box);
	else
		yx_set_tex_y_tex_loop(mlx, &mlx->tex[i], &box);
	if (mlx->strike > 0)
		mlx->strike++;
	if (mlx->strike > 9)
		mlx->strike = 0;
}
