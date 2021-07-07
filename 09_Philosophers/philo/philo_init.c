/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:12:51 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/07 22:55:26 by tderwedu         ###   ########.fr       */
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

int	philo_get_args(int argc, char **argv, t_table *table)
{
	table->nbr_philos = philo_get_val((t_uc*)argv[1]);
	if (table->nbr_philos == -1)
		return(philo_exit_error(table, "Bad argument."));
	table->time_to_die = philo_get_val((t_uc*)argv[2]);
	if (table->time_to_die == -1)
		return(philo_exit_error(table, "Bad argument."));
	table->time_to_eat = philo_get_val((t_uc*)argv[3]);
	if (table->time_to_eat == -1)
		return(philo_exit_error(table, "Bad argument."));
	table->time_to_sleep = philo_get_val((t_uc*)argv[4]);
	if (table->time_to_sleep == -1)
		return(philo_exit_error(table, "Bad argument."));
	if (argc == 6)
	{
		table->meals = philo_get_val((t_uc*)argv[5]);
		if (table->meals == -1)
			return(philo_exit_error(table, "Bad argument."));
	}
	else
		table->meals = -1;
	table->philos = NULL;
	table->m_forks = NULL;
	table->death = 0;
	table->tid = malloc(sizeof(pthread_t) * table->nbr_philos);
	if (!table->tid)
		return(philo_exit_error(table, "Malloc error."));
	return (0);
}

int	philo_init_philo(t_table *table)
{
	int		i;
	t_philo	*philo;

	table->philos = malloc(sizeof(*table->philos) * table->nbr_philos);
	if (!(table->philos))
		return(philo_exit_error(table, "Malloc error."));
	i = -1;
	while (++i < table->nbr_philos)
	{
		philo = &table->philos[i];
		philo->table = table;
		philo->id = i + 1;
		philo->meals = 0;
		if ((i % 2) == 0)
		{
			philo->m_fork_1 = &table->m_forks[i];
			philo->m_fork_2 = &table->m_forks[(i + 1) % table->nbr_philos];
		}
		else
		{
			philo->m_fork_1 = &table->m_forks[(i + 1) % table->nbr_philos];
			philo->m_fork_2 = &table->m_forks[i];
		}
		pthread_mutex_init(&philo->m_philo, NULL);
	}
	return (0);
}

int	philo_init_mutex(t_table *table)
{
	int	i;

	table->m_forks = malloc(sizeof(*table->m_forks) * table->nbr_philos);
	if (!(table->m_forks))
		return (philo_exit_error(table, "Malloc error."));
	pthread_mutex_init(&table->m_table, NULL);
	i = -1;
	while (++i < table->nbr_philos)
		pthread_mutex_init(&table->m_forks[i], NULL);
	return (0);
}

int	philo_init(int argc, char **argv, t_table *table)
{
	if (philo_get_args(argc, argv, table))
		return (1);
	if (philo_init_mutex(table))
		return (1);
	if (philo_init_philo(table))
		return (1);
	return (0);
}
