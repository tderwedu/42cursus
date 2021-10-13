/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:55:40 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/13 10:02:57 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

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
	static t_fct_arr	lst[] = {
	{"cd", &msh_cd},
	{"pwd", &msh_pwd},
	{"env", &msh_env},
	{"exit", &msh_exit},
	{"echo", &msh_echo},
	{"unset", &msh_unset},
	{"export", &msh_export}
	};
	static int			max = sizeof(lst) / sizeof(t_fct_arr);

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
