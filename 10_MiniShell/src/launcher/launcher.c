/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:23:31 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/07 17:34:25 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	launcher(t_msh *msh)
{
	t_exec	exec;

	if (!msh->ast)
		return ;
	exec.msh = msh;
	exec.cmdpath = NULL;
	no_pipe(exec.pipe_in);
	no_pipe(exec.pipe_out);
	if (msh->ast->type == AST_PIPE)
		launch_pipe_seq(&exec);
	else
		launch_simple_cmd(&exec);
	msh->ast = free_ast(msh->ast);
}

void	error_exec(t_exec *exec, int ret)
{
	free_exec(exec);
	free_msh(exec->msh);
	exit(ret);
}

void	error_exec_errno(t_exec *exec, char *msg)
{
	print_error(msg, strerror(errno), NULL, errno);
	free_exec(exec);
	free_msh(exec->msh);
	exit(errno);
}
