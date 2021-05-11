/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:00:01 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/11 18:00:04 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_bonus_tex_1(t_mlx *mlx)
{
	if (load_tex(mlx, &mlx->tex[S_broken], S_BROKEN))
		return (1);
	if (load_tex(mlx, &mlx->tex[tex_knife], TEX_KNIFE))
		return (1);
	if (load_tex(mlx, &mlx->tex[kfc_y000], KFC_Y000))
		return (1);
	if (load_tex(mlx, &mlx->tex[kfc_y000], KFC_Y045))
		return (1);
	if (load_tex(mlx, &mlx->tex[kfc_y000], KFC_Y090))
		return (1);
	if (load_tex(mlx, &mlx->tex[kfc_y000], KFC_Y135))
		return (1);
	if (load_tex(mlx, &mlx->tex[kfc_y000], KFC_Y180))
		return (1);
	if (load_tex(mlx, &mlx->tex[kfc_y000], KFC_Y225))
		return (1);
	if (load_tex(mlx, &mlx->tex[kfc_y000], KFC_Y270))
		return (1);
	if (load_tex(mlx, &mlx->tex[kfc_y000], KFC_Y315))
		return (1);
	if (load_tex(mlx, &mlx->tex[kfc_y000], KFC_DEAD))
		return (1);
	if (load_tex(mlx, &mlx->tex[tex_door], TEX_DOOR))
		return (1);
}
int	load_bonus_tex_2(t_mlx *mlx)
{
	if (load_tex(mlx, &mlx->tex[arm_0], TEX_ARM_0))
		return (1);
	if (load_tex(mlx, &mlx->tex[arm_1], TEX_ARM_1))
		return (1);
}
