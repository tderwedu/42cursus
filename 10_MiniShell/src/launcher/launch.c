/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:23:31 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/06 13:06:19 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <sys/types.h>

#include "exec.h"

static void	msh_no_pipe(int	pipe[2])
{
	pipe[0] = -1;
	pipe[1] = -1;
}

// static void	msh_close_pipe(int pipe[2])
// {
// 	close(pipe[0]);
// 	close(pipe[1]);
// 	msh_no_pipe(pipe);
// }

// static void	msh_switch_pipe(int pipe_in[2], int pipe_out[2])
// {
// 	msh_close_pipe(pipe_in);
// 	pipe_in[0] = pipe_out[0];
// 	pipe_in[1] = pipe_out[1];
// }

/*
**	USE DUP(1) TO SACE A COPY !!!
*/

void	msh_launch_simple(t_exec *exec)
{
	int		ret;
	pid_t	pid;
	t_fct	fct;

	fct = is_builtin(exec->tab[0]);
	if (fct)
	{
		do_redir(exec);
		ret = (*fct)(exec);
		undo_redir(exec);
	}
	else
	{
		// Get Binary File
		exec->cmdpath = get_bin(exec->msh, exec->tab[0]);
		if (!exec->cmdpath)
		{
			msh_print_error(MSG_BASH, exec->tab[0], MSG_NOTFOUND, 0);
			ret_itoa(exec->msh, EXIT_FAILURE);
			return ;
		}
		// Launch Sub Shell environment
		pid = fork();
		if (pid < 0)
			return ;					// TODO: Error Handling
		if (pid == 0)
		{
			do_redir(exec);
			exec->msh->env = NULL;
			msh_free(exec->msh);
			execve(exec->cmdpath, exec->tab, exec->env);
			// TODO: Error Handling
		}
		waitpid(pid, &ret, 0);
		ret = WEXITSTATUS(ret);
	}
	ret_itoa(exec->msh, ret);
}

void	msh_launch_pipe(t_exec *exec)
{
	(void)exec;
	// int		ret;
	// t_ast	*cmd;

	// cmd = msh->ast;
	// msh_no_pipe(exec->pipe_in);
	// while (cmd)
	// {
	// 	cmd_get(&msh, cmd->left, &exec);
	// 	cmd = cmd->right;
	// 	if (pipe(exec->pipe_out) == -1)
	// 		return ; // TODO: ERROR HANDLING
	// 	msh_launch_one(msh, &exec);
	// 	msh_switch_pipe(exec->pipe_in, exec->pipe_out);
	// }
	// msh_close_pipe(exec->pipe_in);
	// waitpid(exec.pid, &ret, 0); // TODO: TODO
}

void	msh_launch(t_msh *msh)
{
	t_exec	exec;

	msh_no_pipe(exec.pipe_in);
	msh_no_pipe(exec.pipe_out);
	if (msh->ast->type == AST_PIPE)
	{
		cmd_get(msh, msh->ast->left, &exec);
		msh_launch_pipe(&exec);
	}
	else
	{
		cmd_get(msh, msh->ast, &exec);
		cmd_print(&exec);
		msh_launch_simple(&exec);
	}
}
