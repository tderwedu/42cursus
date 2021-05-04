/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_set_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:53:32 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/04 10:27:32 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int	rc_set_mlx(t_cub *data, int show_win)
{
	t_mlx	mlx;
	t_cam	cam;

	mlx.cam = &cam;
	if (rc_mlx_init(data, &mlx))
		return (1);
	ft_free_data(data);
	(void)show_win;
	rc_new_frame(&mlx);
	mlx_mouse_move(mlx.mlx, mlx.win, mlx.width_2, mlx.height_2);
	mlx_mouse_hide(mlx.mlx, mlx.win); // TODO: does not work!
	mlx_hook(mlx.win, 2, 1L << 0, &rc_key_press, &mlx);
	mlx_hook(mlx.win, 3, 1L << 1, &rc_key_release, &mlx);
	mlx_hook(mlx.win, 33, 1L << 17, &rc_exit, &mlx);
	mlx_loop_hook (mlx.mlx, &rc_new_frame, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}

int	rc_new_frame(t_mlx *mlx)
{
	t_img	img;

	img.img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	img.addr = (t_u32 *)mlx_get_data_addr(img.img, &img.bpp, &img.sl, &img.endia);
	img.width = mlx->width;
	img.height = mlx->height;
	img.bpp /= 8;
	img.sl /= 4;
	mlx->img = &img;
	mlx->lst = NULL;
	rc_mouse_hook(mlx);
	if (mlx->cam->z_pos > 0.0)
		mlx->cam->z_pos -= 10;
	rc_scanline(mlx);
	rc_raycasting(mlx, mlx->cam);
	rc_sprite(mlx, &img);
	rc_draw_mini_map(mlx, &img); // TODO
	rc_draw_arms(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, 0, 0);
	mlx_destroy_image(mlx->mlx, img.img);
	mlx->img = NULL;
	return (0);
}
