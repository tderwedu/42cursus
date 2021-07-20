/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:55:10 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/20 16:52:02 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

# define ERR_NBR_ARG	"Wrong number of argument."
# define ERR_BAD_ARG	"Bad argument."
# define ERR_MALLOC		"Malloc error."
# define ERR_MUTEX		"Mutex error."
# define ERR_PTHREAD	"pthread_create error."

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
struct					s_philo;

typedef struct s_table
{
	int					guests;
	int					meals;
	int					death;
	int					sated;
	int64_t				time_to_die;
	int64_t				time_to_eat;
	int64_t				time_to_sleep;
	uint64_t			time_t0;
	pthread_t			*tid;
	pthread_mutex_t		m_table;
	pthread_mutex_t		*m_forks;
	struct s_philo		*philo;
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

int			set_the_table(int argc, char **argv, t_table *table);

/*
** philo_exit.c
*/

int			philo_clear_all(t_table *table);
int			poor_lonely_philo(t_table *table);
int			philo_exit_error(t_table *table, char *str);

/*
** philo_chekcs.c
*/

int			check_death(t_table *table);
int			check_sated(t_table *table);

/*
** philo_utils.c
*/

void		philo_print_status(t_philo *philo, int status);
void		philo_usleep(t_philo *philo, uint64_t msec);
uint64_t	philo_get_time(void);

/*
** philo.c
*/

int			dinner_time(t_table *table);
int			main(int argc, char **argv);

/*
** routine_*_bonus.c
*/

void		*philo_routine(void *args);
void		*reaper_routine(void *args);

#endif
