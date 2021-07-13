/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:12:51 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/13 16:49:31 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

static int	lay_the_table(t_table *table, t_philo *philo)
{
	philo->id = 0;
	philo->meals = 0;
	table->sated = 0;
	sem_unlink(SEM_SEATS);
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_SATED);
	sem_unlink(SEM_EXIT);
	table->pid = malloc(sizeof(pid_t) * table->guests);
	if (!table->pid)
		return (philo_exit_error(table, ERR_MALLOC));
	memset(table->pid, 0, sizeof(pid_t) * table->guests);
	table->sem_seats = sem_open(SEM_SEATS, O_CREAT, 0660, table->guests / 2);
	table->sem_forks = sem_open(SEM_FORKS, O_CREAT, 0660, table->guests);
	table->sem_sated = sem_open(SEM_SATED, O_CREAT, 0660, 1);
	table->sem_exit = sem_open(SEM_EXIT, O_CREAT, 0660, 0);
	if (!table->sem_seats || !table->sem_forks || !table->sem_sated
		|| !table->sem_exit)
		return (philo_exit_error(table, ERR_SEM_OPEN));
	return (0);
}

int	set_table(int argc, char **argv, t_table *table, t_philo *philo)
{
	table->guests = get_arg((t_uc *)argv[1]);
	table->time_to_die = get_arg((t_uc *)argv[2]);
	table->time_to_eat = get_arg((t_uc *)argv[3]);
	table->time_to_sleep = get_arg((t_uc *)argv[4]);
	if (table->guests < 1 || table->time_to_die == -1
		|| table->time_to_eat == -1 || table->time_to_sleep == -1)
		return (philo_exit_error(table, ERR_BAD_ARG));
	if (argc == 6)
	{
		table->meals = get_arg((t_uc *)argv[5]);
		if (table->meals == -1)
			return (philo_exit_error(table, ERR_BAD_ARG));
	}
	else
		table->meals = -1;
	if (lay_the_table(table, philo))
		return (1);
	return (0);
}
