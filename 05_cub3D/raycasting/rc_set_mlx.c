/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_set_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:53:32 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/18 09:31:00 by tderwedu         ###   ########.fr       */
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
	rc_draw_img(&mlx);
	mlx_hook(mlx.win, 2, 1L << 0, rc_key_hooks, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}

void	rc_draw_img(t_mlx *mlx)
{
	t_img	img;

	// ft_printf("== NEW ==\n");
	img.img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.sl, &img.endia);
	img.bpp /= 8;
	img.sl /= 4;
	mlx->img = &img;
	mlx->lst = NULL;
	rc_scanline(mlx);
	rc_raycasting(mlx, mlx->cam);
	rc_sprite(mlx, &img);
	rc_draw_mini_map(mlx, &img); // TODO
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, 0, 0);
	mlx_destroy_image(mlx->mlx, img.img);
	mlx->img = NULL;
	// ft_printf("== END ==\n\n");
}
