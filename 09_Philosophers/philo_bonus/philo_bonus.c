/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:55:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/12 15:21:41 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	sit_philosophers(t_table *table, t_philo *philo)
{
	int		i;

	i = -1;
	while (++i < table->guests)
	{
		table->pid[i] = fork();
		if (table->pid[i] < 0)
			return (philo_exit_error(&table, "Fork() error."));
		else if (!table->pid[i])
		{
			philo->id = i + 1;
			philo_routine_bonus(table, philo);
			return (0);
		}
	}
}

int	main(int argc, char **argv)
{
	t_table	table;
	t_philo	philo;

	table.philo = &philo;
	philo.table = &table;
	if (argc < 5 || argc > 6)
		return (philo_exit_error(&table, "Wrong number of argument."));
	if (set_table(argc, argv, &table, &philo))
		return (1);
}
