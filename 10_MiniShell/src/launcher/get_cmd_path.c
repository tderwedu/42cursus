/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 11:46:05 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/07 11:48:29 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static inline int	search_dir(char *dir, char *file)
{
	int			found;
	DIR			*dirp;
	t_dirent	*info;

	found = 0;
	info = NULL;
	dirp = opendir(dir);
	if (!dirp)
		return (0);
	errno = 0;
	info = readdir(dirp);
	if (errno)
		return (0);
	while (info && !found)
	{
		if (ft_strcmp(file, info->d_name) == 0)
			found = 1;
		info = readdir(dirp);
	}
	closedir(dirp);
	return (found);
}

static inline char	*try_path_join(t_exec *exec, char *dir, char *cmd)
{
	char	*file;

	file = path_join(dir, cmd);
	if (!file)
	{
		msh_print_error(MSG_MSH, ERR_MALLOC, NULL, EXIT_FAILURE);
		error_exec(exec);
	}
	return (file);
}

char	*get_cmd_path(t_exec *exec, char *cmd)
{
	char	*dir_s;
	char	*dir_e;
	char	*file;

	file = NULL;
	dir_s = msh_getenv(exec->msh->env, "PATH", 4);
	if (!dir_s || !cmd || !*cmd)
		return (NULL);
	dir_e = dir_s;
	while (*dir_e && !file)
	{
		dir_s += (*dir_s == ':');
		if (*dir_e == ':' && dir_s < dir_e)
		{
			*dir_e = '\0';
			if (search_dir(dir_s, cmd))
				file = try_path_join(exec, dir_s, cmd);
			*dir_e = ':';
			dir_s = dir_e + 1;
		}
		dir_e++;
	}
	if (!file && search_dir(dir_s, cmd))
		file = try_path_join(exec, dir_s, cmd);
	return (file);
}
