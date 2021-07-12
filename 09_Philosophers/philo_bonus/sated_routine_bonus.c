/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sated_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:30:17 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/12 18:54:00 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*sated_routine_bonus(void *args)
{
	t_philo		*philo;
	t_table		*table;

	philo = (t_philo *)args;
	table = philo->table;
	sem_wait(table->sem_sated);
	sem_post(table->sem_sated);
	exit(EXIT_SUCCESS);
	return (NULL);
}
