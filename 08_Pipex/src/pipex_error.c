/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:00:18 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/10 12:18:16 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_pipex(char **dir, char *str)
{
	free_array(dir);
	perror(str);
	exit(EXIT_FAILURE);
}

void	error_prog(t_prog *prog, char *path, char **argv, char *str)
{
	if (prog->fd_in && prog->fd_in[0] != 0)
		close(prog->fd_in[0]);
	if (prog->fd_out && prog->fd_out[1] != 1)
		close(prog->fd_out[1]);
	if (prog->dir)
		free_array(prog->dir);
	if (path)
		free(path);
	if (argv)
		free_array(argv);
	if (!str)
	{
		write(2, "command not found: ", 20);
		write(2, prog->cmd, ft_strchr(prog->cmd, ' ') - prog->cmd);
		write(2, "\n", 1);
	}
	else
		perror(str);
	exit(EXIT_FAILURE);
}
