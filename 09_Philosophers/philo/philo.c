/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:55:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/13 17:25:31 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dinner_time(t_table *table)
{
	int			i;
	t_philo		*philo;

	table->time_t0 = philo_get_time();
	i = 0;
	while (i < table->guests)
	{
		philo = &table->philo[i];
		if (pthread_create(&(table->tid[i]), NULL, &philo_routine, philo))
			return (philo_exit_error(table, ERR_PTHREAD));
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
		return (philo_exit_error(&table, ERR_NBR_ARG));
	if (set_the_table(argc, argv, &table))
		return (1);
	if (table.guests == 1 && table.meals != 0)
		return (poor_lonely_philo(&table));
	else
	{
		if (table.meals == 0)
			return (0);
		if (dinner_time(&table))
			return (1);
		i = -1;
		while (++i < table.guests)
			pthread_join(table.tid[i], NULL);
		philo_clear_all(&table);
	}
}
