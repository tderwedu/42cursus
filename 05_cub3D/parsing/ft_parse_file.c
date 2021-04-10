/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:21:26 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/10 11:58:39 by tderwedu         ###   ########.fr       */
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

static inline int	ft_check_data(t_cub *data, int ret)
{
	if (ret < 0)
		return (ft_error_parser(data, strerror(errno)));
	if (ret == 0 || !(data->flag == FLAG_ALL))
		return (ft_error_parser(data, ERR_INCOMP));
	return (0);
}

int	ft_get_data(t_cub *data, int argc, char **argv)
{
	ft_init_data(data);
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0)
		return (ft_error_arg(data, strerror(errno), argv[1]));
	if (ft_strncmp(ft_strchr(argv[1], '.') + 1, "cub", 3))
		return (ft_error_arg(data, strerror(errno), argv[1]));
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6))
		return (ft_error_arg(data, ERR_ARG_OPT, argv[1]));
	if (ft_parse_cubfile(data))
		return (1);
	if (close(data->fd))
		return (ft_error_parser(data, strerror(errno)));
	if (DEBUG)
		ft_print_data(data);
	if (ft_create_map(data))
		return (1);
	if (ft_check_boundary_x(data) && ft_check_boundary_y(data))
		return (1);
	if (DEBUG)
		ft_print_map(data);
	return (0);
}

int	ft_parse_cubfile(t_cub *data)
{
	int	ret;

	ret = get_next_line(data->fd, &data->line);
	while (ret > 0)
	{
		data->ptr = ft_skip_spaces(data->line);
		if (ft_isdigit(*data->ptr))
			break ;
		if (ft_line_handler(data))
			return (1);
		free(data->line);
		ret = get_next_line(data->fd, &data->line);
	}
	if (ft_check_data(data, ret))
		return (1);
	while (ret > 0)
	{
		if (ft_parse_map(data))
			return (1);
		ret = get_next_line(data->fd, &data->line);
	}
	if (ret < 0)
		return (ft_error_parser(data, strerror(errno)));
	return (0);
}
