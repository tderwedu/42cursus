/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:12:51 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/01 18:58:13 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_get_args(int argc, char **argv, t_table *table)
{
	table->nbr_philos = philo_get_val(argv[1]);
	if (table->nbr_philos == -1)
		return(philo_exit_error(table, "Bad argument"));
	table->time_to_die = philo_get_val(argv[2]);
	if (table->time_to_die == -1)
		return(philo_exit_error(table, "Bad argument"));
	table->time_to_eat = philo_get_val(argv[3]);
	if (table->time_to_eat == -1)
		return(philo_exit_error(table, "Bad argument"));
	table->time_to_sleep = philo_get_val(argv[4]);
	if (table->time_to_sleep == -1)
		return(philo_exit_error(table, "Bad argument"));
	if (argc == 6)
	{
		table->must_eat_count = philo_get_val(argv[5]);
		if (table->must_eat_count == -1)
			return(philo_exit_error(table, "Bad argument"));
	}
	else
		table->must_eat_count = -1;
	table->philos = NULL;
	table->forks = NULL;
	return (0);
}

void	philo_init_mutex(t_table *table)
{
	int	i;

	table->m_forks = malloc(sizeof(table->m_forks) * table->nbr_philos);
	if (!(table->m_forks))
		return(philo_exit_error(table, "Malloc error"));
	pthread_mutex_init(&table->m_table, NULL);
	// pthread_mutex_init(&table->m_write, NULL);
	i = -1;
	while (++i < table->nbr_philos)
		pthread_mutex_init(&(table->m_forks + i), NULL);
}

void	philo_init_philo(t_table *table)
{
	int	i;

	table->philos = malloc(sizeof(table->philos) * table->nbr_philos);
	if (!(table->philos))
		return(philo_exit_error(table, "Malloc error"));
	i = -1;
	while (++i < table->nbr_philos)
	{
		table->philos[i].table = table;
		table->philos[i].nbr = i + 1;
		table->philos[i].nbr_of_meals = 0;
		table->philos[i].m_fork_1 = table->forks[i];
		table->philos[i].m_fork_2 = table->forks[(i + 1) % table->nbr_philos];
		pthread_mutex_init(&table->philos[i].m_philo, NULL);
	}
	i--;
	table->philos[i].m_fork_1 = table->forks[0];
	table->philos[i].m_fork_2 = table->forks[i];
}

int	philo_init(int argc, char **argv, t_table *table)
{
	if (philo_get_args(argc, argv, &table))
		return (1);
	if (table->nbr_philos == 1)
		return (philo_poor_lonely_philo(table));
	philo_init_philo(table);
	return (0);
}
