/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:51:03 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/06 17:49:10 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

typedef struct s_input
{
	int		rx;
	int		ry;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		f;
	int		c;
}				t_input;

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

#define R_FLAG	0x00000001
#define S_FLAG	0x00000001
#define C_FLAG	0x00000001
#define F_FLAG	0x00000001
#define R_FLAG	0x00000001

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

ft_initvars(t_vars *vars)
{
	
}

int		ft_getint(const char **ptr)
{
	uint64_t		val;
	register char	*nbr;

	nbr = *ptr;
	val = 0;
	while (*nbr && (*nbr == ' ' || (t_ui)(*nbr - 9U) < 4U))
		nbr++;
	*ptr = nbr;
	while ((t_ui)(*nbr - '0') < 10U && val < UINT32_MAX)
		val = val * 10 + (*nbr++ - '0');
	if (nbr == *ptr)
		return (-1);
	*ptr = nbr;
	return (val);
}

int32_t	ft_getcolor(char *ptr)
{
	t_color		rgb;

	rgb.a = 0;
	rgb.r = ft_getint(&ptr);
	if ((uint32_t)(rgb.r - 0) > 255U || !(*ptr++ == ','))
		return (-1);
	rgb.g = ft_getint(&ptr);
	if ((uint32_t)(rgb.g - 0) > 255U || !(*ptr++ == ','))
		return (-1);
	rgb.b = ft_getint(&ptr);
	if ((uint32_t)(rgb.b - 0) > 255U || !(*ptr++ == '\0'))
		return (-1);
	return (rgb.a << 24 | rgb.r << 16 | rgb.g << 8 | rgb.b);
}

int32_t	ft_getresolution(char *ptr, t_mlx *mlx)
{
	mlx->width =  ft_getint(&ptr);
	if (mlx->width < 1)
		return (-1);
	mlx->height =  ft_getint(&ptr);
	if (mlx->height < 1)
		return (-1);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_vars	vars;

	ft_initvars(&vars);
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
