/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bar_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:16:57 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/19 09:34:57 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	life_bar_full_heart(t_mlx *mlx, t_loop *box, int i)
{
	int	tmp;
	int	ratio;

	ratio = (int)(mlx->height / 11.25);
	*box = (t_loop){mlx->sq, 0, ratio, 0, mlx->tex[tex_heart].height, 0, 0,
		ratio, 0, mlx->tex[tex_heart].width, 0x22B14C};
	box->y_max = mlx->sq + box->y_range;
	tmp = 5 - i;
	box->x = mlx->width - (tmp * (box->x_range + mlx->sq));
	box->x_max = box->x + box->x_range;
	if (box->y_tex_range < box->y_range)
		set_tex_yx_y_loop(mlx, &mlx->tex[tex_heart], box);
	else
		set_tex_yx_y_tex_loop(mlx, &mlx->tex[tex_heart], box);
}

static inline void	life_bar_half_heart(t_mlx *mlx, t_loop *box, int i)
{
	int		tmp;
	double	ratio;

	*box = (t_loop){mlx->sq, 0, 0, 0, mlx->tex[tex_heart].height, 0, 0, 0,
		0, mlx->tex[tex_heart].width, 0x22B14C};
	ratio = mlx->tex[tex_heart].height / 32.0;
	box->y_range = (int)(ratio * mlx->tex[tex_heart].height);
	box->y_max = mlx->sq + box->y_range;
	box->x_range = (int)(ratio * mlx->tex[tex_heart].height);
	tmp = 5 - i;
	box->x = mlx->width - (tmp * (box->x_range + mlx->sq));
	box->x_range /= 2;
	box->x_tex_range /= 2;
	box->x_max = box->x + box->x_range;
	if (box->y_tex_range < box->y_range)
		set_tex_yx_y_loop(mlx, &mlx->tex[tex_heart], box);
	else
		set_tex_yx_y_tex_loop(mlx, &mlx->tex[tex_heart], box);
}

void	life_bar(t_mlx *mlx)
{
	int		i;
	int		i_max;
	t_loop	box;

	i_max = mlx->life_bar / 2;
	i = 0;
	while (++i <= i_max)
		life_bar_full_heart(mlx, &box, i);
	if (mlx->life_bar % 2)
		life_bar_half_heart(mlx, &box, i);
}
