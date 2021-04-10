/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:15:39 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/10 11:26:50 by tderwedu         ###   ########.fr       */
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
	uint32_t	tmp;
	uint32_t	rgb;

	rgb = 0U << 24;
	tmp = ft_get_int(&ptr);
	if ((tmp - 0U) > 255U || !(*ptr++ == ','))
		return (-1);
	rgb |= tmp << 16;
	tmp = ft_get_int(&ptr);
	if ((tmp - 0U) > 255U || !(*ptr++ == ','))
		return (-1);
	rgb |= tmp << 8;
	tmp = ft_get_int(&ptr);
	if ((tmp - 0U) > 255U)
		return (-1);
	rgb |= tmp;
	while (*ptr && (*ptr == ' ' || (t_ui)(*ptr - 9U) < 4U))
		ptr++;
	if (!(*ptr == '\0'))
		return (-1);
	return (rgb);
}

void				ft_print_data(t_cub *data)
{
	ft_printf("***\n");
	ft_printf("Data parsed from CUB file:\n");
	ft_printf("Resolution: %i - %i\n", data->width, data->height);
	ft_printf("      Ceil: %#.8x\n", data->ceil);
	ft_printf("     Floor: %#.8x\n", data->floor);
	ft_printf("Wall North: %s\n", data->tex_no);
	ft_printf(" Wall West: %s\n", data->tex_we);
	ft_printf("Wall South: %s\n", data->tex_so);
	ft_printf(" Wall East: %s\n", data->tex_ea);
	ft_printf("    Sprite: %s\n", data->sprite);
	ft_printf("     y_map: %i\n", data->y_map);
	ft_printf("     x_map: %i\n", data->x_map);
	ft_printf("\n***\n");
}

void				ft_print_map(t_cub *data)
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
