/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:14:11 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/24 14:15:12 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //TODO: remove

int		ft_check_buff_size(t_vec *buff, size_t len)
{
	while (len > (buff->max - buff->end))
		if(!ft_growvec(buff, 0))
			return (-1);
	return (1);
}

void	ft_pad(t_format *fmt, t_ui nb, int after)
{
	t_vec			*buff;
	register char	chr;
	register char	*start;
	register int	i;

	i = -1;
	chr = (fmt->flags & FL_ZERO) ? '0' : ' ';
	buff = fmt->ptr;
	start = (after ? (buff->end + buff->len) : (buff->end - nb));
	while (++i < nb)
		start[i] = chr;
	 buff->end -= (after ? 0 : nb);
	 buff->len += nb;
}

void	ft_prefix_unsigned(t_format *fmt, uintmax_t val)
{
	char	*start;
	t_vec	*buff;

	buff = fmt->ptr;
	start = buff->end;
	if (val && (fmt->flags & FL_HASH))
	{
		if ((fmt->type | 32) == 'x')
		{
				start -= 2;
				start[0] = '0';
				start[1] = fmt->type;
		}
		if (fmt->type == 'o')
		{
				start -= 1;
				start[0] = '0';
		}
		buff->len += buff->end - start;
		buff->end = start;
	}
}

void	ft_prefix_signed(t_format *fmt, intmax_t val)
{
	t_vec	*buff;

	buff = fmt->ptr;
	if (val >= 0 && (fmt->flags & (FL_PLUS | FL_BLANK)))
	{
		(buff->len)++;
		(buff->end)--;
		if (fmt->flags & FL_PLUS)
			*buff->end = '+';
		else if (fmt->flags & FL_BLANK)
			*buff->end = ' ';
	}
	else if (val < 0)
	{
		(buff->len)++;
		(buff->end)--;
		*buff->end = '-';
	}
}

void	ft_fmt_signed(t_format *fmt, va_list *ap, t_vec *buff)
{
	int			len;
	t_vec		*fmt_buff;
	intmax_t	i_val;

	fmt_buff = fmt->ptr;
	if ( fmt->length < 1)
		i_val = va_arg(*ap, int);
	else
		i_val = va_arg(*ap, intmax_t);
	if (i_val < 0)
		fmt_buff->len = ft_fmt_u(~i_val + 1, fmt_buff->end);
	else
		fmt_buff->len = ft_fmt_u(i_val, fmt_buff->end);
	if (fmt_buff->len < fmt->prec)
	{
		fmt->flags |= FL_ZERO;
		ft_pad(fmt, fmt->prec - fmt_buff->len, 0);
		fmt->flags &= ~FL_ZERO;
	}
	ft_prefix_signed(fmt, i_val);
	if (fmt_buff->len < fmt->width)
		ft_pad(fmt, fmt->width - fmt_buff->len, (fmt->flags & FL_LEFT));
	ft_memcpy(buff->end, fmt_buff->end, fmt_buff->len);
	buff->end[fmt_buff->len] = '\0';
	buff->end += fmt_buff->len;
}

void	ft_fmt_unsigned(t_format *fmt, va_list *ap, t_vec *buff)
{
	int			len;
	t_vec		*fmt_buff;
	uintmax_t	u_val;

	fmt_buff = fmt->ptr;
	u_val = va_arg(*ap, uintmax_t);
	if ((fmt->type | 32) == 'u')
		fmt_buff->len = ft_fmt_u(u_val, fmt_buff->end);
	else if ((fmt->type | 32) == 'o')
		fmt_buff->len = ft_fmt_o(u_val, fmt_buff->end);
	else if ((fmt->type | 32) == 'x')
		fmt_buff->len = ft_fmt_x(u_val, fmt_buff->end, (fmt->type & 32));
	if (fmt_buff->len < fmt->prec)
	{
		fmt->flags |= FL_ZERO;
		ft_pad(fmt, fmt->prec - fmt_buff->len, 0);
		fmt->flags &= ~FL_ZERO;
	}
	ft_prefix_unsigned(fmt, u_val);
	if (fmt_buff->len < fmt->width)
		ft_pad(fmt, fmt->width - fmt_buff->len, (fmt->flags & FL_LEFT));
	ft_memcpy(buff->end, fmt_buff->end, fmt_buff->len);
	buff->end[fmt_buff->len] = '\0';
	buff->end += fmt_buff->len;
}

static inline void	ft_pad_str(t_vec *buff, size_t nb)
{
	register size_t	i;
	register char	*ptr;

	i = -1;
	ptr = buff->end;
	while (++i < nb)
		ptr[i] = ' ';
	buff->end += nb;
	buff->len += nb;
}

