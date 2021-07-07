/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:13:17 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/07 23:22:13 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print_status(t_philo *philo, int status)
{
	uint64_t	time_stamp;
	uint64_t	delta_time;

	if (!check_death(philo->table) && check_meals(philo))
		return ;
	time_stamp = get_time();
	delta_time = time_stamp - philo->table->start_time;
	if (status == THINKING)
		printf("%.8llu %i is thinking\n", delta_time, philo->id);
	else if (status == FORK_TAKEN)
		printf("%.8llu %i has taken a fork\n", delta_time, philo->id);
	else if (status == EATING)
		printf("%.8llu %i is eating\n", delta_time, philo->id);
	else if (status == SLEEPING)
		printf("%.8llu %i is sleeping\n", delta_time, philo->id);
}

void	philo_sleep(t_philo *philo, uint64_t msec)
{
	uint64_t	start;
	
	start = get_time();
	while (((get_time() - start) < msec) && check_death(philo->table))
		usleep(100);
}

uint64_t	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / (uint64_t)1000));
}
