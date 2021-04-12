/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:16:35 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/12 16:17:54 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	rc_free_mlx(t_mlx *mlx)
{
	int i;

	i = -1;
	while (++i <= S)
		if (mlx->tex[i].img)
			mlx_destroy_image(mlx->mlx, mlx->tex[i].img);
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
}

int	rc_error(t_mlx *mlx, char *str)
{
	ft_printf("Error\n%s\n", str);
	rc_free_mlx(mlx);
	return (1);
}

int	rc_error_data(t_cub *data,t_mlx *mlx, char *str)
{
	ft_printf("Error\n%s\n", str);
	ft_free_data(data);
	rc_free_mlx(mlx);
	return (1);
}
