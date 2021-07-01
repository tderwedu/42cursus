/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:55:10 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/01 14:22:04 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define _BSD_SOURCE

#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>

typedef unsigned char	t_uc;
typedef unsigned int	t_ui;

typedef struct s_table
{
	int					nbr_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat_count;
	int					all_alive;
	uint64_t			start_time;
	pthread_mutex_t		m_all_alive;
	pthread_mutex_t		*m_forks;
	t_philo				*philos;
}						t_table;

typedef struct s_philo
{
	int					number;
	int					nbr_of_meals;
	uint64_t			last_meal;
	t_table				*table;
	pthread_mutex_t		m_philo;
	pthread_mutex_t		*m_fork_1;
	pthread_mutex_t		*m_fork_2;
}						t_philo;

/*
** philoinit.c
*/

int			philo_init(int argc, char **argv, t_table *table);

/*
** philo_exit.c
*/

int			philo_clear_all(t_table *table);
int			philo_exit_error(t_table *table, char *str);
int			philo_poor_lonely_philo(t_table *table);

/*
** philo_utils.c
*/

int			philo_get_val(t_uc *nbr);
uint64_t	get_time(void);

#endif
