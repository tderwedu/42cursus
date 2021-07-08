/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:55:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/08 19:21:56 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_threads(t_table *table)
{
	int			i;
	t_philo		*philo;

	table->time_t0 = philo_get_time();
	i = 0;
	while (i < table->guest)
	{
		philo = &table->philo[i];
		if (pthread_create(&(table->tid[i]), NULL, &philo_routine, philo))
			return (philo_exit_error(table, "pthread_create fail."));
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	t_table	table;

	table.tid = NULL;
	table.philo = NULL;
	table.m_forks = NULL;
	table.death = 0;
	table.sated = 0;
	if (argc < 5 || argc > 6)
		return (philo_exit_error(&table, "Wrong number of argument."));
	if (set_the_table(argc, argv, &table))
		return (1);
	if (table.guest == 1)
		return (poor_lonely_philo(&table));
	else
	{
		if (start_threads(&table))
			return (1);
		i = -1;
		while (++i < table.guest)
			pthread_join(table.tid[i], NULL);
		philo_clear_all(&table);
	}
}
