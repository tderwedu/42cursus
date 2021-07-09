/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:55:10 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/09 17:54:44 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <signal.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>


# define SEM_FORKS	"/sem_forks"
# define SEM_DEAD	"/sem_dead"
# define SEM_SEATS	"/sem_seats"
# define SEM_PHILO	"/sem_philo_"

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
	pid_t				*pid;
	int64_t				time_to_die;
	int64_t				time_to_eat;
	int64_t				time_to_sleep;
	uint64_t			time_t0;
	sem_t				*sen_seats;
	sem_t				*sem_forks;
	sem_t				*sem_dead;
	struct s_philo		*philo;
}						t_table;

typedef struct s_philo
{
	int					id;
	int					meals;
	uint64_t			last_meal;
	sem_t				*sem_philo;
	t_table				*table;
}						t_philo;

/*
** philo_init_bonus.c
*/

int			set_the_table(int argc, char **argv, t_table *table, t_philo *philo);

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

void		*philo_routine(void *args);
void		*waiter_routine(void *args);
int			start_threads(t_table *table);
int			main(int argc, char **argv);

#endif
