/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:55:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/06 12:30:47 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *args)
{
	t_philo		*philo;
	t_table		*table;
	uint64_t	time_stamp;

	philo = (t_philo*)args;
	table = philo->table;
	pthread_mutex_lock(&philo->m_philo);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->m_philo);
	
	while (check_all_alive(philo->table) && check_nbr_meals(philo))
	{
		philo_print_status(philo, THINKING);
		pthread_mutex_lock(philo->m_fork_1);
		philo_print_status(philo, FORK_TAKEN);
		pthread_mutex_lock(philo->m_fork_2);
		philo_print_status(philo, FORK_TAKEN);
		time_stamp = get_time();
		pthread_mutex_lock(&philo->m_philo);
		if ((time_stamp - philo->last_meal) >= (t_ui)table->time_to_die)
		{
			pthread_mutex_unlock(&philo->m_philo);
			pthread_mutex_lock(&table->m_table);
			table->all_alive = 0;
			pthread_mutex_unlock(&table->m_table);
			pthread_mutex_unlock(philo->m_fork_1);
			pthread_mutex_unlock(philo->m_fork_2);
			printf("%.8lu %i has taken a fork\n", time_stamp, philo->number);
			break ;
		}
		philo->last_meal = time_stamp;
		if (table->must_eat_count != -1)
			philo->nbr_of_meals++;
		pthread_mutex_unlock(&philo->m_philo);
		philo_print_status(philo, EATING);
		usleep(1000 * table->time_to_eat);
		pthread_mutex_unlock(philo->m_fork_1);
		pthread_mutex_unlock(philo->m_fork_2);
		philo_print_status(philo, SLEEPING);
		usleep(1000 * table->time_to_sleep);
	}
	if (table->must_eat_count != -1)
	{
		pthread_mutex_lock(&table->m_table);
		table->sated_philos++;
		pthread_mutex_unlock(&table->m_table);
	}
	return (NULL);
}

void	waiter_routine(t_table *table)
{
	int			i;
	t_philo		*philo;
	uint64_t	starving_time;

	while (!check_sated_philos(table) && check_all_alive(table))
	{
		i = -1;
		while (++i < table->nbr_philos)
		{
			philo = &table->philos[i];
			pthread_mutex_lock(&philo->m_philo);
			starving_time = get_time() - philo->last_meal;
			pthread_mutex_unlock(&philo->m_philo);
			if (starving_time >= (uint64_t)table->time_to_die)
			{
				pthread_mutex_lock(&table->m_table);
				table->all_alive = 0;
				pthread_mutex_unlock(&table->m_table);
				break ;
			}
		}
	}
}

int start_threads(t_table *table)
{
	int			i;
	pthread_t	tid;
	void		*philo;

	table->start_time = get_time();
	i = 0;
	while (i < table->nbr_philos)
	{
		table->philos[i].last_meal = get_time();
		philo = (void*)(&table->philos[i]);
		if (!pthread_create(&tid, NULL, &philo_routine, philo))
			return (philo_exit_error(table, "pthread_create fail."));
		pthread_detach(tid);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table table;

	if (argc < 5 || argc > 6)
		return(philo_exit_error(&table, "Wrong number of argument."));
	if (philo_init(argc, argv, &table))
		return (1);
	if (start_threads(&table))
		return (1);
	waiter_routine(&table);
	philo_clear_all(&table);
}
