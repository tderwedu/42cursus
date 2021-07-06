/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:57:38 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/06 11:57:49 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_all_alive(t_table *table)
{
	int	ret;

	pthread_mutex_lock(&table->m_table);
	ret = table->all_alive;
	pthread_mutex_unlock(&table->m_table);
	return (ret);
}

int	check_nbr_meals(t_philo *philo)
{
	int	ret;

	pthread_mutex_lock(&philo->m_philo);
	ret = (philo->nbr_of_meals != philo->table->must_eat_count);
	pthread_mutex_unlock(&philo->m_philo);
	return (ret);
}

int	check_sated_philos(t_table *table)
{
	int	ret;

	pthread_mutex_lock(&table->m_table);
	ret = (table->sated_philos == table->nbr_philos);
	pthread_mutex_unlock(&table->m_table);
	return (ret);
}
