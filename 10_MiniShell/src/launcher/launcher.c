/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:23:31 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/07 11:44:22 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	msh_no_pipe(int	pipe[2])
{
	pipe[0] = -1;
	pipe[1] = -1;
}

static void	msh_close_pipe(int pipe[2])
{
	if (pipe[0] < 0)
		return ;
	printf("\e[32m Close pipe :[% i|% i]\e[0m\n", pipe[0], pipe[1]);
	close(pipe[0]);
	close(pipe[1]);
}

static void	msh_switch_pipe(int pipe_in[2], int pipe_out[2])
{
	pipe_in[0] = pipe_out[0];
	pipe_in[1] = pipe_out[1];
	pipe_out[0] = -1;
	pipe_out[1] = -1;
}

void	msh_launch_simple(t_exec *exec)
{
	int		ret;
	pid_t	pid;

	cmd_get(exec->msh, exec->msh->ast, exec);
	// fct = is_builtin(exec->argv[0]);
	if (exec->fct)// Execution in the SHELL environment
	{
		do_redir(exec, 1);
		ret = (*exec->fct)(exec);
		undo_redir(exec);
	}
	else // Execution in a SUB Shell environment
	{
		// Get Binary File
		// exec->cmdpath = get_cmd_path(exec, exec->argv[0]);
		if (!exec->cmdpath)
		{
			msh_print_error(MSG_MSH, exec->argv[0], MSG_NOTFOUND, 0);
			ret_itoa(exec->msh, EXIT_FAILURE);
			return ;
		}
		pid = fork();
		if (pid < 0)
			return ;// TODO: Error Handling
		if (pid == 0)
		{
			do_redir(exec, 0);
			exec->msh->env = NULL;
			free_msh(exec->msh);
			execve(exec->cmdpath, exec->argv, exec->msh->env);
			// TODO: Error Handling
		}
		waitpid(pid, &ret, 0);
		ret = WEXITSTATUS(ret);
	}
	ret_itoa(exec->msh, ret);
	free_exec(exec);
}

void	error_exec(t_exec *exec)
{
	free_exec(exec);
	free_msh(exec->msh);
	exit(EXIT_FAILURE);
}

int	launcher_subshell_cmd(t_exec *exec)
{
	do_redir(exec, 0);
	exec->msh->env = NULL;
	free_msh(exec->msh);
	if (exec->fct)
		return ((*exec->fct)(exec));
	else
	{
		if (!exec->cmdpath)
		{
			msh_print_error(MSG_MSH, exec->argv[0], MSG_NOTFOUND, 0);
			//TODO: Error Handling
			exit(EXIT_FAILURE);
		}
		errno = 0;
		execve(exec->cmdpath, exec->argv, exec->msh->env);
		msh_print_error(MSG_EXECVE, strerror(errno), NULL, EXIT_FAILURE);
		error_exec(exec);
		return (EXIT_FAILURE);
	}
}

void	msh_launch_pipe(t_exec *exec)
{
	int		ret;
	pid_t	pid;
	t_ast	*ast_pipe;

	ast_pipe = exec->msh->ast;
	while (ast_pipe->type == AST_PIPE)
	{
		// Prepare CMD
		cmd_get(exec->msh, ast_pipe->left, exec);
		// PIPE Handling - 1
		if (pipe(exec->pipe_out) == -1)
			return ; // TODO: ERROR HANDLING
		// Launch cmd - START
		pid = fork();
		if (pid < 0)
			return ;	// TODO: Error Handling
		if (pid == 0)
			launcher_subshell_cmd(exec);
		else
		{
			msh_close_pipe(exec->pipe_in);
		}
		// Launch cmd - END
		// PIPE Handling - 2
		msh_switch_pipe(exec->pipe_in, exec->pipe_out);
		ast_pipe = ast_pipe->right;
	}
	// Prepare LAST
	cmd_get(exec->msh, ast_pipe, exec);
	// Launch LAST - START
	pid = fork();
	if (pid < 0)
		return ;	// TODO: Error Handling
	if (pid == 0)
	{
		do_redir(exec, 0);
		exec->msh->env = NULL;
		free_msh(exec->msh);
		if (exec->fct)
			ret = (*exec->fct)(exec);
		else
		{
			if (!exec->cmdpath)
			{
				msh_print_error(MSG_MSH, exec->argv[0], MSG_NOTFOUND, 0);
				ret_itoa(exec->msh, EXIT_FAILURE);
				exit(EXIT_FAILURE) ; //TODO: Error Handling
			}
			execve(exec->cmdpath, exec->argv, exec->msh->env);
			// TODO: Error Handling
		}
	}
	else
	{
		msh_close_pipe(exec->pipe_in);
		waitpid(pid, &ret, 0);
		ret = WEXITSTATUS(ret);
		ret_itoa(exec->msh, ret);
	}
	waitpid(-1, &ret, 0);
	// Launch LAST- END
	msh_close_pipe(exec->pipe_in);
	msh_close_pipe(exec->pipe_out);
	waitpid(exec->pid, &ret, 0); // TODO: TODO
}

void	msh_launch(t_msh *msh)
{
	t_exec	exec;

	exec.msh = msh;
	exec.cmdpath = NULL;
	msh_no_pipe(exec.pipe_in);
	msh_no_pipe(exec.pipe_out);
	if (msh->ast->type == AST_PIPE)
		msh_launch_pipe(&exec);
	else
		msh_launch_simple(&exec);
}
