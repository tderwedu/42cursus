/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:13:17 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/13 19:00:48 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print_status(t_philo *philo, int status)
{
	uint64_t	time_stamp;

	if (!check_death(philo->table) && check_sated(philo->table))
		return ;
	time_stamp = philo_get_time() - philo->table->time_t0;
	if (status == THINKING)
		printf("%8llu %i is thinking\n", time_stamp, philo->id);
	else if (status == FORK_TAKEN)
		printf("%8llu %i has taken a fork\n", time_stamp, philo->id);
	else if (status == EATING)
		printf("%8llu %i is eating\n", time_stamp, philo->id);
	else if (status == SLEEPING)
		printf("%8llu %i is sleeping\n", time_stamp, philo->id);
	else if (status == DIED)
		printf("%8llu %i died\n", time_stamp, philo->id);
}

void	philo_usleep(t_philo *philo, uint64_t msec)
{
	uint64_t	start;

	start = philo_get_time();
	while (((philo_get_time() - start) < msec) && check_death(philo->table))
		usleep(100);
}

uint64_t	philo_get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / (uint64_t)1000));
}
