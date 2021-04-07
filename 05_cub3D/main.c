/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:51:03 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/07 17:46:56 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

#define R_FLAG		0x01
#define C_FLAG		0x02
#define F_FLAG		0x04
#define SP_FLAG		0x08
#define NO_FLAG		0x10
#define SO_FLAG		0x20
#define WE_FLAG		0x40
#define EA_FLAG		0x80
#define ALL_FLAG	0xFF

typedef struct s_cub
{
	int		width;
	int		height;
	int		floor;
	int		ceil;
	char	*tex_no;
	char	*tex_so;
	char	*tex_we;
	char	*tex_ea;
	char	*sprite;
	char	*line;
	char	*ptr;
	int		fd;
	int		flag;
}				t_cub;

void	ft_init_cub_struct(t_cub *data)
{
	data->width = 0;
	data->height = 0;
	data->floor = 0;
	data->ceil = 0;
	data->tex_no = NULL;
	data->tex_so = NULL;
	data->tex_we = NULL;
	data->tex_ea = NULL;
	data->sprite = NULL;
	data->line = NULL;
	data->ptr = NULL;
	data->fd = 0;
}

void	ft_free_cub_struct(t_cub *data)
{
	if (data->tex_no)
		free(data->tex_no);
	if (data->tex_so)
		free(data->tex_so);
	if (data->tex_we)
		free(data->tex_we);
	if (data->tex_ea)
		free(data->tex_ea);
	if (data->sprite)
		free(data->sprite);
}

int		ft_error_parser(t_cub *data, char *str)
{
		ft_printf("Error:\n%s\n", str);
		ft_printf(">>%s<<\n", data->line);
		free(data->line);
		ft_free_cub_struct(data);
		return (1);
}

int ft_checkargs(int argc, char **argv)
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

char	*ft_skip_spaces(char *str)
{
	register char *ptr;

	ptr = str;
	while (*ptr && (t_ui)(*ptr == ' ' || (*ptr - 9U) < 4U))
		ptr++;
	return (ptr);
}

int		ft_get_int(char **ptr)
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

int32_t	ft_get_color(char *ptr)
{
	t_color		rgb;

	rgb.a = 0;
	rgb.r = ft_get_int(&ptr);
	if ((uint32_t)(rgb.r - 0) > 255U || !(*ptr++ == ','))
		return (-1);
	rgb.g = ft_get_int(&ptr);
	if ((uint32_t)(rgb.g - 0) > 255U || !(*ptr++ == ','))
		return (-1);
	rgb.b = ft_get_int(&ptr);
	if ((uint32_t)(rgb.b - 0) > 255U)
		return (-1);
	while (*ptr && (*ptr == ' ' || (t_ui)(*ptr - 9U) < 4U))
		ptr++;
	if (!(*ptr == '\0'))
		return (-1);
	return (rgb.a << 24 | rgb.r << 16 | rgb.g << 8 | rgb.b);
}

int		ft_get_resolution(t_cub	*data)
{
	t_uc chr;

	chr = *++data->ptr;
	if (!(chr == ' ' || (chr - 9U) < 4U))
		return (ft_error_parser(data, ERR_NOT_ELEM));
	if (data->flag & R_FLAG)
		return (ft_error_parser(data, ERR_DEF_TWICE));
	data->flag |= R_FLAG;
	data->ptr = ft_skip_spaces(++data->ptr);
	data->width = ft_get_int(&data->ptr);
	data->ptr = ft_skip_spaces(data->ptr);
	data->height = ft_get_int(&data->ptr);
	if (data->width < 1 || data->width < 1)
		return (ft_error_parser(data, ERR_WRONG_RES));
	if (!(*data->ptr == '\0'))
		return (ft_error_parser(data, ERR_WRONG_LINE));
	return (0);
}

int		ft_get_ceil(t_cub *data)
{
	t_uc chr;

	chr = *++data->ptr;
	if (!(chr == ' ' || (chr - 9U) < 4U))
		return (ft_error_parser(data, ERR_NOT_ELEM));
	if (data->flag & C_FLAG)
		return (ft_error_parser(data, ERR_DEF_TWICE));
	data->flag |= C_FLAG;
	data->ptr = ft_skip_spaces(++data->ptr);
	data->ceil = ft_get_color(data->ptr);
	if (data->ceil < 0)
		return (ft_error_parser(data, ERR_COLOR));
	return (0);
}

int		ft_get_floor(t_cub *data)
{
	t_uc chr;

	chr = *++data->ptr;
	if (!(chr == ' ' || (chr - 9U) < 4U))
		return (ft_error_parser(data, ERR_NOT_ELEM));
	if (data->flag & F_FLAG)
		return (ft_error_parser(data, ERR_DEF_TWICE));
	data->flag |= F_FLAG;
	data->ptr = ft_skip_spaces(++data->ptr);
	data->floor = ft_get_color(data->ptr);
	if (data->floor < 0)
		return (ft_error_parser(data, ERR_COLOR));
	return (0);
}

