/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:13:17 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/01 18:58:16 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_get_val(t_uc *nbr)
{
	t_ui	val;

	if (*nbr == '\0')
		return (-1);
	val = 0;
	while ((*nbr == ' ' || *nbr - 9U < 4U))
		nbr++;
	nbr += (*nbr == '+');
	if (!((*nbr - 48U) < 10U))
		return (-1);
	while ((*nbr - 48U) < 10U)
		val = val * 10 + (*nbr++ - '0');
	if (*nbr != '\0' || val == 0)
		return (-1);
	return (val);
}

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

	pthread_mutex_lock(philo->m_philo);
	ret = (philo->nbr_of_meals != table->must_eat_count);
	pthread_mutex_unlock(philo->m_philo);
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

void	philo_print_status(t_philo *philo, int status)
{
	uint64_t	time_stamp;

	if (!check_all_alive(philo->table))
		return ;
	time_stamp = get_time() - table->start_time;
	if (e_action == THINKING)
		printf("%.8i %lu is thinking\n", time_stamp, philo->number);
	else if (e_action == TOOK_FORK)
		printf("%.8i %lu has taken a fork\n", time_stamp, philo->number);
	else if (e_action == EATING)
		printf("%.8i %lu is eating\n", time_stamp, philo->number);
	else if (e_action == SLEEPING)
		printf("%.8i %lu is sleeping\n", time_stamp, philo->number);
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
