/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:55:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/07 23:22:13 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *args)
{
	t_philo		*philo;
	t_table		*table;
	int64_t		time_stamp;
	int64_t		starving;
	pthread_t	waiter;

	philo = (t_philo*)args;
	table = philo->table;
	pthread_mutex_lock(&philo->m_philo);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->m_philo);
	if (pthread_create(&waiter, NULL, &waiter_routine, philo))
	{
		philo_exit_error(table, "pthread_create fail.");
		return (NULL);
	}
	while (check_death(table) && check_meals(philo))
	{
		philo_print_status(philo, THINKING);
		pthread_mutex_lock(philo->m_fork_1);
		philo_print_status(philo, FORK_TAKEN);
		pthread_mutex_lock(philo->m_fork_2);
		philo_print_status(philo, FORK_TAKEN);
		time_stamp = get_time();
		pthread_mutex_lock(&philo->m_philo);
		starving = time_stamp - philo->last_meal;
		if (!check_death(table) || starving >= table->time_to_die)
		{
			pthread_mutex_unlock(&philo->m_philo);
			pthread_mutex_unlock(philo->m_fork_1);
			pthread_mutex_unlock(philo->m_fork_2);
			break ;
		}
		philo->last_meal = time_stamp;
		if (table->meals != -1)
			philo->meals++;
		pthread_mutex_unlock(&philo->m_philo);
		philo_print_status(philo, EATING);
		philo_sleep(philo, table->time_to_eat);
		pthread_mutex_unlock(philo->m_fork_1);
		pthread_mutex_unlock(philo->m_fork_2);
		philo_print_status(philo, SLEEPING);
		philo_sleep(philo, table->time_to_sleep);
	}
	pthread_join(waiter, NULL);
	return (NULL);
}

void	*waiter_routine(void *args)
{
	t_philo		*philo;
	t_table		*table;
	int64_t		time_stamp;
	int64_t		starving;

	philo = (t_philo*)args;
	table = philo->table;
	while (check_death(table) && check_meals(philo))
	{
		pthread_mutex_lock(&philo->m_philo);
		time_stamp = philo->last_meal;
		pthread_mutex_unlock(&philo->m_philo);
		time_stamp += table->time_to_die - get_time();
		philo_sleep(philo, time_stamp);
		time_stamp = get_time();
		pthread_mutex_lock(&philo->m_philo);
		starving = time_stamp - philo->last_meal;
		if (starving >= table->time_to_die)
		{
			pthread_mutex_unlock(&philo->m_philo);
			pthread_mutex_lock(&table->m_table);
			if (!table->death)
				printf("%.8llu %i died\n", time_stamp - table->start_time, philo->id);
			table->death = 1;
			pthread_mutex_unlock(&table->m_table);
			break ;
		}
		pthread_mutex_unlock(&philo->m_philo);
	}
	return (NULL);
}

int start_threads(t_table *table)
{
	int			i;
	t_philo		*philo;

	table->start_time = get_time();
	i = 0;
	while (i < table->nbr_philos)
	{
		philo = &table->philos[i];
		if (pthread_create(&(table->tid[i]), NULL, &philo_routine, philo))
			return (philo_exit_error(table, "pthread_create fail."));
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	t_table table;

	if (argc < 5 || argc > 6)
		return(philo_exit_error(&table, "Wrong number of argument."));
	if (philo_init(argc, argv, &table))
		return (1);
	if (table.nbr_philos == 1)
		return (philo_poor_lonely_philo(&table));
	else
	{
		if (start_threads(&table))
			return (1);
		i = -1;
		while (++i < table.nbr_philos)
			pthread_join(table.tid[i], NULL);
		philo_clear_all(&table);
	}
}
