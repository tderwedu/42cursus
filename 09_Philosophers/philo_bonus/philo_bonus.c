/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:55:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/12 18:55:31 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	sit_philosophers(t_table *table, t_philo *philo)
{
	int		i;

	i = -1;
	while (++i < table->guests)
	{
		table->pid[i] = fork();
		if (table->pid[i] < 0)
			return (philo_exit_error(table, "Fork() error."));
		else if (!table->pid[i])
		{
			philo->id = i + 1;
			philo_routine_bonus(table, philo);
			return (0);
		}
	}
	return (0);
}

static int	dinner_time(t_table *table)
{
	int		i;
	int		wstatus;
	int		ret;

	ret = 0;
	i = -1;
	while (++i < table->guests)
	{
		waitpid(table->pid[i], &wstatus, 0);
		wstatus = WEXITSTATUS(wstatus);
			if (wstatus != 0)
		ret = wstatus;
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	t_table	table;
	t_philo	philo;
	int		ret;

	table.philo = &philo;
	philo.table = &table;
	if (argc < 5 || argc > 6)
		return (philo_exit_error(&table, "Wrong number of argument."));
	if (set_table(argc, argv, &table, &philo))
		return (1);
	if (table.guests == 1)
		return (poor_lonely_philo(&table));
	else
	{
		if (sit_philosophers(&table, &philo))
			return (1);
		ret = dinner_time(&table);
		philo_clear_all(&table, &philo);
		return (ret);
	}
}
