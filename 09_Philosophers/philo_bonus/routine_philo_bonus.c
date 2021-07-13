/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:38:54 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/13 19:00:10 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	exit_process_error(t_table *table, char *str)
{
	printf("Error:\n");
	printf("%s\n", str);
	sem_post(table->sem_exit);
	sem_post(table->sem_exit);
	sem_post(table->sem_exit);
	free(table->pid);
	exit(EXIT_FAILURE);
}

static inline void	philo_routine_init(t_table *table, t_philo *philo)
{
	table->sem_seats = sem_open(SEM_SEATS, O_CREAT, 0660, table->guests / 2);
	table->sem_forks = sem_open(SEM_FORKS, O_CREAT, 0660, table->guests);
	table->sem_sated = sem_open(SEM_SATED, O_CREAT, 0660, 1);
	table->sem_exit = sem_open(SEM_EXIT, O_CREAT, 0660, 0);
	philo_sem_name(philo->sem_name, philo->id);
	sem_unlink(philo->sem_name);
	philo->sem_philo = sem_open(philo->sem_name, O_CREAT, 0660, 1);
	philo->last_meal = philo_get_time();
	if (!table->sem_seats || !table->sem_forks || !table->sem_sated
		|| !table->sem_exit || !philo->sem_philo)
		return (exit_process_error(table, ERR_SEM_OPEN));
}

static inline void	philo_eat(t_table *table, t_philo *philo)
{
	int64_t		starving_time;

	sem_wait(philo->sem_philo);
	starving_time = philo_get_time() - philo->last_meal;
	if (starving_time >= table->time_to_die)
		dying_philo(table, philo);
	philo_print_status(philo, EATING);
	philo->last_meal = philo_get_time();
	sem_post(philo->sem_philo);
	philo_usleep(table->time_to_eat);
	sem_wait(philo->sem_philo);
	if (table->meals > 0)
		philo->meals++;
	sem_post(philo->sem_philo);
	sem_post(table->sem_forks);
	sem_post(table->sem_forks);
	sem_post(table->sem_seats);
	if (philo->meals == table->meals)
		exit(EXIT_SUCCESS);
}

void	philo_routine_bonus(t_table *table, t_philo *philo)
{
	pthread_t	exit;
	pthread_t	death;

	exit = 0;
	death = 0;
	philo_routine_init(table, philo);
	if (pthread_create(&exit, NULL, &reaper_routine_bonus, table)
		|| pthread_create(&death, NULL, &death_routine_bonus, philo))
		exit_process_error(table, ERR_PTHREAD);
	pthread_detach(exit);
	pthread_detach(death);
	while (1)
	{
		philo_print_status(philo, THINKING);
		sem_wait(table->sem_seats);
		sem_wait(table->sem_forks);
		philo_print_status(philo, FORK_TAKEN);
		sem_wait(table->sem_forks);
		philo_print_status(philo, FORK_TAKEN);
		philo_eat(table, philo);
		philo_print_status(philo, SLEEPING);
		philo_usleep(table->time_to_sleep);
	}
}
