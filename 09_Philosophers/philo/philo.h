/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:55:10 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/08 10:04:10 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# pragma GCC diagnostic push 
# pragma GCC diagnostic ignored "-Wcpp"
# define _BSD_SOURCE
# include <unistd.h>
# pragma GCC diagnostic pop

# include <pthread.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>

enum e_status
{
	FORK_TAKEN,
	EATING,
	SLEEPING,
	THINKING,
	DIED
};

typedef unsigned char	t_uc;
typedef unsigned int	t_ui;
struct	s_philo;

typedef struct s_table
{
	int					nbr_philos;
	int64_t				time_to_die;
	int64_t				time_to_eat;
	int64_t				time_to_sleep;
	int					meals;
	int					death;
	int					*ph_meals;
	pthread_t			*tid;
	uint64_t			start_time;
	pthread_mutex_t		m_table;
	pthread_mutex_t		*m_forks;
	struct s_philo		*philos;
}						t_table;

typedef struct s_philo
{
	int					id;
	int					meals;
	uint64_t			last_meal;
	pthread_mutex_t		m_philo;
	pthread_mutex_t		*m_fork_1;
	pthread_mutex_t		*m_fork_2;
	t_table				*table;
}						t_philo;

/*
** philo_init.c
*/

int			philo_get_val(t_uc *nbr);
int			philo_get_args(int argc, char **argv, t_table *table);
int			philo_init_philo(t_table *table);
int			philo_init_mutex(t_table *table);
int			philo_init(int argc, char **argv, t_table *table);

/*
** philo_exit.c
*/

int			philo_clear_all(t_table *table);
int			philo_poor_lonely_philo(t_table *table);
int			philo_exit_error(t_table *table, char *str);

/*
** philo_chekcs.c
*/

int			check_death(t_table *table);
int			check_meals(t_philo *philo);

/*
** philo_utils.c
*/

void		philo_print_status(t_philo *philo, int status);
void		philo_sleep(t_philo *philo, uint64_t msec);
uint64_t	get_time(void);

/*
** philo.c
*/

void		*philo_routine(void *args);
void		*waiter_routine(void *args);
int 		start_threads(t_table *table);
int			main(int argc, char **argv);

#endif
