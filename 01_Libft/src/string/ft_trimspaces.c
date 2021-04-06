/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimspaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:11:30 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/06 12:11:47 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_trimspaces(char *str)
{
	register char *start;
	register char *end;

	start = str;
	while (*start && (t_ui)(*start == ' ' || *start - 9U < 4U))
		start++;
	end = start + ft_strlen(start);
	while ((t_ui)(*end == ' ' || *end - 9U < 4U))
		end--;
	return (ft_substr(str, start, end - start));
}
