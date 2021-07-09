/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:55:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/09 17:55:05 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	int		i;
	t_table	table;
	t_philo	philo;

	table.philo = &philo;
	philo.table = &table;
	if (argc < 5 || argc > 6)
		return (philo_exit_error(&table, "Wrong number of argument."));
	if (set_the_table(argc, argv, &table, &philo))
		return (1);
	// if (table.guests == 1)
	// 	return (poor_lonely_philo(&table));
	// else
	// {
	// 	if (start_threads(&table))
	// 		return (1);
	// 	i = -1;
	// 	while (++i < table.guests)
	// 		pthread_join(table.tid[i], NULL);
	// 	philo_clear_all(&table);
	// }
}
