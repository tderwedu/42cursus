/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:53:32 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/11 18:42:42 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	new_img(t_mlx *mlx, t_img *img)
{
	img->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	if (!img->img)
		return (rc_error(mlx, ERR_RC_IMG_XPM));
	img->addr = (t_u32 *)mlx_get_data_addr(img->img, &img->bpp, &img->sl,
			&img->endia);
	if (!img->addr)
		return (rc_error(mlx, ERR_RC_ADDR_XPM));
	img->width = mlx->width;
	img->height = mlx->height;
	img->bpp /= 8;
	img->sl /= 4;
	mlx->img = img;
	return (0);
}

int	new_frame(t_mlx *mlx)
{
	t_img			img;
	struct timespec	ts_1;
	struct timespec	ts_2;

	clock_gettime(CLOCK_MONOTONIC, &ts_1); // TODO:remove
	if (new_img(mlx, &img))
		return (1);
	mlx->lst = NULL;
	rc_mouse_hook(mlx);
	if (mlx->cam->z_pos > 0.0)
		mlx->cam->z_pos -= 10;
	floor_ceil(mlx);
	raycasting(mlx, mlx->cam);
	spr_draw(mlx);
	draw_mini_map(mlx, &img);
	arm(mlx);
	clock_gettime(CLOCK_MONOTONIC, &ts_2); // TODO:remove
	mlx->fps = 1000000000 / (ts_2.tv_nsec - ts_1.tv_nsec); // TODO:remove
	mlx->avg += mlx->fps; // TODO:remove
	mlx->count++; // TODO:remove
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, 0, 0);
	mlx_destroy_image(mlx->mlx, img.img);
	mlx->img = NULL;
	return (0);
}
