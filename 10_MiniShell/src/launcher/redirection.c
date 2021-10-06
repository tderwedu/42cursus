/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:42:37 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/06 18:44:37 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "minishell.h"

//	TODO: remove
//	int dup(int oldfd);
//	int dup2(int oldfd, int newfd);

void	undo_redir(t_exec *exec)
{
	t_io	*io;
	int		err_d;

	io = exec->io;
	while (io)
	{
		close(io->fd_h);
		err_d = dup2(io->fd_d, io->fd);
		if (err_d == -1)
			return ;				// TODO: Handle IO Error
		io = io->next;
	}
}

void	redir_io_lst(t_exec *exec)
{
	int		err_d;
	t_io	*io;

	io = exec->io;
	while (io)
	{
		if (io->fd_h <= 0)
		{
			io->fd_h = open(io->filename, io->oflag, 0644);
			if (io->fd_h == -1)
				return ;			// TODO: Handle IO Error
			free(io->filename);
			io->filename = NULL;
		}
		io->fd_d = dup(io->fd);
		if (err_d == -1)
			return ;				// TODO: Handle IO Error
		err_d = dup2(io->fd_h, io->fd);
		if (err_d == -1)
			return ;				// TODO: Handle IO Error
		io = io->next;
	}
}

void	do_redir(t_exec *exec)
{
	int		err_d;

	printf("\e[31m pipe in :[% i|% i]\e[0m\n",exec->pipe_in[0], exec->pipe_in[1]);	// TODO:remove
	printf("\e[31m pipe out:[% i|% i]\e[0m\n",exec->pipe_out[0], exec->pipe_out[1]);	// TODO:remove
	if (exec->pipe_in[0] >= 0)
	{
		printf("\e[34m PIPE IN:[% i|% i]\e[0m\n",exec->pipe_in[0], exec->pipe_in[1]);	// TODO:remove
		close(exec->pipe_in[1]);
		err_d = dup2(exec->pipe_in[0], 0);
		if (err_d == -1)
			return ;				// TODO: Handle IO Error
	}
	if (exec->pipe_out[1] >= 0)
	{
		printf("\e[34m PIPE OUT:[% i|% i]\e[0m\n",exec->pipe_out[0], exec->pipe_out[1]);	// TODO:remove
		close(exec->pipe_out[0]);
		err_d = dup2(exec->pipe_out[1], 1);
		if (err_d == -1)
			return ;				// TODO: Handle IO Error
	}
	redir_io_lst(exec);
}
