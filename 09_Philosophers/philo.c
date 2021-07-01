/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:55:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/01 14:32:08 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	philo_think(t_philo *philo)
{
	t_table *table;

	table = philo->table;
	pthread_mutex_lock(&philo->m_fork_1);
	printf("%i %i has taken a fork\n", get_time() - table->start_time, philo->number);
	pthread_mutex_lock(&philo->m_fork_2);
	printf("%i %i has taken a fork\n", get_time() - table->start_time, philo->number);
}

void	philo_eat(t_philo *philo)
{
	t_table *table;

	table = philo->table;
	if ((get_time() - philo->last_meal) < table->time_to_die)
	{
		pthread_mutex_lock(&philo->m_philo);
		philo->last_meal = get_time();
		philo->nbr_of_meals++;
		pthread_mutex_unlock(&philo->m_philo);
		printf("%i %i is eating\n", get_time() - table->start_time, philo->number);
		usleep(table->time_to_eat);
	}
	else
	{
		pthread_mutex_lock(&table->m_all_alive);
		table->all_alive = 0;
		pthread_mutex_lock(&table->m_all_alive);
	}
}

void	philo_sleep(t_philo *philo)
{
	t_table *table;

	table = philo->table;
	pthread_mutex_unlock(&philo->m_fork_1);
	pthread_mutex_unlock(&philo->m_fork_2);
	printf("%i %i is sleeping\n", get_time() - table->start_time, philo->number);
	usleep(table->time_to_sleep);
}


void	*philo_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo*)args;
	pthread_mutex_lock(&philo->m_philo);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->m_philo);
}

int	main(int argc, char **argv)
{
	t_table table;

	if (argc < 5 || argc > 6)
		return(exit_error("Wrong number of argument"));
	if (philo_init(argc, argv, &table))
		return (1);

	// struct timeval tv_1;
	// struct timeval tv_2;
	// gettimeofday(&tv_1, NULL);
	// sleep(2);
	// gettimeofday(&tv_2, NULL);
	// printf("sec: %li\n", tv_2.tv_sec - tv_1.tv_sec);
	// printf("usec: %li\n", tv_2.tv_usec - tv_1.tv_usec);
}
