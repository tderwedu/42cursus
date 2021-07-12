/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_routine_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:40:21 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/12 14:06:36 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*waiter_routine_bonus(void *args)
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
		philo_usleep(philo, starving_time);
		sem_wait(philo->sem_philo);
		if (starving_time >= table->time_to_die)
		{
			philo_print_status(philo, DIED);
			sem_post(&table->sem_dead);
			break ;
		}
		sem_post(philo->sem_philo);
	}
	return (NULL);
}