int		ft_fmt_str(t_format *fmt, va_list *ap, t_vec *buff)
{
	size_t	len;
	char	*str;

	fmt->ptr = buff;
	str = va_arg(*ap, char*);
	len = ft_strlen(str);
	len = (fmt->prec < len ? fmt->prec :len);
	fmt->flags &= ~FL_ZERO;
	if (ft_check_buff_size(buff, (len < fmt->width ? fmt->width : len)) < 0)
		return (-1);
	if (len < fmt->width && !(fmt->flags & FL_LEFT))
	{
		ft_pad_str(buff, fmt->width - len);
		ft_memcpy(buff->end, str, len);
		buff->end += len;
	}
	else
	{
		ft_memcpy(buff->end, str, len);
		buff->end += len;
		if (len < fmt->width && (fmt->flags & FL_LEFT))
			ft_pad_str(buff, fmt->width - len);
	}
	return (1);
}

int		ft_fmt_chr(t_format *fmt, va_list *ap, t_vec *buff)
{
	char	chr;

	fmt->ptr = buff;
	chr = va_arg(*ap, int);
	fmt->flags &= ~FL_ZERO;
	if (ft_check_buff_size(buff, (fmt->width ? fmt->width : 1)) < 0)
		return (-1);
	if (fmt->width && !(fmt->flags & FL_LEFT))
	{
		ft_pad_str(buff, fmt->width - 1);
		*(buff->end)++ = chr;
	}
	else
	{
		*(buff->end)++ = chr;
		if (fmt->width && (fmt->flags & FL_LEFT))
			ft_pad_str(buff, fmt->width - 1);
	}
	return (1);
}

int		ft_fmt_len(t_format *fmt, va_list *ap, t_vec *buff)
{
	ssize_t	len;
	int		length;
	void	*ptr;

	len = buff->end - buff->begin;
	length = fmt->length;
	ptr = va_arg(*ap, void*);
	if (length == -2)
		*(char*)ptr = (char)len;
	else if (length == -1)
		*(short*)ptr = (short)len;
	else if (length == 0)
		*(int*)ptr = (int)len;
	else if (fmt->length == 1)
		*(long*)ptr = (long)len;
	else if (length == 2)
		*(long long *)ptr = (long long)len;
	return (1);
}

void	ft_prefix_double(t_format *fmt, uintmax_t val)
{
	char	*start;
	t_vec	*buff;

	buff = fmt->ptr;
	start = buff->end;
	if (val && (fmt->flags & FL_HASH))
	{
		if ((fmt->type | 32) == 'x')
		{
				start -= 2;
				start[0] = '0';
				start[1] = fmt->type;
		}
		if (fmt->type == 'o')
		{
				start -= 1;
				start[0] = '0';
		}
		buff->len += buff->end - start;
		buff->end = start;
	}
}

void	ft_fmt_double_hex(t_format *fmt, double	d_val, t_vec *buff)
{
	int		len;
	t_fp 	fp_val;
	t_vec	*fmt_buff;

	fmt_buff = fmt->ptr;
	fp_val = ft_double2fp(d_val);
	len = ft_fmt_x(fp_val.man, fmt_buff->end, (fmt->type & 32));
	*--(fmt_buff->end) = fmt_buff->end[1];
	if (len < fmt->prec)
	{
		fmt->flags |= FL_ZERO;
		ft_pad(fmt, fmt->prec - fmt_buff->len, 0);
		fmt->flags &= ~FL_ZERO;
	}




	
}

void	ft_double_handler(t_format *fmt, va_list *ap, t_vec *buff)
{
	char	type;
	double	d_val;
	
	d_val = va_arg(*ap, double);
	if (fmt->prec < 0)
		fmt->prec = 6;
	type = (fmt->type | 32);
	if (type & 'a')
	{
		fmt->flags |= FL_HASH;
	}
	else
	{
		fmt->flags &= ~FL_HASH;
	}

}

void	ft_format_handler(t_format *fmt, va_list *ap, t_vec *buff)
{
	t_ui	type;
	t_vec	*ptr;
	size_t	size;

	type =  1U << ((fmt->type | 32) - 'a');
	if (type & TYPE_CHAR)
		ft_fmt_chr(fmt, ap, buff);
	else if (type & TYPE_STR)
		ft_fmt_str(fmt, ap, buff);
	else if (type & TYPE_N)
		ft_fmt_len(fmt, ap, buff);
	size = ((fmt->width + fmt->prec) / 8 + 1) * 16 + BUFFER_SIZE / 4;
	fmt->ptr = ft_newvec(size, 0);
	ptr = fmt->ptr;
	ptr->end = ptr->begin + size / 2;
	if (type & TYPE_INT)
		ft_fmt_signed(fmt, ap, buff);
	else if (type & TYPE_UINT)
		ft_fmt_unsigned(fmt, ap, buff);
	else if (type & TYPE_PTR)
		;
	else if (type & TYPE_DOUBLE)
		;
	ft_freevec(fmt->ptr);
}
