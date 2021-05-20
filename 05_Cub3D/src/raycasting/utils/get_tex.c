/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:57:01 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/19 15:12:04 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_tex(t_cub *data, t_mlx *mlx)
{
	int	i;

	if (get_floor_ceil(data, mlx))
		return (ft_free_data(data));
	i = NO - 1;
	while (++i <= S)
	{
		if (load_tex(mlx, &mlx->tex[i], data->tex[i]))
			return (ft_free_data(data));
		rotate_tex(&mlx->tex[i]);
	}
	i--;
	if (BONUS)
	{
		if (load_bonus_tex_1(mlx))
			return (1);
		if (load_bonus_tex_2(mlx))
			return (1);
		while (++i <= tex_door)
			rotate_tex(&mlx->tex[i]);
	}
	return (0);
}

int	get_floor_ceil(t_cub *data, t_mlx *mlx)
{
	if (data->rgb[0] >= 0)
	{
		mlx->rgb[0] = data->rgb[0];
		mlx->tex[C].img = NULL;
		mlx->tex[C].addr = NULL;
	}
	else
	{
		mlx->rgb[0] = data->rgb[0];
		if (load_tex(mlx, &mlx->tex[C], data->tex[C]))
			return (ft_free_data(data));
	}
	if (data->rgb[1] >= 0) 
	{
		mlx->rgb[1] = data->rgb[1];
		mlx->tex[F].img = NULL;
		mlx->tex[F].addr = NULL;
	}
	else
	{
		mlx->rgb[1] = data->rgb[0];
		if (load_tex(mlx, &mlx->tex[F], data->tex[F]))
			return (ft_free_data(data));
	}
	return (0);
}

int	load_tex(t_mlx *mlx, t_tex *tex, char *dir)
{
	tex->img = mlx_xpm_file_to_image(mlx->mlx, dir, &tex->width,
			&tex->height);
	if (!tex->img)
		return (rc_error_tex(mlx, ERR_RC_IMG_XPM, dir));
	tex->addr = (t_u32 *)mlx_get_data_addr(tex->img, &tex->bpp, &tex->sl,
			&tex->endia);
	if (!tex->addr)
		return (rc_error(mlx, ERR_RC_ADDR_XPM));
	tex->bpp /= 8;
	tex->sl /= 4;
	tex->h_mask = tex->height - 1;
	tex->w_mask = tex->width - 1;
	if (!(tex->bpp == sizeof(t_u32)))
		return (rc_error(mlx, ERR_RC_BPP));
	return (0);
}

void	rotate_tex(t_tex *tex)
{
	t_u32			tmp;
	register int	x;
	register int	y;
	register t_u32	*addr;

	addr = (t_u32 *)tex->addr;
	x = -1;
	tex->sl = tex->sl * tex->width / tex->height;
	while (++x < tex->width)
	{
		y = -1;
		while (++y < x)
		{
			tmp = *(addr + x * tex->height + y);
			*(addr + x * tex->height + y) = *(addr + y * tex->width + x);
			*(addr + y * tex->width + x) = tmp;
		}
	}
}
