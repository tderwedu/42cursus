/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:15:39 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/09 18:23:00 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int					ft_get_int(char **ptr)
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

int32_t				ft_get_color(char *ptr)
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

void				ft_print_data(t_cub	*data)
{
	ft_printf("\n***\n");
	ft_printf("Resolutiozln: %i - %i\n", data->width, data->height);
	ft_printf("Ceil: %#.8x\n", data->ceil);
	ft_printf("Floor: %#.8x\n", data->floor);
	ft_printf("Wall North: %s\n", data->tex_no);
	ft_printf("Wall West: %s\n", data->tex_we);
	ft_printf("Wall South: %s\n", data->tex_so);
	ft_printf("Wall East: %s\n", data->tex_ea);
	ft_printf("Sprite: %s\n", data->sprite);
	ft_printf("y_map: %i\n", data->y_map);
	ft_printf("x_map: %i\n", data->x_map);
	ft_printf("\n***\n");
}

void				ft_print_map(t_cub	*data)
{
	int		x;
	int		y;
	y = -1;
	while (++y < data->y_map)
	{
		x = -1;
		while (++x < data->x_map)
			ft_printf("%- 3i", data->map[y][x]);
		ft_printf("\n");
	}
}

int					ft_error_parser(t_cub *data, char *str)
{
	ft_printf("Error:\n%s\n", str);
	ft_printf("line: \"%s\"\n", data->line);
	ft_free_cub_struct(data);
	return (1);
}

int					ft_error_map(t_cub *data, char *str, int y_e,  int x_e)
{
	int		x;
	int		y;
	ft_printf("Error:\n%s\n", str);
	y = -1;
	while (++y < data->y_map)
	{
		x = -1;
		ft_printf("\n");
		while (++x < data->x_map)
		{
			if ( y == y_e && x == x_e)
				ft_printf("%sX%s", RGB_RED, RGB_NC);
			else if (data->map[y][x] == 1)
				ft_printf("%s1%s", RGB_BOLD, RGB_NC);
			else if (data->map[y][x] == 0)
				ft_printf("0");
			else if (data->map[y][x] > 1)
				ft_printf("%s%i%s", RGB_YLW, data->map[y][x], RGB_NC);
			else if (data->map[y][x] < 0)
				ft_printf(" ");
		}
	}
	ft_printf("\n");
	ft_free_cub_struct(data);
	return (1);
}
