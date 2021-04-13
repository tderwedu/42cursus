/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:51:03 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/13 11:57:00 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int					main(int argc, char **argv)
{
	t_cub	data;

	if (!((t_ui)(argc - 2) < 1U))
		return (ft_printf("Error\n%s\n", ERR_ARG_NBR));
	if (ft_get_data(&data, argc, argv))
		return (1);
	rc_set_mlx(&data, 1);
	ft_free_data(&data);
}
