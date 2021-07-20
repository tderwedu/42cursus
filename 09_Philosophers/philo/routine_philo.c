/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:38:54 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/20 16:34:27 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline int	sit_philo(t_philo *philo, t_table *table, pthread_t *pid)
{
	int64_t	time_stamp;

	pthread_mutex_lock(&philo->m_philo);
	philo->last_meal = philo_get_time();
	pthread_mutex_unlock(&philo->m_philo);
	if (pthread_create(pid, NULL, &reaper_routine, philo))
	{
		philo_exit_error(table, ERR_PTHREAD);
		pthread_mutex_lock(&table->m_table);
		table->death = 1;
		pthread_mutex_unlock(&table->m_table);
		return (1);
	}
	time_stamp = table->time_to_eat - (philo_get_time() - table->time_t0);
	if (table->guests % 2 == 0 && philo->id % 2 != 0 && time_stamp > 0)
		philo_usleep(philo, time_stamp);
	return (0);
}

static inline void	philo_think(t_philo *philo, t_table *table)
{
	philo_print_status(philo, THINKING);
	if (table->guests % 2 != 0)
		philo_usleep(philo, 5);
	pthread_mutex_lock(philo->m_fork_1);
	philo_print_status(philo, FORK_TAKEN);
	pthread_mutex_lock(philo->m_fork_2);
	philo_print_status(philo, FORK_TAKEN);
}

static inline int	philo_eat(t_philo *philo, t_table *table)
{
	int64_t	time_stamp;
	int64_t	starving_time;

	time_stamp = philo_get_time();
	pthread_mutex_lock(&philo->m_philo);
	starving_time = time_stamp - philo->last_meal;
	if (!check_death(table) || starving_time >= table->time_to_die)
	{
		pthread_mutex_unlock(&philo->m_philo);
		pthread_mutex_unlock(philo->m_fork_1);
		pthread_mutex_unlock(philo->m_fork_2);
		return (1);
	}
	philo->last_meal = time_stamp;
	if (table->meals != -1)
		philo->meals++;
	pthread_mutex_unlock(&philo->m_philo);
	philo_print_status(philo, EATING);
	philo_usleep(philo, table->time_to_eat);
	return (0);
}

static inline void	philo_sleep(t_philo *philo, t_table *table)
{
	pthread_mutex_unlock(philo->m_fork_1);
	pthread_mutex_unlock(philo->m_fork_2);
	if (philo->meals == table->meals)
	{
		pthread_mutex_lock(&table->m_table);
		table->sated++;
		pthread_mutex_unlock(&table->m_table);
	}
	philo_print_status(philo, SLEEPING);
	philo_usleep(philo, table->time_to_sleep);
}

void	*philo_routine(void *args)
{
	t_philo		*philo;
	t_table		*table;
	pthread_t	waiter;

	philo = (t_philo *)args;
	table = philo->table;
	if (sit_philo(philo, table, &waiter))
		return (NULL);
	while (check_death(table) && check_sated(table))
	{
		philo_think(philo, table);
		if (philo_eat(philo, table))
			break ;
		philo_sleep(philo, table);
	}
	pthread_join(waiter, NULL);
	return (NULL);
}
