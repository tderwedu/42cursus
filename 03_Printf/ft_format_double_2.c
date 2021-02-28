/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_double_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:18:04 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/28 12:10:56 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //TODO: remove

void	ft_pad_double(t_format *fmt, t_vec *tmp, int nb, int prec)
{
	register char	chr;
	register char	*ptr;

	// printf( "	### PAD DOUBLE ###\n");
	// printf( "	  tmp: |%s|\n", tmp->ptr);
	// printf( "	  len: %ld\n", tmp->len);
	// printf( "	   nb: %d\n", nb);
	if (nb > 0)
	{
		ptr = tmp->ptr - nb;
		tmp->len += nb;
		if (prec || fmt->flags & FL_LEFT)
		{
			chr = ' ' + prec * 16;
			ptr += tmp->len;

		}
		else
		{
			chr = (fmt->flags & FL_ZERO) ? '0' : ' ';
			tmp->ptr -= nb;
		}
		while (nb--)
			*ptr++ = chr;
	}
	// printf( "	  tmp: |%s|\n", tmp->ptr);
	// printf( "	  len: %ld\n", tmp->len);
}

void	ft_prefix_double(t_format *fmt, t_vec *tmp, t_fp *fp)
{
	int				type;
	register char	*ptr;

	ptr = tmp->ptr;
	type = (fmt->type | 32);
	if (type == 'a')
	{
		*--ptr = ('X' | type);
		*--ptr = '0';
	}
	if (fp->sign)
		*--ptr = '-';
	else if (fmt->flags & FL_BLANK)
		*--ptr = ' ';
	else if (fmt->flags & FL_PLUS)
		*--ptr = '+';
	tmp->len += tmp->ptr - ptr;
	tmp->ptr = ptr;
}

void	ft_suffix_double(t_format *fmt, t_vec *tmp, t_fp *fp)
{
	int				upper;
	register char	*ptr;

	ptr = tmp->ptr + tmp->len;
	upper = (fmt->type & 32);
	fp->exp *= (-2 * fp->sign + 1);
	if ((fmt->type | 32) == 'a')
	{
		*ptr++ = ('P' | upper);
		*ptr++ = '+' + (fp->sign) * 2;
		tmp->len += 2 + ft_fmt_x(fp->exp, ptr, upper);
	}
	else if (fp->sign)
	{
		*ptr++ = ('E' | upper);
		*ptr++ = '+' + (fp->sign) * 2;
		*ptr = '0';
		tmp->len += 4 + (ft_fmt_u(fp->exp, ptr + (fp->exp < 9)) > 2);
	}
}

void	ft_fmt_radix_f(t_format *fmt, t_vec *tmp, t_fp *fp, int exp)
{
	register int	i;
	register char	*ptr;

	// printf( "### RADIX FFF ###\n");
	// printf( "  len: %ld\n", tmp->len);
	// printf( "  tmp: |%s|\n", tmp->ptr);
	ptr = (tmp->ptr)--;
	if (fmt->prec)
		tmp->len++;
	if (exp >= 0)
	{
		i = -2;
		while (++i < exp)
			ptr[i] = ptr[i + 1];
		ptr[i] = '.';
	}
	else
	{
		i = exp - 1;
		tmp->ptr += exp;
		tmp->len = ((fmt->prec) ? fmt->prec + 2 : 1);
		ptr[i] = '0';
		ptr[++i] = '.';
		while (++i < 0)
			ptr[i] = '0';
	}
	// printf( "  len: %ld\n", tmp->len);
	// printf( "  tmp: |%s|\n", tmp->ptr);
}

void	ft_rmtrailingzeros(t_format *fmt, t_vec *tmp, int exp)
{
	int				len;
	int				suffix;
	register int	i;
	register char	*ptr;

	ptr = tmp->ptr;
	suffix = 0;
	if (exp < -4 || exp >= fmt->prec)
		suffix = 4 + ((exp < 0 ? -exp : exp) / 100 > 0);
	i = tmp->len - suffix;
	while (ptr[--i] == '0')
		;
	len = tmp->len;
	tmp->len = i + 1 + suffix;
	while (suffix--)
		ptr[++i] = ptr[--len];
}
