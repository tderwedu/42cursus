/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_double_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:27:11 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/01 18:33:40 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_specialvalues(t_format *fmt, t_vec *tmp, t_fp *fp)
{
	int	prefix;
	char *ptr;
	char *str;

	ptr = tmp->ptr;
	str = ((fp->man & ~HIDDEN_BIT) ? "NAN": "INF");
	prefix = ((fmt->type & 32) ? 32 : 0);
	fmt->type = ('f' | prefix);
	tmp->len = 3;
	while (*str)
		*ptr++ = ((*str++) | prefix);
	fmt->flags &= ~FL_ZERO;
	ft_prefix_double(fmt, tmp, fp);
	ft_pad_double(fmt, tmp, fmt->width - tmp->len, 0);
}

void	ft_adapt2prec(t_format *fmt, t_vec *tmp, t_fp *fp)
{
	uintmax_t mask;
	//printf( "		prec: %d\n", fmt->prec);
	if (fmt->prec > -1 && fmt->prec < 13)
	{
		tmp->len = 1 + fmt->prec;
		mask = 1LU << (MANT_SIZE - (fmt->prec * 4) - 1);
		//printf( "		CHR: %c\n", tmp->ptr[fmt->prec]);
		//printf( "		test: %ld\n", (fp->man & mask));
		tmp->ptr[fmt->prec] += ((fp->man & mask) > 0);
		//printf( "		CHR: %c\n", tmp->ptr[fmt->prec]);
		if ((tmp->ptr[fmt->prec] | 32) == ':')
			tmp->ptr[fmt->prec] = 'A' | (fmt->type & 32);
		else if ((tmp->ptr[fmt->prec] | 32) == 'g')
			tmp->ptr[fmt->prec] = '0';
		//printf( "		CHR: %c\n", tmp->ptr[fmt->prec]);
	}
}
