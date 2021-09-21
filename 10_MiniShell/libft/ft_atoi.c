/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:30:29 by namenega          #+#    #+#             */
/*   Updated: 2021/06/07 16:35:44 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	norminette_v3(unsigned long int result, int compteur)
{
	if (result > 2147483648)
	{
		if (compteur == -1)
			return (0);
		else
			return (-1);
	}
	return (compteur);
}

int	ft_atoi(const char *nptr)
{
	int					i;
	int					compteur;
	unsigned long int	result;

	i = 0;
	compteur = 1;
	result = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\f'
		|| nptr[i] == '\r' || nptr[i] == ' ' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			compteur *= -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	compteur = norminette_v3(result, compteur);
	return (result * compteur);
}

/*
** convertir une chaine en entier
** white spaces/+ ou -/conversion
** return entier
*/