int		ft_get_wall_no(t_cub *data)
{
	t_uc chr;

	chr = data->ptr[2];
	if (!(data->ptr[1] == 'O' && (chr == ' ' || (chr - 9U) < 4U)))
		return (ft_error_parser(data, ERR_NOT_ELEM));
	if (data->flag & NO_FLAG)
		return (ft_error_parser(data, ERR_DEF_TWICE));
	data->flag |= NO_FLAG;
	data->ptr += 2;
	data->tex_no = ft_trimspaces(data->ptr);
	printf("ft_get_wall_no(): OK\n");
	return (0);
}

int		ft_get_wall_we(t_cub *data)
{
	t_uc chr;

	chr = data->ptr[2];
	if (!(data->ptr[1] == 'E' && (chr == ' ' || (chr - 9U) < 4U)))
		return (ft_error_parser(data, ERR_NOT_ELEM));
	if (data->flag & WE_FLAG)
		return (ft_error_parser(data, ERR_DEF_TWICE));
	data->flag |= WE_FLAG;
	data->ptr += 2;
	data->tex_we = ft_trimspaces(data->ptr);
	return (0);
}

int		ft_get_wall_so(t_cub *data)
{
	t_uc chr;

	chr = data->ptr[2];
	if (!(data->ptr[1] == 'O' && (chr == ' ' || (chr - 9U) < 4U)))
		return (ft_error_parser(data, ERR_NOT_ELEM));
	if (data->flag & SO_FLAG)
		return (ft_error_parser(data, ERR_DEF_TWICE));
	data->flag |= SO_FLAG;
	data->ptr += 2;
	data->tex_so = ft_trimspaces(data->ptr);
	return (0);
}

int		ft_get_wall_ea(t_cub *data)
{
	t_uc chr;

	chr = data->ptr[2];
	if (!(data->ptr[1] == 'A' && (chr == ' ' || (chr - 9U) < 4U)))
		return (ft_error_parser(data, ERR_NOT_ELEM));
	if (data->flag & EA_FLAG)
		return (ft_error_parser(data, ERR_DEF_TWICE));
	data->flag |= EA_FLAG;
	data->ptr += 2;
	data->tex_ea = ft_trimspaces(data->ptr);
	return (0);
}

int		ft_get_sprite(t_cub *data)
{
	t_uc chr;

	chr = *++data->ptr;
	if (!(chr == ' ' || (chr - 9U) < 4U))
		return (ft_error_parser(data, ERR_NOT_ELEM));
	if (data->flag & SP_FLAG)
		return (ft_error_parser(data, ERR_DEF_TWICE));
	data->flag |= SP_FLAG;
	data->sprite = ft_trimspaces(data->ptr);
	return (0);
}

int		ft_parse_data(t_cub *data)
{
	if (*data->ptr == '\0')
		return (0);
	else if (*data->ptr == 'R')
		return (ft_get_resolution(data));
	else if (*data->ptr == 'C')
		return (ft_get_ceil(data));
	else if (*data->ptr == 'F')
		return (ft_get_floor(data));
	else if (*data->ptr == 'N')
		return (ft_get_wall_no(data));
	else if (*data->ptr == 'W')
		return (ft_get_wall_we(data));
	else if (*data->ptr == 'E')
		return (ft_get_wall_ea(data));
	else if (*data->ptr == 'S' && *(data->ptr + 1) == 'O')
		return (ft_get_wall_so(data));
	else if (*data->ptr == 'S')
		return (ft_get_sprite(data));
	return (1);
}

void	ft_print_data(t_cub	*data)
{
	ft_printf("\n***\n");
	ft_printf("Resolution: %i - %i\n", data->width, data->height);
	ft_printf("Ceil: %#.8x\n", data->ceil);
	ft_printf("Floor: %#.8x\n", data->floor);
	ft_printf("Wall North: %s\n", data->tex_no);
	ft_printf("Wall West: %s\n", data->tex_we);
	ft_printf("Wall South: %s\n", data->tex_so);
	ft_printf("Wall East: %s\n", data->tex_ea);
	ft_printf("Sprite: %s\n", data->sprite);
	ft_printf("***\n");
}

int	ft_parse_cubfile(t_cub	*data)
{
	int		ret;
	int		i;

	i = 0;
	ret = get_next_line(data->fd, &data->line);
	while (ret > 0 && i < 23)
	{
		ft_printf("\ni: %i \n", i++);
		ft_printf("Line:>%s<\n", data->line);
		data->ptr = ft_skip_spaces(data->line);
		if (ft_strchr("CEFNRSW", *data->ptr))
		{
			if (ft_parse_data(data))
				return (1);
		}
		else if (!ft_isdigit(*data->ptr))
			return (ft_error_parser(data, ERR_DEBUG));
		free(data->line);
		ret = get_next_line(data->fd, &data->line);
	}
	free(data->line);
	return (1);
}

int		main(int argc, char **argv)
{
	t_cub	data;

	if (!((t_ui)(argc - 2) < 1U))
		return (ft_printf("Error:\n%s\n", ERR_NUM_ARG));
	ft_init_cub_struct(&data);
	data.fd = ft_checkargs(argc, argv);
	if (data.fd < 0)
		return (1);
	if (!ft_parse_cubfile(&data))
		return (1);
	ft_print_data(&data);
	ft_printf("End of parsing\n");
	ft_free_cub_struct(&data);
	ft_print_data(&data);
}
