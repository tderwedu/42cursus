/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:57:38 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/08 15:23:07 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_table *table)
{
	int	ret;

	pthread_mutex_lock(&table->m_table);
	ret = !table->death;
	pthread_mutex_unlock(&table->m_table);
	return (ret);
}

int	check_sated(t_table *table)
{
	int	ret;

	pthread_mutex_lock(&table->m_table);
	ret = (table->sated != table->guest);
	pthread_mutex_unlock(&table->m_table);
	return (ret);
}
