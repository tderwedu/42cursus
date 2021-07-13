/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sated_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:30:17 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/13 10:04:03 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*sated_routine_bonus(void *args)
{
	t_table		*table;

	table = (t_table *)args;
	sem_wait(table->sem_sated);
	while (table->sated != table->guests)
		philo_usleep(table->time_to_eat);
	sem_post(table->sem_sated);
	exit(EXIT_SUCCESS);
	return (NULL);
}
