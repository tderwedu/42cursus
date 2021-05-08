/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_skybox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:24:45 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/08 17:43:34 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	rc_skybox(t_mlx *mlx, t_tex *tex, t_cam *cam)
{
	double	x_dir;
	double	y_dir;
	t_loop	box;

	x_dir = cam->x_dir;
	y_dir = cam->y_dir;
	box.x = 0;
	box.x_range = mlx->width;
	box.x_tex_range = tex->width * FOV / 360.0;
	box.x_tex = (int)((atan2(y_dir, x_dir) + M_PI)/(2 * M_PI) * tex->width);
	box.x_tex -= box.x_tex_range / 2;
	if (box.x_tex < 0)
		box.x_tex += tex->width;
	box.y = 0;
	box.y_range = cam->height_pitch;
	box.y_tex = (0.3 * mlx->height_2 - cam->pitch) * box.x_tex_range / box.x_range;
	box.y_tex_range = box.y_range * box.x_tex_range / box.x_range;
	
	// ft_printf("        y: % i\n", box.y);
	// // ft_printf("      y_max: % i\n", box.y_max);
	// ft_printf("    y_range: % i\n", box.y_range);
	// ft_printf("      y_tex: % i\n", box.y_tex);
	// // ft_printf("  y_tex_max: % i\n", box.y_tex_max);
	// ft_printf("y_tex_range: % i\n", box.y_tex_range);
	// ft_printf("        x: % i\n", box.y);
	// // ft_printf("      x_max: % i\n", box.x_max);
	// ft_printf("    x_range: % i\n", box.x_range);
	// ft_printf("      x_tex: % i\n", box.x_tex);
	// // ft_printf("  x_tex_max: % i\n", box.x_tex_max);
	// ft_printf("xy_tex_range: % i\n", box.x_tex_range);

	if (box.y_tex_range < box.y_range)
		yx_set_tex_y_loop(mlx, tex, &box, 0xFF000000);
	else
		yx_set_tex_y_tex_loop(mlx, tex, &box, 0xFF000000);
}
