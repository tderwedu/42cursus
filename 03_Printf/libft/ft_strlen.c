/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:24:23 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/26 11:24:30 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_libft.h"

size_t	ft_strlen(const char *s)
{
	register size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
