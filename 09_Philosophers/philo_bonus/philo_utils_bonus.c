/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:13:17 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/13 19:00:48 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_print_status(t_philo *philo, int status)
{
	uint64_t	time_stamp;

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

void	philo_sem_name(char *name, int id)
{
	int		i;
	char	*prefix;

	i = -1;
	prefix = SEM_PHILO;
	while (++i < 11)
		name[i] = prefix[i];
	name[i] = id / 100 + '0';
	id %= 100;
	name[++i] = id / 10 + '0';
	id %= 10;
	name[++i] = id + '0';
	name[++i] = '\0';
}

void	philo_usleep(uint64_t msec)
{
	uint64_t	start;

	start = philo_get_time();
	while (((philo_get_time() - start) < msec))
		usleep(100);
}

uint64_t	philo_get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / (uint64_t)1000));
}
