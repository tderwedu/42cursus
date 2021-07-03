/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:13:13 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/01 18:58:13 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_clear_all(t_table *table)
{
	int	i;

	if (table->m_forks)
	{
		i = -1;
		while (++i < table->nbr_philos)
			pthread_mutex_destroy(&table->m_forks[i]);
		free(table->m_forks);
	}
	if (table->philos)
	{
		i = -1;
		while (++i < table->nbr_philos)
			pthread_mutex_destroy(&table->philos[i].m_philo);
		free(table->philos);
	}
	// pthread_mutex_destroy(&table->m_write);
	pthread_mutex_destroy(&table->m_table);
	return (1);
}

int	philo_poor_lonely_philo(t_table *table)
{
	table->start_time = get_time();
	usleep(table->time_to_die);
	printf("%i 1 died\n", get_time() - table->start_time);
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
