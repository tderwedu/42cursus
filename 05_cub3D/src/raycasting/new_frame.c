/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:53:32 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/17 12:04:18 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	update_cam(t_mlx *mlx)
{
	if (mlx->cam->z_pos > 0.0)
	{
		mlx->cam->z_pos -= 10;
		if (mlx->cam->z_pos < 0.0)
			mlx->cam->z_pos = 0.0;
	}
}

static inline int	game_over(t_mlx *mlx, t_img *img)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	mlx_string_put(mlx->mlx, mlx->win, mlx->width_2, mlx->height_2,
		0x00FF0000, "GAME OVER");
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	mlx_destroy_image(mlx->mlx, img->img);
	mlx->img = NULL;
	sleep(5);
	rc_exit(mlx);
	return (1);
}

int	new_frame(t_mlx *mlx)
{
	t_img			img;

	if (new_img(mlx, &img))
		return (1);
	if (mlx->life_bar <= 0)
		game_over(mlx, &img);
	mlx->lst = NULL;
	if (BONUS)
		mouse_hook(mlx);
	update_cam(mlx);
	floor_ceil(mlx);
	raycasting(mlx, mlx->cam);
	spr_draw(mlx);
	if (BONUS)
	{
		draw_mini_map(mlx);
		if (mlx->knife)
			arm(mlx);
		life_bar(mlx);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, 0, 0);
	mlx_destroy_image(mlx->mlx, img.img);
	mlx->img = NULL;
	return (0);
}

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
