/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_reaper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:40:21 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/13 18:16:55 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline void	waiter_sleep(t_philo *philo, t_table *table)
{
	int64_t	starving_time;

	pthread_mutex_lock(&philo->m_philo);
	starving_time = philo->last_meal;
	pthread_mutex_unlock(&philo->m_philo);
	starving_time += table->time_to_die - philo_get_time();
	if (starving_time > 0)
		philo_usleep(philo, starving_time);
}

static inline void	philo_died(t_philo *philo, t_table *table)
{
	pthread_mutex_unlock(&philo->m_philo);
	if (check_death(table))
		philo_print_status(philo, DIED);
	pthread_mutex_lock(&table->m_table);
	table->death = 1;
	pthread_mutex_unlock(&table->m_table);
}

void	*reaper_routine(void *args)
{
	t_philo		*philo;
	t_table		*table;
	int64_t		starving_time;

	philo = (t_philo *)args;
	table = philo->table;
	while (check_death(table) && check_sated(table))
	{
		waiter_sleep(philo, table);
		if (!check_sated(table))
			break ;
		pthread_mutex_lock(&philo->m_philo);
		starving_time = philo_get_time() - philo->last_meal;
		if (starving_time >= table->time_to_die)
		{
			philo_died(philo, table);
			break ;
		}
		pthread_mutex_unlock(&philo->m_philo);
	}
	return (NULL);
}
