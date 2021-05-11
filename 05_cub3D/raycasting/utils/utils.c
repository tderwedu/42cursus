/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:00:50 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/11 16:11:10 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_4_walls(t_mlx *mlx, double new_y, double new_x, double dt)
{
	int	ret;

	ret = 0;
	ret += (mlx->map[(int)(new_y)][(int)(new_x)] != 0);
	ret += (mlx->map[(int)(new_y + dt)][(int)(new_x)] != 0);
	ret += (mlx->map[(int)(new_y - dt)][(int)(new_x)] != 0);
	ret += (mlx->map[(int)(new_y)][(int)(new_x + dt)] != 0);
	ret += (mlx->map[(int)(new_y)][(int)(new_x - dt)] != 0);
	return (ret);
}
