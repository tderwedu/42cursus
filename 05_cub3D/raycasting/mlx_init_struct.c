/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:12:57 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/12 17:41:13 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int	mlx_init_struct(t_cub *data, t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (rc_error_data(data, mlx, ERR_RC_INIT));
	mlx_get_screen_size(mlx->mlx, &mlx->width, &mlx->height);
	if (mlx->width > data->width)
		mlx->width = data->width;
	if (mlx->height > data->height)
		mlx->height = data->height;
	mlx->height_2 = mlx->height / 2;
	mlx->width_2 = mlx->width / 2;
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "cub3D");
	if (!mlx->win)
		return (rc_error_data(data, mlx, ERR_RC_WIN));
	if (get_tex(data, mlx))
		return (1);
	if (init_mandatory(data, mlx))
		return (1);
	if (init_bonus(data, mlx))
		return (1);
	return (0);
}

void	cam_init_struct(t_cub *data, t_cam *cam, double fov)
{
	cam->x_pos = (double)data->x_pos + 0.5;
	cam->y_pos = (double)data->y_pos + 0.5;
	cam->z_pos = 0.0;
	cam->pitch = 0.0;
	cam->x_dir = 0.0;
	cam->y_dir = 0.0;
	if (data->dir == 'N')
		cam->y_dir = -1.0;
	else if (data->dir == 'W')
		cam->x_dir = -1.0;
	else if (data->dir == 'S')
		cam->y_dir = 1.0;
	else if (data->dir == 'E')
		cam->x_dir = 1.0;
	cam->x_plane = -cam->y_dir * tan(fov);
	cam->y_plane = cam->x_dir * tan(fov);
	if (DEBUG)
	{
		ft_printf("  POS| y: % .2f | x: % .2f\n", cam->y_pos, cam->x_pos);
		ft_printf("  DIR| y: % .2f | x: % .2f\n", cam->y_dir, cam->x_dir);
		ft_printf("PLANE| y: % .2f | x: % .2f\n", cam->y_plane, cam->x_plane);
		ft_printf("PITCH| % .2f | ZPOS: % .2f\n", cam->pitch, cam->z_pos);
	}
}

int	init_mandatory(t_cub *data, t_mlx *mlx)
{
	mlx->fov_2 = (FOV / 2.0) * M_PI / 180;
	mlx->ratio = mlx->width / (2.0 * tan(mlx->fov_2));
	cam_init_struct(data, mlx->cam, mlx->fov_2);
	mlx->cam->height_pitch = mlx->height_2 + mlx->cam->pitch;
	mlx->nb_spr = data->nb_spr;
	if (mlx->nb_spr)
	{
		if (spr_new_lst(data, mlx))
			return (1);
	}
	else
		mlx->tab = NULL;
	mlx->map = data->map;
	data->map = NULL;
	mlx->z_buff = malloc(sizeof(double) * mlx->width);
	mlx->y_max = data->y_max;
	mlx->x_max = data->x_max;
	return (0);
}

int	init_bonus(t_cub *data, t_mlx *mlx)
{
	mlx->strike = 0;
	mlx->knife = 0;
	mlx->nb_door = data->nb_door;
	mlx->door = malloc(sizeof(t_door) * mlx->nb_door);
	if (!mlx->door && !mlx->nb_door)
		return (rc_error(mlx, strerror(errno)));
	mlx->fps = 0; // TODO: remove
	mlx->avg = 0; // TODO: remove
	mlx->count = 0; // TODO: remove
	if (ptr_map_create(mlx))
		return (1);
	return (0);
}
