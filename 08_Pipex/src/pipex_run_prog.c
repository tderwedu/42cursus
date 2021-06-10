/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_run_prog.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:03:28 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/10 12:16:57 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	pipe_in(t_prog *prog)
{
	int	fd;

	if (!prog->file_in)
	{
		close(prog->fd_in[1]);
		if (prog->fd_in[0] != 0 && dup2(prog->fd_in[0], 0) == -1)
			error_prog(prog, NULL, NULL, "dup2");
	}
	else
	{
		fd = open(prog->file_in, O_RDONLY);
		if (fd == -1)
			error_prog(prog, NULL, NULL, "open");
		if (dup2(fd, 0) == -1)
			error_prog(prog, NULL, NULL, "dup2");
	}
}

void	pipe_out(t_prog *prog)
{
	int	fd;

	if (!prog->file_out)
	{
		close(prog->fd_out[0]);
		if (prog->fd_out[1] != 1 && dup2(prog->fd_out[1], 1) == -1)
			error_prog(prog, NULL, NULL, "dup2");
	}
	else
	{
		fd = open(prog->file_out, O_WRONLY | O_CREAT, 0644);
		if (fd == -1)
			error_prog(prog, NULL, NULL, "open");
		if (dup2(fd, 1) == -1)
			error_prog(prog, NULL, NULL, "dup2");
	}
}

void	run_prog(t_prog *prog)
{
	char	*path;
	char	**argv;

	pipe_in(prog);
	pipe_out(prog);
	argv = ft_split(prog->cmd, ' ');
	if (!argv)
		error_prog(prog, NULL, NULL, NULL);
	path = get_path(prog->dir, argv[0]);
	if (!path)
		error_prog(prog, NULL, argv, NULL);
	execve(path, argv, prog->env);
	error_prog(prog, path, argv, strerror(errno));
}
