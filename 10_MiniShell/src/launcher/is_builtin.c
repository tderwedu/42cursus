/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:55:40 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/06 15:02:05 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

// TODO: move to a better place
static inline void	set_lowercase(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		s[i] = (s[i] | 0x20);
}

t_fct	is_builtin(char *name)
{
	int					i;
	static t_builtin	lst[] = {
	{"cd", &msh_cd},
	{"pwd", &msh_pwd},
	{"env", &msh_env},
	{"exit", &msh_exit},
	{"echo", &msh_echo},
	{"unset", &msh_unset},
	{"export", &msh_export}
	};
	static int			max = sizeof(lst) / sizeof(t_builtin);

	set_lowercase(name);
	i = -1;
	while (++i < max)
	{
		if (!ft_strcmp(lst[i].name, name))
			break ;
	}
	if (i < max)
		return (lst[i].fct);
	return (NULL);
}

// int	launch_builtin(t_msh *msh, t_exec *exec)
// {
// 	int	ret;

// 	set_lowercase(exec->tab[0]);
// 	if (!ft_strncmp(exec->tab[0], "echo", 5))
// 		ret = msh_echo(msh, exec);
// 	else if (!ft_strncmp(exec->tab[0], "cd", 3))
// 		ret = msh_cd(msh, exec);
// 	else if (!ft_strncmp(exec->tab[0], "unset", 6))
// 		ret = msh_unset(msh, exec);
// 	else if (!ft_strncmp(exec->tab[0], "env", 4))
// 		ret = msh_env(msh, exec);
// 	else if (!ft_strncmp(exec->tab[0], "pwd", 4))
// 		ret = msh_pwd(msh, exec);
// 	else if (!ft_strncmp(exec->tab[0], "export", 4))
// 		ret = msh_export(exec);
// 	else
// 		ret = -1;
// 	if (ret >= 0)
// 		ret_itoa(msh, ret);
// 	return (ret);
// }
