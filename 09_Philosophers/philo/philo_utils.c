/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:13:17 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/06 12:07:57 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print_status(t_philo *philo, int status)
{
	uint64_t	time_stamp;

	if (!check_all_alive(philo->table))
		return ;
	time_stamp = get_time() - philo->table->start_time;
	if (status == THINKING)
		printf("%.8lu %i is thinking\n", time_stamp, philo->number);
	else if (status == FORK_TAKEN)
		printf("%.8lu %i has taken a fork\n", time_stamp, philo->number);
	else if (status == EATING)
		printf("%.8lu %i is eating\n", time_stamp, philo->number);
	else if (status == SLEEPING)
		printf("%.8lu %i is sleeping\n", time_stamp, philo->number);
}

void	philo_sleep(t_philo *philo, uint64_t msec)
{
	uint64_t	start;
	
	start = get_time();
	while (((get_time() - start) < msec) && check_all_alive(philo->table))
		usleep(100);
}

uint64_t	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / (uint64_t)1000));
}
