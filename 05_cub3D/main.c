/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:51:03 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/06 12:26:04 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int ft_checkinput(int argc, char **argv)
{
	int		fd;
	char	*str;

	str = "File Extension Don’t Match '.cub'";

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error:\n%s\n>:%s\n", strerror(errno), argv[1]);
		return (fd);
	}
	if (ft_strncmp(ft_strchr(argv[1], '.'), "cub", 3))
	{
		ft_printf("Error:\n%s\n> %s\n", str, argv[1]);
		return (-1);
	}
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6))
	{
		ft_printf("Error:\n%s\n> %s\n", "Wrong Option", argv[2]);
		return (-1);
	}
	return (fd);
}

ft_parse_data(char *line)
{
	if (*line == 'C')
		;
	else if (*line == 'E')
		;
	else if (*line == 'F')
		;
	else if (*line == 'N')
		;
	else if (*line == 'R')
		;
	else if (*line == 'S')
		;
	else if (*line == 'W')
		;
	else
		;
}

int	ft_parse_inputfile(int fd)
{
	int		ret;
	char	*ptr;
	char	*line;

	ret = get_next_line(fd, &ptr);
	while (ret > 0)
	{
		line = ft_trimspaces(ptr);
		if (ft_strchr("01CEFNRSW", *line))
			ft_parse_data(line);
		else
			return(-1);
		// free(line);
		// free(ptr);
		ret = get_next_line(fd, &ptr);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;

	fd = 0;
	if (!((t_ui)(argc - 2) < 1U))
	{
		ft_printf("Error:\n%s\n", "Wrong number of input argument");
		return (-1);
	}
	fd = ft_checkinputfile(argv[1]);
	if (fd < 0)
		return (-1);
	ft_parseinputfile(fd);
}
