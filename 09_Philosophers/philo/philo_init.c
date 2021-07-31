/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:12:51 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/25 14:17:36 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	get_arg(t_uc *nbr)
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
	if (*nbr != '\0')
		return (-1);
	return (val);
}

static int	lay_the_table(int argc, char **argv, t_table *table)
{
	table->guests = get_arg((t_uc *)argv[1]);
	table->time_to_die = get_arg((t_uc *)argv[2]);
	table->time_to_eat = get_arg((t_uc *)argv[3]);
	table->time_to_sleep = get_arg((t_uc *)argv[4]);
	if (table->guests < 1 || table->time_to_die == -1
		|| table->time_to_eat == -1 || table->time_to_sleep == -1)
		return (philo_free_error(table, ERR_BAD_ARG));
	if (argc == 6)
	{
		table->meals = get_arg((t_uc *)argv[5]);
		if (table->meals == -1)
			return (philo_free_error(table, ERR_BAD_ARG));
	}
	else
		table->meals = -1;
	table->tid = malloc(sizeof(pthread_t) * table->guests);
	table->m_forks = malloc(sizeof(*table->m_forks) * table->guests);
	table->philo = malloc(sizeof(*table->philo) * table->guests);
	if (!(table->m_forks) || !table->tid || !(table->philo))
		return (philo_free_error(table, ERR_MALLOC));
	return (0);
}

int	set_the_table(int argc, char **argv, t_table *table)
{
	int		i;
	t_philo	*philo;

	pthread_mutex_init(&table->m_table, NULL);
	if (lay_the_table(argc, argv, table))
		return (1);
	i = -1;
	while (++i < table->guests)
	{
		philo = &table->philo[i];
		philo->table = table;
		philo->id = i + 1;
		philo->meals = 0;
		philo->m_fork_1 = &table->m_forks[i];
		philo->m_fork_2 = &table->m_forks[(i + 1) % table->guests];
		if ((i % 2) != 0)
		{
			philo->m_fork_1 = &table->m_forks[(i + 1) % table->guests];
			philo->m_fork_2 = &table->m_forks[i];
		}
		pthread_mutex_init(&philo->m_philo, NULL);
		pthread_mutex_init(&table->m_forks[i], NULL);
	}
	return (0);
}
