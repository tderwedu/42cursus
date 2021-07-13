/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_dead_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:50:32 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/13 12:04:09 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*dead_routine_bonus(void *args)
{
	t_table		*table;

	table = (t_table *)args;
	sem_wait(table->sem_exit);
	sem_post(table->sem_exit);
	sem_post(table->sem_exit);
	sem_post(table->sem_exit);
	exit(EXIT_SUCCESS);
	return (NULL);
}
