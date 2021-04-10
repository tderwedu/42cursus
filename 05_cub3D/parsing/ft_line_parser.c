/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:46:21 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/10 11:58:24 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

static inline char	*ft_skip_spaces(char *str)
{
	register char	*ptr;

	ptr = str;
	while (*ptr && (t_ui)(*ptr == ' ' || (*ptr - 9U) < 4U))
		ptr++;
	return (ptr);
}

int	ft_line_handler(t_cub *data)
{
	char	chr;
	char	next_chr;

	chr = *data->ptr;
	if (chr == '\0')
		return (0);
	next_chr = *(data->ptr + 1);
	if (chr == 'N' && next_chr == 'O')
		return (ft_get_tex_path(data, &data->tex_no, FLAG_NO));
	else if (chr == 'W' && next_chr == 'E')
		return (ft_get_tex_path(data, &data->tex_we, FLAG_WE));
	else if (chr == 'E' && next_chr == 'A')
		return (ft_get_tex_path(data, &data->tex_ea, FLAG_EA));
	else if (chr == 'S' && next_chr == 'O')
		return (ft_get_tex_path(data, &data->tex_so, FLAG_SO));
	else if (chr == 'R' && (next_chr == ' ' || (t_ui)(next_chr - 9U) < 4U))
		return (ft_get_resolution(data));
	else if (chr == 'C' && (next_chr == ' ' || (t_ui)(next_chr - 9U) < 4U))
		return (ft_get_pavement(data, &data->ceil, FLAG_C));
	else if (chr == 'F' && (next_chr == ' ' || (t_ui)(next_chr - 9U) < 4U))
		return (ft_get_pavement(data, &data->floor, FLAG_F));
	else if (chr == 'S' && (next_chr == ' ' || (t_ui)(next_chr - 9U) < 4U))
		return (ft_get_tex_path(data, &data->sprite, FLAG_SP));
	return (ft_error_parser(data, ERR_NOT_ELEM));
}

int	ft_get_resolution(t_cub *data)
{
	t_uc	chr;

	chr = *++data->ptr;
	if (!(chr == ' ' || (chr - 9U) < 4U))
		return (ft_error_parser(data, ERR_NOT_ELEM));
	if (data->flag & FLAG_R)
		return (ft_error_parser(data, ERR_DEF_TWICE));
	data->flag |= FLAG_R;
	data->ptr = ft_skip_spaces(++data->ptr);
	data->width = ft_get_int(&data->ptr);
	data->ptr = ft_skip_spaces(data->ptr);
	data->height = ft_get_int(&data->ptr);
	if (data->width < 1 || data->width < 1)
		return (ft_error_parser(data, ERR_WRONG_RES));
	data->ptr = ft_skip_spaces(data->ptr);
	if (!(*data->ptr == '\0'))
		return (ft_error_parser(data, ERR_WRONG_LINE));
	return (0);
}

int	ft_get_pavement(t_cub *data, int *rgb, int flag)
{
	t_uc	chr;

	chr = *++data->ptr;
	if (!(chr == ' ' || (chr - 9U) < 4U))
		return (ft_error_parser(data, ERR_NOT_ELEM));
	if (data->flag & flag)
		return (ft_error_parser(data, ERR_DEF_TWICE));
	data->flag |= flag;
	data->ptr = ft_skip_spaces(++data->ptr);
	*rgb = ft_get_color(data->ptr);
	if (data->ceil < 0)
		return (ft_error_parser(data, ERR_COLOR));
	return (0);
}

int	ft_get_tex_path(t_cub *data, char **path, int flag)
{
	if (data->flag & flag)
		return (ft_error_parser(data, ERR_DEF_TWICE));
	data->flag |= flag;
	data->ptr += 2;
	*path = ft_trimspaces(data->ptr);
	if (!(*path))
		return (ft_error_parser(data, strerror(errno)));
	if (ft_strncmp(ft_strrchr(*path, '.') + 1, "xpm", 3))
		return (ft_error_parser(data, ERR_TEX_EXT));
	return (0);
}
