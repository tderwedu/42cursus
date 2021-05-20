/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:51:03 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/18 15:51:00 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	data;

	if (argc < 2 || argc > 3)
		return (printf("Error\n%s\n", ERR_ARG_NBR));
	if (ft_get_data(&data, argc, argv))
		return (1);
	if (argc == 2)
	{
		if (set_mlx(&data))
			return (1);
	}
	else
	{
		if (save_frame(&data))
			return (1);
	}
}
