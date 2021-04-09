/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:51:03 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/09 17:48:24 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int 				ft_checkargs(int argc, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error:\n%s\n>:%s\n", strerror(errno), argv[1]);
		return (fd);
	}
	if (ft_strncmp(ft_strchr(argv[1], '.') + 1, "cub", 3))
	{
		ft_printf("Error:\n%s\n", ERR_FILE_EXT);
		return (-1);
	}
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6))
	{
		ft_printf("Error:\n%s\n> %s\n", "Wrong Option", argv[2]);
		return (-1);
	}
	return (fd);
}

int					main(int argc, char **argv)
{
	t_cub	data;

	if (!((t_ui)(argc - 2) < 1U))
		return (ft_printf("Error:\n%s\n", ERR_NUM_ARG));
	ft_init_cub_struct(&data);
	data.fd = ft_checkargs(argc, argv);
	if (data.fd < 0)
		return (1);
	if (ft_parse_cubfile(&data))
		return (1);
	ft_printf("End of parsing\n");
	ft_print_data(&data);
	if (ft_map_create(&data))
		return (1);
	if (ft_check_map_closure_x(&data))
		return (1);
	if (ft_check_map_closure_y(&data))
		return (1);
	ft_printf("The map is valid :)\n");
	ft_print_map(&data);
	ft_free_cub_struct(&data);
}
