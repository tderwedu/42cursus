/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_routine_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:50:32 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/12 18:54:14 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*dead_routine_bonus(void *args)
{
	t_philo		*philo;
	t_table		*table;

	philo = (t_philo *)args;
	table = philo->table;
	sem_wait(table->sem_dead);
	sem_post(table->sem_dead);
	exit(EXIT_SUCCESS);
	return (NULL);
}
