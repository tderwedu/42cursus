/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:10:48 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/17 12:01:07 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_mlx(t_cub *data)
{
	t_mlx	mlx;
	t_cam	cam;

	mlx.cam = &cam;
	if (mlx_init_struct(data, &mlx, 1))
		return (1);
	ft_free_data(data);
	if (new_frame(&mlx))
		return (1);
	mlx_mouse_move(mlx.mlx, mlx.win, mlx.width_2, mlx.height_2);
	mlx_mouse_hide(mlx.mlx, mlx.win);
	mlx_hook(mlx.win, 2, 1L << 0, &key_press, &mlx);
	mlx_hook(mlx.win, 3, 1L << 1, &key_release, &mlx);
	mlx_hook(mlx.win, 4, 1L << 2, &button_press, &mlx);
	mlx_hook(mlx.win, 33, 1L << 17, &rc_exit, &mlx);
	mlx_loop_hook (mlx.mlx, &new_frame, &mlx);
	mlx_loop(mlx.mlx);
	mlx_do_key_autorepeatoff(mlx.mlx);
	return (0);
}

int	save_frame(t_cub *data)
{
	t_mlx	mlx;
	t_cam	cam;
	t_img	img;

	mlx.cam = &cam;
	if (mlx_init_struct(data, &mlx, 0))
		return (1);
	ft_free_data(data);
	if (new_img(&mlx, &img))
		return (1);
	mlx.lst = NULL;
	floor_ceil(&mlx);
	raycasting(&mlx, &cam);
	spr_draw(&mlx);
	if (BONUS)
	{
		draw_mini_map(&mlx);
		if (mlx.knife)
			arm(&mlx);
		life_bar(&mlx);
	}
	if (bmp_save(&mlx, &img))
		return (1);
	rc_free_mlx(&mlx);
	return (0);
}
