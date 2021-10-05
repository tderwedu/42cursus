/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:13:56 by namenega          #+#    #+#             */
/*   Updated: 2021/10/05 14:23:20 by namenega         ###   ########.fr       */
=======
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:13:56 by namenega          #+#    #+#             */
/*   Updated: 2021/10/01 13:51:56 by tderwedu         ###   ########.fr       */
>>>>>>> 7fba0d37e81594fe3547fdcd7d0ff558dac266a7
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

<<<<<<< HEAD
//! CHECK RETURN/EXIT VALUES

static int	normal_echo(char **tab, int i)
{
	while (tab[i])
	{
		ft_putstr_fd(tab[i], 1);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
	return (i);
}

static int	echo_multiple_n(int i, char **tab)
{
	if (!tab[i])
		return (0);
	while (tab[i])
	{
		ft_putstr_fd(tab[i], 1);
		if (tab[i + 1])
			write(1, " ", 1);
=======
static void	normal_echo(char **tab, int i, t_exec *exec)
{
	while (tab[i])
	{
		ft_putstr_fd(tab[i], exec->io->fd);
		write(exec->io->fd, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

static int	echo_multiple_n(t_exec *exec, int i, char **tab)
{
	if (!tab[i + 1])
		return (0);
	i++;
	while (tab[i])
	{
		ft_putstr(tab[i], exec->io->fd);
		write(exec->io->fd, " ", 1);
>>>>>>> 7fba0d37e81594fe3547fdcd7d0ff558dac266a7
		i++;
	}
	return (i);
}

static int	parse_n(char *s)
{
<<<<<<< HEAD
	int	i;
=======
	int i;
>>>>>>> 7fba0d37e81594fe3547fdcd7d0ff558dac266a7

	if (!s)
		return (0);
	i = ft_strlen(s);
	if (i == 2)
		return (1);
<<<<<<< HEAD
	else if (s[2] && s[2] == 'n')
=======
	else if (s[2] && s[2] == 'n')								//* echo -nnnn
>>>>>>> 7fba0d37e81594fe3547fdcd7d0ff558dac266a7
	{
		i = 2;
		while (s[i] && s[i] == 'n')
			i++;
<<<<<<< HEAD
		if (s[i + 1] && s[i + 1] != 'n')
=======
		if (s[i + 1] && s[i + 1] != 'n')						//* echo -nnnnpl
>>>>>>> 7fba0d37e81594fe3547fdcd7d0ff558dac266a7
			return (0);
		else
			return (1);
	}
	else
		return (0);
}

<<<<<<< HEAD
static int	if_echo_n(char **tab, int i)
=======

static int	if_echo_n(char **tab, int i, t_exec *exec)
>>>>>>> 7fba0d37e81594fe3547fdcd7d0ff558dac266a7
{
	int		j;

	j = 0;
	while (tab[i] && !ft_strncmp(tab[i], "-n", 2))
	{
		j = parse_n(tab[i]);
		if (j == 0)
			break ;
		i++;
	}
<<<<<<< HEAD
	if (j == 1)
		i = echo_multiple_n(i, tab);
	else
	{
		ft_putstr_fd(tab[i], 1);
		if (tab[i + 1])
			write(1, " ", 1);
=======
	if (j == 1)													//* echo -n -n -n || echo -nnnn
		i += echo_multiple_n(exec, i, tab);
	else														//* echo -nfadsfas
	{															//!WRONG
		ft_putstr_fd(tab[i], exec->io->fd);
		write(exec->io->fd, " ", 1);
>>>>>>> 7fba0d37e81594fe3547fdcd7d0ff558dac266a7
		i++;
	}
	return (i);
}

<<<<<<< HEAD
int	msh_echo(t_msh *msh, t_exec *exec) //TODO: add return
=======
void	msh_echo(t_exec *exec)
>>>>>>> 7fba0d37e81594fe3547fdcd7d0ff558dac266a7
{
	char	**tab;
	int		i;

<<<<<<< HEAD
	(void)msh;
	i = 1;
	if (!exec->tab)
		return (EXIT_FAILURE);
=======
	i = 1;
	if (!exec->tab)
		return ;												//* Error msg need a change
>>>>>>> 7fba0d37e81594fe3547fdcd7d0ff558dac266a7
	tab = exec->tab;
	if (!tab[i])
	{
		write(1, "\n", 1);
<<<<<<< HEAD
		return (EXIT_FAILURE);
	}
	while (tab[i])
	{
		if (i == 1 && tab[i] && !ft_strncmp(tab[i], "-n", 2))
			i = if_echo_n(tab, i);
		else if (tab[i])
			i = normal_echo(tab, i);
	}
	return (EXIT_SUCCESS);
=======
		return ;
	}
	while (tab[i])
	{
		if (i == 1 && tab[i] && !ft_strncmp(tab[i], "-n", 2))	//* echo -n
			i += ft_echo_n(tab, i, exec);
		else if (tab[i])										//* echo
			normal_echo(tab, i, exec);
	}
>>>>>>> 7fba0d37e81594fe3547fdcd7d0ff558dac266a7
}
