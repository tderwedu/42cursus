/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:21:26 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/09 15:38:06 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

static inline char	*ft_skip_spaces(char *str)
{
	register char *ptr;

	ptr = str;
	while (*ptr && (t_ui)(*ptr == ' ' || (*ptr - 9U) < 4U))
		ptr++;
	return (ptr);
}

static inline int	ft_check_data(t_cub	*data, int ret)
{
	if (ret < 0)
		return (ft_error_parser(data, strerror(errno)));
	if (ret == 0 || !(data->flag == FLAG_ALL))
		return (ft_error_parser(data, ERR_INCOMP));
	return (0);
}

int					ft_parse_cubfile(t_cub	*data)
{
	int		ret;

	ret = get_next_line(data->fd, &data->line);
	while (ret > 0)
	{
		data->ptr = ft_skip_spaces(data->line);
		if (ft_isdigit(*data->ptr))
			break;
		if (ft_data_parse(data))
			return (1);	
		free(data->line);
		ret = get_next_line(data->fd, &data->line);
	}
	if (ft_check_data(data, ret))
		return (1);
	while (ret > 0)
	{
		if (ft_map_parse(data))
			return (1);
		ret = get_next_line(data->fd, &data->line);
	}
	if (ret < 0)
		return (ft_error_parser(data, strerror(errno)));
	return (0);
}
