/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:57:09 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/07 17:22:45 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

extern pid_t	g_pid;

static inline void	launch_subshell_cmd(t_exec *exec, char **env)
{
	g_pid = fork();
	if (g_pid < 0)
		error_exec_errno(exec, MSG_FORK);
	if (g_pid == 0)
	{
		apply_redir(exec, 0);
		if (exec->fct)
			exit((*exec->fct)(exec));
		else
		{
			if (!exec->cmdpath)
			{
				print_error(MSG_MSH, exec->argv[0], MSG_NOTFOUND, 0);
				error_exec(exec, ERRNO_NOT_FOUND);
			}
			exec->msh->env = NULL;
			exec->msh = free_msh(exec->msh);
			exec->io = free_io(exec->io);
			execve(exec->cmdpath, exec->argv, env);
			error_exec_errno(exec, MSG_EXECVE);
		}
	}
	else
		close_pipe(exec->pipe_in);
}

void	launch_pipe_seq(t_exec *exec)
{
	int		ret;
	t_ast	*ast_pipe;

	ast_pipe = exec->msh->ast;
	while (ast_pipe->type == AST_PIPE)
	{
		prep_next_cmd(exec->msh, ast_pipe->left, exec);
		if (pipe(exec->pipe_out) == -1)
			error_exec_errno(exec, MSG_PIPE);
		launch_subshell_cmd(exec, exec->msh->env);
		switch_pipe(exec->pipe_in, exec->pipe_out);
		ast_pipe = ast_pipe->right;
		free_exec(exec);
	}
	prep_next_cmd(exec->msh, ast_pipe, exec);
	launch_subshell_cmd(exec, exec->msh->env);
	free_exec(exec);
	waitpid(g_pid, &ret, 0);
	ret_itoa(exec->msh, WEXITSTATUS(ret));
	waitpid(-1, &ret, 0);
}

void	no_pipe(int	pipe[2])
{
	pipe[0] = -1;
	pipe[1] = -1;
}

void	close_pipe(int pipe[2])
{
	if (pipe[0] < 0)
		return ;
	close(pipe[0]);
	close(pipe[1]);
	pipe[0] = -1;
	pipe[1] = -1;
}

void	switch_pipe(int pipe_in[2], int pipe_out[2])
{
	pipe_in[0] = pipe_out[0];
	pipe_in[1] = pipe_out[1];
	pipe_out[0] = -1;
	pipe_out[1] = -1;
}
