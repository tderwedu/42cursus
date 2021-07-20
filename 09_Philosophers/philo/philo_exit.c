/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:13:13 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/20 16:51:57 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_clear_all(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->guests && table->philo[i].id == (i + 1))
	{
		pthread_mutex_destroy(&table->m_forks[i]);
		pthread_mutex_destroy(&table->philo[i].m_philo);
	}
	if (table->m_forks)
		free(table->m_forks);
	if (table->philo)
		free(table->philo);
	if (table->tid)
		free(table->tid);
	pthread_mutex_destroy(&table->m_table);
	return (1);
}

int	poor_lonely_philo(t_table *table)
{
	table->time_t0 = philo_get_time();
	printf("%8lu 1 is thinking\n", philo_get_time() - table->time_t0);
	printf("%8lu 1 has taken a fork\n", philo_get_time() - table->time_t0);
	usleep(1000 * table->time_to_die);
	printf("%8lu 1 died\n", philo_get_time() - table->time_t0);
	philo_clear_all(table);
	return (0);
}

int	philo_exit_error(t_table *table, char *str)
{
	printf("Error:\n");
	printf("%s\n", str);
	philo_clear_all(table);
	return (1);
}
