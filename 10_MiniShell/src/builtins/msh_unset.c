/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 09:46:24 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/06 17:55:31 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

//TODO: exit(), CTRL-D

//TODO: UPDATE env_left

static int	find_env(char *s, char **env, int len)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], s, len)
			&& (env[i][len] == '=' || env[i][len] == '\0'))
			break ;
		i++;
	}
	if (env[i])
	{
		free(env[i]);
		while (env[i + 1])
		{
			env[i] = env[i + 1];
			i++;
		}
		env[i] = NULL;
		return (1);
	}
	return (0);
}

int	msh_unset(t_exec *exec) //TODO: correct return
{
	int	i;
	int	len;

	i = 1;
	len = 0;
	if (!exec->msh->env)
		return (EXIT_FAILURE);				//!Error need a change
	while (exec->tab[i])
	{
		len = ft_strlen(exec->tab[i]);
		if (find_env(exec->tab[i], exec->msh->env, len))
			exec->msh->env_left++;
		i++;
	}
	return (EXIT_SUCCESS);
}
