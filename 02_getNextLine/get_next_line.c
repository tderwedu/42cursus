/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 09:12:24 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/15 15:21:34 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_copy_line(t_vec *buff, char *str)
{
	size_t	carry;

	ft_memcpy(str, buff->begin, buff->len);
	*(str + buff->len) = '\0';
	carry = (size_t)(buff->end - buff->begin) - buff->len;
	carry = (carry ? carry - 1 : 0);
	if (carry > 0)
		ft_memcpy(buff->begin, buff->begin + buff->len + 1, carry);
	buff->end = buff->begin + carry;
	buff->len = carry;
	*(buff->end) = '\0';
}

static int	ft_read_file(int fd, char **line, t_vec *buff)
{
	ssize_t	nbytes;
	char	*eol;

	eol = ft_strchr(buff->begin, '\n');
	nbytes = BUFFER_SIZE;
	while (!eol && nbytes == BUFFER_SIZE)
	{
		if ((nbytes = read(fd, buff->end, BUFFER_SIZE)) < 0)
			return (ft_free_vec(buff));
		*(buff->end + nbytes) = '\0';
		eol = ft_strchr(buff->end, '\n');
		buff->end += nbytes;
		if (!eol && buff->end > buff->max)
			if (!(buff = ft_growvec(buff)))
				return (-1);
	}
	buff->len = (eol ? eol : buff->end) - buff->begin;
	if (!(*line = malloc(buff->len + 1)))
		return (ft_free_vec(buff));
	ft_copy_line(buff, *line);
	if (eol)
		return (1);
	ft_free_vec(buff);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static t_vec	*buff[OPEN_MAX];
	int				ret;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!buff[fd])
		if (!(buff[fd] = ft_newvec()))
			return (-1);
	ret = ft_read_file(fd, line, buff[fd]);
	if (ret != 1)
		buff[fd] = NULL;
	return (ret);
}
