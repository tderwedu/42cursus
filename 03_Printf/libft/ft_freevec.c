/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freevec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:35:35 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/26 17:40:21 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_libft.h"
#include <stdio.h> //TODO: remove

int		ft_freevec(t_vec *vec)
{
	free(vec->begin);
	free(vec);
	return (1);
}