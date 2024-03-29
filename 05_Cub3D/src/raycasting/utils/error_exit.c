/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:16:35 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/18 15:58:43 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rc_exit(t_mlx *mlx)
{
	rc_free_mlx(mlx);
	exit(0);
	return (0);
}

int	rc_error(t_mlx *mlx, char *str)
{
	printf("Error\n%s\n", str);
	rc_free_mlx(mlx);
	exit(0);
	return (1);
}

int	rc_error_tex(t_mlx *mlx, char *str, char *tex)
{
	printf("Error\n%s\n", str);
	printf("->'%s'\n", tex);
	rc_free_mlx(mlx);
	exit(0);
	return (1);
}

int	rc_error_data(t_cub *data, t_mlx *mlx, char *str)
{
	printf("Error\n%s\n", str);
	ft_free_data(data);
	rc_free_mlx(mlx);
	return (1);
}
