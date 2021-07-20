/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:55:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/15 11:02:41 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	sit_philo(t_table *table, t_philo *philo)
{
	int	i;

	table->time_t0 = philo_get_time();
	i = -1;
	while (++i < table->guests)
	{
		philo->id++;
		table->pid[i] = fork();
		if (table->pid[i] < 0)
			return (philo_exit_error(table, ERR_FORK));
		else if (!table->pid[i])
		{
			philo_routine_bonus(table, philo);
			return (0);
		}
	}
	return (0);
}

static int	dinner_time(t_table *table)
{
	int	i;
	int	wstatus;
	int	ret;

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

	table = (t_table){0, 0, 0, NULL, 0, 0, 0, 0, NULL,
		NULL, NULL, NULL, &philo};
	philo.table = &table;
	if (argc < 5 || argc > 6)
		return (philo_exit_error(&table, ERR_NBR_ARG));
	if (set_table(argc, argv, &table, &philo))
		return (1);
	if (table.guests == 1 && table.meals != 0)
		return (poor_lonely_philo(&table));
	else
	{
		if (table.meals == 0)
			return (0);
		if (sit_philo(&table, &philo))
			return (1);
		ret = dinner_time(&table);
		philo_clear_all(&table, &philo);
		return (ret);
	}
}
