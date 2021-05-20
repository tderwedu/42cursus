/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:19:29 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/18 15:46:25 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int	key_release(int keycode, t_mlx *mlx)
{
	t_cam	*cam;

	cam = mlx->cam;
	if (keycode == K_CTRL)
		release_crouch(cam);
	else
		return (0);
	new_frame(mlx);
	return (0);
}

void	release_crouch(t_cam *cam)
{
	if (cam->z_pos < 0)
		cam->z_pos = 0.0;
}
