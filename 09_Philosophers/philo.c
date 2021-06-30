/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:55:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/30 12:00:57 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	exit_error(char *str)
{
	printf("%s\n", str);
	return (1);
}

int	ft_atoi(t_uc *nbr)
{
	t_ui	val;

	if (*nbr == '\0')
		return (-1);
	val = 0;
	while ((*nbr == ' ' || *nbr - 9U < 4U))
		nbr++;
	nbr += (*nbr == '+');
	if (!((*nbr - 48U) < 10U))
		return (-1);
	while ((*nbr - 48U) < 10U)
		val = val * 10 + (*nbr++ - '0');
	if (*nbr != '\0')
		return (-1);
	return (val);
}

typedef struct s_philo
{
	int		number_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_eats;
}			t_philo;

int	main(int argc, char **argv)
{
	// if (argc < 5 || argc > 6)
	// 	return(exit_error("Wrong number of argument"));
	(void)argc;
	(void)argv;
	struct timeval tv_1;
	struct timeval tv_2;
	gettimeofday(&tv_1, NULL);
	sleep(2);
	gettimeofday(&tv_2, NULL);
	printf("sec: %li\n", tv_2.tv_sec - tv_1.tv_sec);
	printf("usec: %li\n", tv_2.tv_usec - tv_1.tv_usec);
}
