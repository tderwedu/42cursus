/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:55:10 by tderwedu          #+#    #+#             */
/*   Updated: 2021/07/15 10:55:16 by tderwedu         ###   ########.fr       */
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

# define ERR_NBR_ARG	"Wrong number of argument."
# define ERR_BAD_ARG	"Bad argument."
# define ERR_MALLOC		"Malloc error."
# define ERR_SEM_OPEN	"sem_open error."
# define ERR_FORK		"Fork error."
# define ERR_PTHREAD	"pthread_create error."

# define SEM_SEATS	"/sem_seats"
# define SEM_FORKS	"/sem_forks"
# define SEM_EXIT	"/sem_exit"
# define SEM_SATED	"/sem_sated"
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
	int					sated;
	pid_t				*pid;
	int64_t				time_to_die;
	int64_t				time_to_eat;
	int64_t				time_to_sleep;
	uint64_t			time_t0;
	sem_t				*sem_seats;
	sem_t				*sem_forks;
	sem_t				*sem_sated;
	sem_t				*sem_exit;
	struct s_philo		*philo;
}						t_table;

typedef struct s_philo
{
	int					id;
	int					meals;
	uint64_t			last_meal;
	char				sem_name[15];
	sem_t				*sem_philo;
	t_table				*table;
}						t_philo;

/*
** philo_init_bonus.c
*/

int			set_table(int argc, char **argv, t_table *table, t_philo *philo);

/*
** philo_exit.c
*/

void		philo_clear_all(t_table *table, t_philo *philo);
int			poor_lonely_philo(t_table *table);
int			philo_exit_error(t_table *table, char *str);

/*
** philo_utils.c
*/

void		philo_sem_name(char *name, int id);
void		philo_print_status(t_philo *philo, int status);
void		philo_usleep(uint64_t msec);
uint64_t	philo_get_time(void);

/*
** philo.c
*/

void		exit_process_error(t_table *table, char *str);
int			main(int argc, char **argv);

/*
** routine_*_bonus.c
*/

void		philo_routine_bonus(t_table *table, t_philo *philo);
void		*reaper_routine_bonus(void *args);
void		dying_philo(t_table *table, t_philo *philo);
void		*death_routine_bonus(void *args);

#endif
