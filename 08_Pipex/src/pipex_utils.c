/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:01:01 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/10 12:02:38 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_dir(char **env)
{
	char	**dir;

	while (ft_strncmp("PATH=", *env, 5))
		env++;
	if (!(*env))
		return (NULL);
	dir = ft_split(*env, ':');
	if (!dir)
		return (NULL);
	if (!(*dir))
	{
		free(dir);
		return (NULL);
	}
	return (dir);
}

char	*get_path(char **dir, char *exe)
{
	int		i;
	int		fd;
	char	*path;

	if (!dir || !exe)
		return (NULL);
	i = 0;
	path = ft_path_join(dir[i], exe);
	fd = open(path, O_RDONLY);
	while (fd == -1 && dir[++i])
	{
		free(path);
		path = ft_path_join(dir[i], exe);
		fd = open(path, O_RDONLY);
	}
	if (fd == -1)
	{
		close(fd);
		free(path);
		return (NULL);
	}
	return (path);
}
