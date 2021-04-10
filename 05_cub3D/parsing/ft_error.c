/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:47:49 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/10 11:56:45 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int	ft_error_arg(t_cub *data, char *str, char *arg)
{
	ft_printf("Error:\n%s\n", str);
	ft_printf(">>\"%s\"\n", arg);
	ft_free_data(data);
	return (1);
}

int	ft_error_parser(t_cub *data, char *str)
{
	ft_printf("Error:\n%s\n", str);
	ft_printf("line: \"%s\"\n", data->line);
	ft_free_data(data);
	return (1);
}

int	ft_error_map(t_cub *data, char *str, int y_e, int x_e)
{
	int		x;
	int		y;

	ft_printf("Error:\n%s\n", str);
	y = -1;
	while (++y < data->y_map)
	{
		x = -1;
		while (++x < data->x_map)
		{
			if (y == y_e && x == x_e)
				ft_printf("%sX%s", RGB_RED, RGB_NC);
			else if (data->map[y][x] == 1)
				ft_printf("%s1%s", RGB_YLW, RGB_NC);
			else if (data->map[y][x] == 0)
				ft_printf("0");
			else if (data->map[y][x] > 1)
				ft_printf("%s%i%s", RGB_GRN, data->map[y][x], RGB_NC);
			else if (data->map[y][x] < 0)
				ft_printf(" ");
		}
		ft_printf("\n");
	}
	ft_free_data(data);
	return (1);
}
