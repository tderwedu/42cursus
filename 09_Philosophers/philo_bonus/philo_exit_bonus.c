/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:13:13 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/25 14:41:50 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_clear_all(t_table *table, t_philo *philo)
{
	int	i;

	i = 0;
	while (table->pid && i < table->guests && table->pid[i])
	{
		kill(table->pid[i++], SIGKILL);
		philo_sem_name(philo->sem_name, philo->id);
		sem_unlink(philo->sem_name);
	}
	if (table->pid)
		free(table->pid);
	if (table->sem_seats)
		sem_close(table->sem_seats);
	if (table->sem_forks)
		sem_close(table->sem_forks);
	if (table->sem_sated)
		sem_close(table->sem_sated);
	if (table->sem_exit)
		sem_close(table->sem_exit);
	sem_unlink(SEM_SEATS);
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_SATED);
	sem_unlink(SEM_EXIT);
}

int	poor_lonely_philo(t_table *table)
{
	table->time_t0 = philo_get_time();
	printf("%8llu 1 is thinking\n", philo_get_time() - table->time_t0);
	printf("%8llu 1 has taken a fork\n", philo_get_time() - table->time_t0);
	usleep(1000 * table->time_to_die);
	printf("%8llu 1 died\n", philo_get_time() - table->time_t0);
	philo_clear_all(table, table->philo);
	return (EXIT_SUCCESS);
}

int	philo_free_error(t_table *table, char *str)
{
	printf("Error:\n");
	printf("%s\n", str);
	philo_clear_all(table, table->philo);
	return (EXIT_FAILURE);
}

int	philo_exit_error(char *str)
{
	printf("Error:\n");
	printf("%s\n", str);
	return (EXIT_FAILURE);
}
