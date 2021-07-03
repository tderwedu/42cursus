/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:55:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/01 19:07:09 by tderwedu         ###   ########.fr       */
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
		pthread_mutex_lock(&philo->m_fork_1);
		philo_print_status(philo, TOOK_FORK);
		pthread_mutex_lock(&philo->m_fork_2);
		philo_print_status(philo, TOOK_FORK);
		time_stamp = get_time();
		pthread_mutex_lock(&philo->m_philo);
		if ((time_stamp - philo->last_meal) >= table->time_to_die)
		{
			pthread_mutex_lock(&table->m_table);
			table->all_alive = 0;
			pthread_mutex_unlock(&philo->m_philo);
			pthread_mutex_unlock(&table->m_table);
			pthread_mutex_unlock(&philo->m_fork_1);
			pthread_mutex_unlock(&philo->m_fork_2);
			printf("%.8i %lu has taken a fork\n", time_stamp, philo->number);
			break ;
		}
		philo->last_meal = time_stamp;
		if (table->must_eat_count != -1)
			philo->nbr_of_meals++;
		pthread_mutex_unlock(&philo->m_philo);
		philo_print_status(philo, EATING);
		usleep(1000 * table->time_to_eat);
		pthread_mutex_unlock(&philo->m_fork_1);
		pthread_mutex_unlock(&philo->m_fork_2);
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

void	*waiter_routine(void *args)
{
	int			i;
	t_table		*table;
	t_philo		*philo;
	uint64_t	starving_time;

	table = (t_philo*)args;
	while (!check_sated_philos(table) && check_all_alive(table))
	{
		i = -1;
		while (++i < table->nbr_philos)
		{
			philo = table->philos[i];
			pthread_mutex_lock(&philo->m_philo);
			starving_time = get_time() - philo->last_meal;
			pthread_mutex_unlock(&philo->m_philo);
			if (starving_time >= table->time_to_die)
			{
				pthread_mutex_lock(&table->m_table);
				table->all_alive = 0;
				pthread_mutex_unlock(&table->m_table);
				break ;
			}
		}
	}
}

int	main(int argc, char **argv)
{
	t_table table;

	if (argc < 5 || argc > 6)
		return(exit_error("Wrong number of argument"));
	if (philo_init(argc, argv, &table))
		return (1);


}
