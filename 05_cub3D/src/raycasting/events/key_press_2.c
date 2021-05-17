/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:34:31 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/11 18:34:52 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	press_crouch(t_mlx *mlx, t_cam *cam)
{
	if (cam->z_pos != 1.0 && mlx->width >= mlx->height)
		cam->z_pos = -mlx->height / 4;
}

void	press_jump(t_mlx *mlx, t_cam *cam)
{
	if (cam->z_pos != 1.0 && mlx->width >= mlx->height)
		cam->z_pos = mlx->height / 3;
}
