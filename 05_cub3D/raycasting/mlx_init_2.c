/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 10:11:34 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/11 11:54:07 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_tex(t_mlx *mlx, t_tex *tex, char *dir)
{
	tex->img = mlx_xpm_file_to_image(mlx->mlx, dir, &tex->width,
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
	if (!(tex->bpp == sizeof(t_u32)))
		return (rc_error(mlx, ERR_RC_BPP));
	return (0);
}

int	load_bonus_tex_1(t_mlx *mlx)
{
	if (get_tex(mlx, &mlx->tex[S_broken], S_BROKEN))
		return (1);
	if (get_tex(mlx, &mlx->tex[knife], SPR_KNIFE))
		return (1);
	if (get_tex(mlx, &mlx->tex[kfc_y000], KFC_Y000))
		return (1);
	if (get_tex(mlx, &mlx->tex[kfc_y000], KFC_Y045))
		return (1);
	if (get_tex(mlx, &mlx->tex[kfc_y000], KFC_Y090))
		return (1);
	if (get_tex(mlx, &mlx->tex[kfc_y000], KFC_Y135))
		return (1);
	if (get_tex(mlx, &mlx->tex[kfc_y000], KFC_Y180))
		return (1);
	if (get_tex(mlx, &mlx->tex[kfc_y000], KFC_Y225))
		return (1);
	if (get_tex(mlx, &mlx->tex[kfc_y000], KFC_Y270))
		return (1);
	if (get_tex(mlx, &mlx->tex[kfc_y000], KFC_Y315))
		return (1);
	if (get_tex(mlx, &mlx->tex[kfc_y000], KFC_DEAD))
		return (1);
	if (get_tex(mlx, &mlx->tex[door], TEX_DOOR))
		return (1);
}
int	load_bonus_tex_2(t_mlx *mlx)
{
	if (get_tex(mlx, &mlx->tex[0], S_BROKEN))
		return (1);
	if (get_tex(mlx, &mlx->tex[1], SPR_KNIFE))
		return (1);
}
