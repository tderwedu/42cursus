/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:15:39 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/21 12:02:37 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int	ft_get_int(char **ptr)
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
	while (*nbr && (*nbr == ' ' || (t_ui)(*nbr - 9U) < 4U))
		nbr++;
	*ptr = nbr;
	return (val);
}

int32_t	ft_get_color(char *ptr)
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

void	ft_print_data(t_cub *data)
{
	ft_printf("***\n");
	ft_printf("Data parsed from CUB file:\n");
	ft_printf("Resolution: %i - %i\n", data->width, data->height);
	if (data->rgb[C] > 0)
		ft_printf("      Ceil: %#.8x\n", data->rgb[C]);
	else
		ft_printf("      Ceil: %s\n", data->tex[C]);
	if (data->rgb[F] > 0)
		ft_printf("     Floor: %#.8x\n", data->rgb[F]);
	else
		ft_printf("     Floor: %s\n", data->tex[F]);
	ft_printf("Wall North: %s\n", data->tex[NO]);
	ft_printf(" Wall West: %s\n", data->tex[WE]);
	ft_printf("Wall South: %s\n", data->tex[SO]);
	ft_printf(" Wall East: %s\n", data->tex[EA]);
	ft_printf("    Sprite: %s\n", data->tex[S]);
	ft_printf("     y_map: %i\n", data->y_map);
	ft_printf("     x_map: %i\n", data->x_map);
	ft_printf("     y_pos: %i\n", data->y_pos);
	ft_printf("     x_pos: %i\n", data->x_pos);
	ft_printf("    nb spr: %i\n", data->nb_spr);
	ft_printf(" lst first: %p\n", data->first);
	ft_printf("  lst last: %p\n", data->last);
	if (data->first)
	{
		ft_printf(" str first: >>%s<<\n", data->first->content);
		ft_printf("  lst last: >>%s<<\n", data->last->content);
	}
	ft_printf("\n***\n");
}

void	ft_print_map(t_cub *data)
{
	int		x;
	int		y;

	ft_printf("=== The MAP === \n");
	y = -1;
	while (++y < data->y_map)
	{
		x = -1;
		while (++x < data->x_map)
		{
			if (data->map[y][x] == 1)
				ft_printf("%s1%s", RGB_YLW, RGB_NC);
			else if (data->map[y][x] > 1)
				ft_printf("%s%i%s", RGB_GRN, data->map[y][x], RGB_NC);
			else if (data->map[y][x] < 0)
				ft_printf(" ");
			else if (y == data->y_pos && x == data->x_pos)
				ft_printf("%s%c%s", RGB_BLU, data->dir, RGB_NC);
			else
				ft_printf("%i", data->map[y][x]);
		}
		ft_printf("\n");
	}
}
