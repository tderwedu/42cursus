/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:15:39 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/19 09:31:22 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	printf("***\n");
	printf("Data parsed from CUB file:\n");
	printf("Resolution: %i - %i\n", data->width, data->height);
	if (data->rgb[C] > 0)
		printf("      Ceil: %#.8x\n", data->rgb[C]);
	else
		printf("      Ceil: %s\n", data->tex[C]);
	if (data->rgb[F] > 0)
		printf("     Floor: %#.8x\n", data->rgb[F]);
	else
		printf("     Floor: %s\n", data->tex[F]);
	printf("Wall North: %s\n", data->tex[NO]);
	printf(" Wall West: %s\n", data->tex[WE]);
	printf("Wall South: %s\n", data->tex[SO]);
	printf(" Wall East: %s\n", data->tex[EA]);
	printf("    Sprite: %s\n", data->tex[S]);
	printf("     y_max: %i\n", data->y_max);
	printf("     x_max: %i\n", data->x_max);
	printf("     y_pos: %i\n", data->y_pos);
	printf("     x_pos: %i\n", data->x_pos);
	printf("    nb spr: %i\n", data->nb_spr);
	printf("   nb door: %i\n", data->nb_door);
	printf("\n***\n");
}

void	ft_print_map(t_cub *data)
{
	int		x;
	int		y;

	printf("=== The MAP === \n");
	y = -1;
	while (++y < data->y_max)
	{
		x = -1;
		while (++x < data->x_max)
		{
			if (data->map[y][x] == 1)
				printf("%s1%s", RGB_YLW, RGB_NC);
			else if (data->map[y][x] > 1)
				printf("%s%i%s", RGB_GRN, data->map[y][x], RGB_NC);
			else if (data->map[y][x] < 0)
				printf(" ");
			else if (y == data->y_pos && x == data->x_pos)
				printf("%s%c%s", RGB_BLU, data->dir, RGB_NC);
			else
				printf("%i", data->map[y][x]);
		}
		printf("\n");
	}
}
