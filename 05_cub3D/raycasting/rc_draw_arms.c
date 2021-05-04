/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_draw_arms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:30:10 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/04 11:41:36 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

#define	RIGT_ARM_0	"./textures/Dague_1_H240.xpm"
#define RIGT_ARM_1	"./textures/Dague_3_H160.xpm"
#define LEFT_ARM_0	"./textures/Torche_1_H240.xpm"


int	rc_get_arms(t_mlx *mlx)
{
	t_tex	*tex;
	// Right Arm 0
	tex = &mlx->right_arm[0];
	tex->img = mlx_xpm_file_to_image(mlx->mlx, RIGT_ARM_0, &tex->width,
				&tex->height);
	if (!tex->img)
		return (rc_error(mlx, ERR_RC_IMG_XPM));
	tex->addr = (t_u32 *)mlx_get_data_addr(tex->img, &tex->bpp, &tex->sl, &tex->endia);
	if (!tex->addr)
		return (rc_error(mlx, ERR_RC_ADDR_XPM));
	tex->bpp /= 8;
	tex->sl /= 4;
	tex->h_mask = tex->height - 1;
	tex->w_mask = tex->width - 1;
	// Right Arm 1
	tex = &mlx->right_arm[1];
	tex->img = mlx_xpm_file_to_image(mlx->mlx, RIGT_ARM_1, &tex->width,
				&tex->height);
	if (!tex->img)
		return (rc_error(mlx, ERR_RC_IMG_XPM));
	tex->addr = (t_u32 *)mlx_get_data_addr(tex->img, &tex->bpp, &tex->sl, &tex->endia);
	if (!tex->addr)
		return (rc_error(mlx, ERR_RC_ADDR_XPM));
	tex->bpp /= 8;
	tex->sl /= 4;
	tex->h_mask = tex->height - 1;
	tex->w_mask = tex->width - 1;
	// Left Arm 0
	tex = &mlx->left_arm[0];
	tex->img = mlx_xpm_file_to_image(mlx->mlx, LEFT_ARM_0, &tex->width,
				&tex->height);
	if (!tex->img)
		return (rc_error(mlx, ERR_RC_IMG_XPM));
	tex->addr = (t_u32 *)mlx_get_data_addr(tex->img, &tex->bpp, &tex->sl, &tex->endia);
	if (!tex->addr)
		return (rc_error(mlx, ERR_RC_ADDR_XPM));
	tex->bpp /= 8;
	tex->sl /= 4;
	tex->h_mask = tex->height - 1;
	tex->w_mask = tex->width - 1;
	return (0);
}

void	rc_draw_arms(t_mlx *mlx)
{
	int		y;
	int		x;
	int		y_tex;
	int		x_tex;
	t_tex	*arm;
	t_u32	*dst;
	t_u32	*src;

	arm = &mlx->left_arm[0];
	y = mlx->height - arm->height;
	y_tex = 0;
	while (++y_tex < arm->height)
	{
		x = 0;
		x_tex = -1;
		dst = mlx->img->addr + ++y * mlx->img->sl;
		src = arm->addr + y_tex * arm->sl;
		while (++x_tex < arm->width)
		{
			if (*(src + x_tex) != 0xFFFFFF)
				*(dst + x) = *(src + x_tex);
			x++;
		}
	}
	arm = &mlx->right_arm[1];
	y = mlx->height - arm->height;
	y_tex = 0;
	while (++y_tex < arm->height)
	{
		x = mlx->width - arm->width;
		x_tex = -1;
		dst = mlx->img->addr + ++y * mlx->img->sl;
		src = arm->addr + y_tex * arm->sl;
		while (++x_tex < arm->width)
		{
			if (*(src + x_tex) != 0xFFFFFF)
				*(dst + x) = *(src + x_tex);
			x++;
		}
	}
}
