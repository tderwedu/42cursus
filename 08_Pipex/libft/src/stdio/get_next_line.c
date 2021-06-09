/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 09:12:24 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/17 15:56:25 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_copy_line(t_vec *buff, char *str)
{
	size_t	carry;

	ft_memcpy(str, buff->start, buff->len);
	*(str + buff->len) = '\0';
	carry = (size_t)(buff->ptr - buff->start) - buff->len;
	if (carry)
		carry = carry - 1;
	else
		carry = 0;
	if (carry > 0)
		ft_memcpy(buff->start, buff->start + buff->len + 1, carry);
	buff->ptr = buff->start + carry;
	buff->len = carry;
	*(buff->ptr) = '\0';
}

static inline int	ft_read_file_return(char **line, t_vec *buff, char *eol)
{
	if (eol)
		buff->len = eol - buff->start;
	else
		buff->len = buff->ptr - buff->start;
	*line = malloc(buff->len + 1);
	if (!(*line))
		return (ft_freevec(buff));
	ft_copy_line(buff, *line);
	if (eol)
		return (1);
	ft_freevec(buff);
	return (0);
}

static int	ft_read_file(int fd, char **line, t_vec *buff)
{
	ssize_t	nbytes;
	char	*eol;

	eol = ft_strchr(buff->start, '\n');
	nbytes = BUFFER_SIZE;
	while (!eol && nbytes == BUFFER_SIZE)
	{
		nbytes = read(fd, buff->ptr, BUFFER_SIZE);
		if (nbytes < 0)
			return (ft_freevec(buff));
		*(buff->ptr + nbytes) = '\0';
		eol = ft_strchr(buff->ptr, '\n');
		buff->ptr += nbytes;
		if (!eol && buff->ptr > buff->max)
		{
			buff = ft_growvec(buff, BUFFER_SIZE);
			if (!buff)
				return (-1);
		}
	}
	return (ft_read_file_return(line, buff, eol));
}

int	get_next_line(int fd, char **line)
{
	static t_vec	*buff[OPEN_MAX];
	int				ret;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!buff[fd])
	{
		buff[fd] = ft_newvec(VEC_SIZE, BUFFER_SIZE);
		if (!buff[fd])
			return (-1);
	}
	ret = ft_read_file(fd, line, buff[fd]);
	if (ret != 1)
		buff[fd] = NULL;
	return (ret);
}
