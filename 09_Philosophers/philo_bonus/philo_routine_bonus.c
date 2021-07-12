/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:38:54 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/12 15:01:43 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	exit_process(t_table *table)
{
	printf("pthread_create fail.");
	sem_post(table->sem_dead);
	exit(EXIT_FAILURE);
}

void	philo_routine_bonus(t_table *table, t_philo *philo)
{
	pthread_t	dead;
	pthread_t	sated;
	pthread_t	waiter;

	get_sem_nam(philo->sem_name, philo->id);
	sem_unlink(philo->sem_name);
	sem_open(philo->sem_name, O_CREAT, 0660, 1);
	philo->last_meal = philo_get_time();
	if (pthread_create(&dead, NULL, &dead_routine_bonus, table))
		exit_process(table);
	if (pthread_create(&sated, NULL, &sated_routine_bonus, table))
		exit_process(table);
	if (pthread_create(&waiter, NULL, &waiter_routine_bonus, philo))
		exit_process(table);
	while (1)
	{
		philo_print_status(philo, THINKING);
		sem_wait(table->sem_seats);
		sem_wait(table->sem_forks);
		philo_print_status(philo, FORK_TAKEN);
		sem_wait(table->sem_forks);
		philo_print_status(philo, FORK_TAKEN);
		sem_wait(philo->sem_philo);
		philo_print_status(philo, EATING);
		philo->last_meal = philo_get_time();
		sem_post(philo->sem_philo);
		philo_usleep(philo, table->time_to_eat);
		sem_wait(philo->sem_philo);
		if (table->meals > 0)
			philo->meals++;
		if (philo->meals == table->meals)
			sem_post(table->sem_sated);
		sem_post(philo->sem_philo);
		sem_post(table->sem_forks);
		sem_post(table->sem_forks);
		sem_post(table->sem_seats);
		philo_print_status(philo, SLEEPING);
		philo_usleep(philo, table->time_to_sleep);
	}
}
