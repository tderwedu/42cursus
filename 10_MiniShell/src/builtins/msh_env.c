/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:41:18 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/06 12:15:20 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_env(t_exec *exec)
{
	char	**env;

	env = exec->env;
	if (exec->tab[1]) //TODO: test on MAc (no msg on WSL)
	{
		write(2, "env: illegal option or argument\n", 32);
		return (EXIT_FAILURE);
	}
	while (*env)
	{
		write(1, *env, ft_strlen(*env));
		write(1, "\n", 1);
		env++;
	}
	return (EXIT_SUCCESS);
}
