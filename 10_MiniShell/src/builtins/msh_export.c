/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:29:41 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/13 10:05:19 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

int	msh_export_print(t_exec *exec)
{
	char	*value;
	char	**argv;

	argv = exec->msh->env;
	while (*argv)
		argv++;
	argv = grow_tab(exec->msh->env, argv - exec->msh->env);
	sort_env(argv);
	while (*argv)
	{
		value = env_go_2_val(*argv);
		write(1, "declare -x ", 11);
		write(1, *argv, value - (*value != '\0') - *argv);
		if (*value)
		{
			write(1, "=\"", 2);
			write(1, value, ft_strlen(value));
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
		argv++;
	}
	return (EXIT_SUCCESS);
}

int	msh_export_var(t_msh *msh, char *exp)
{
	char	*value;
	char	**param;

	value = env_check_name(exp);
	if (!value || (*value != '=' && *value != '\0'))
		return (print_error(MSG_EXPORT, exp, ERR_IDENTIFIER, EXIT_FAILURE));
	param = get_env_addr(msh->env, exp, value - exp);
	if (param)
		free(*param);
	else
	{
		param = get_env_next_addr(msh);
		if (!param)
			return (EXIT_FAILURE);
	}
	*param = ft_strdup(exp);
	if (!*param)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	msh_export(t_exec *exec)
{
	int	i;
	int	r;
	int	ret;

	i = 1;
	r = 0;
	ret = 0;
	if (!exec->argv[i])
		return (msh_export_print(exec));
	while (exec->argv[i])
	{
		r = msh_export_var(exec->msh, exec->argv[i]);
		if (r)
			ret = r;
		i++;
	}
	return (ret);
}
