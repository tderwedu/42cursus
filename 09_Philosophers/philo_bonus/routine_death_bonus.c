/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_death_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:40:21 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/13 15:31:59 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static inline void	dying_philo(t_table *table, t_philo *philo)
{
	philo_print_status(philo, DIED);
	sem_post(table->sem_exit);
	sem_post(table->sem_exit);
	sem_post(table->sem_exit);
	exit(EXIT_SUCCESS);
}

void	*death_routine_bonus(void *args)
{
	t_philo		*philo;
	t_table		*table;
	int64_t		starving_time;

	philo = (t_philo *)args;
	table = philo->table;
	while (1)
	{
		sem_wait(philo->sem_philo);
		starving_time = philo->last_meal;
		sem_post(philo->sem_philo);
		starving_time += table->time_to_die - philo_get_time();
		philo_usleep(starving_time);
		sem_wait(philo->sem_philo);
		starving_time = philo_get_time() - philo->last_meal;
		if (starving_time >= table->time_to_die)
		{
			dying_philo(table, philo);
			break ;
		}
		sem_post(philo->sem_philo);
	}
	return (NULL);
}
