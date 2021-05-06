/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_draw_arms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:30:10 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/06 08:54:45 by tderwedu         ###   ########.fr       */
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
	int		i;
	double	ratio;
	t_loop	box;

	// Left Arm
	box = (t_loop){0, 0, 0, mlx->left_arm[0].height, 0, 0, 0, mlx->left_arm[0].width};
	ratio = 1.5 * box.y_tex_max / mlx->height;
	box.y = mlx->height - box.y_tex_max * ratio;
	box.x_max = box.x_tex_max * ratio;
	box.y_max = box.y_tex_max * ratio;
	if (box.y_tex_max < box.y_max)
		set_tex_y_loop(mlx, &mlx->left_arm[0], &box, 0xFFFFFF);
	else
		set_tex_y_tex_loop(mlx, &mlx->left_arm[0], &box, 0xFFFFFF);
	
	// Left Arm
	i = (mlx->attack > 0);
	box = (t_loop){0, mlx->height, 0, mlx->right_arm[i].height, 0, 0, 0, mlx->right_arm[i].width};
	ratio = 1.5 * box.y_tex_max / mlx->height;
	if (mlx->attack == 1 || mlx->attack == 9)
	{
		box.x_tex_max /= 2;
		box.y_tex_max /= 2;
	}
	else if (mlx->attack == 2 || mlx->attack == 8)
	{
		box.x_tex_max = (2 * box.x_tex_max ) / 3;
		box.y_tex_max = (2 * box.y_tex_max ) / 3;
	}
	else if (mlx->attack == 3 || mlx->attack == 7)
	{
		box.x_tex_max = (3 * box.x_tex_max ) / 4;
		box.y_tex_max = (3 * box.y_tex_max ) / 4;
	}
	box.y = mlx->height - box.y_tex_max * ratio;
	box.x = mlx->width - box.x_tex_max * ratio;
	box.x_max = box.x_tex_max * ratio;
	box.y_max = box.y_tex_max * ratio;
	if (box.y_tex_max < box.y_max)
		set_tex_y_loop(mlx, &mlx->right_arm[i], &box, 0xFFFFFF);
	else
		set_tex_y_tex_loop(mlx, &mlx->right_arm[i], &box, 0xFFFFFF);
	if (mlx->attack > 0) //TOD: improve and ADD object detection
		mlx->attack++;
	if (mlx->attack > 9)
		mlx->attack = 0;
}
