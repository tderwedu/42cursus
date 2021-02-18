/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:50:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/18 16:02:11 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ui	ft_parse_prec(char **str, va_list *ap)
{
	t_ui			ret;
	register char	*ptr;

	ret = 6;
	ptr = *str;
	if (*ptr && *ptr == '.' && *(ptr + 1))
	{
		ptr++;
		ret = 0;
		if (FT_ISDIGIT(*ptr))
			while (*ptr && FT_ISDIGIT(*ptr))
				ret = ret * 10 + *ptr++ - '0';
		else if (*ptr == '-')
			ptr++;
		else if (*ptr++ == '*')
			ret = va_arg(*ap, int);
		else
			ret = -1;
		*str = ptr;
	}
	if (!*str)
		return (-1);
	return (ret);
}
