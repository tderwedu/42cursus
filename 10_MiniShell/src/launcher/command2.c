/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:57:07 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/07 09:56:49 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	cmd_word_count_sub(t_ast *ast, int *count)
{
	if (ast->type == AST_IO_REDIR)
		return ;
	if (ast->type == AST_WORD && ast->lex)
		(*count)++;
	if (ast->left)
		cmd_word_count_sub(ast->left, count);
	if (ast->right)
		cmd_word_count_sub(ast->right, count);
}

int	cmd_word_count(t_ast *ast)
{
	int	count;

	count = 0;
	cmd_word_count_sub(ast, &count);
	return (count);
}

void	free_exec(t_exec *exec)
{
	t_io	*io;
	t_io	*next;

	if (exec->cmdpath)
		free(exec->cmdpath);
	if (exec->argv)
		free_tab(exec->argv);
	io = exec->io;
	next = exec->io;
	while (io)
	{
		next = io->next;
		free(io->filename);
		free(io);
		io = next;
	}
}

void	cmd_error(t_cmd *cmd, char *msg)
{
	free_exec(cmd->exec);
	msh_error(cmd->msh, msg);
}

void	print_exec(t_exec *exec)
{
	char	**tab;
	t_io	*io;

	if (!exec)
		return ;
	tab = exec->argv;
	io = exec->io;
	printf("\e[33m \t ### NEXT EXEC ###\e[0m\n");
	printf("\e[36m CMD \e[0m %s\n", exec->argv[0]);
	printf("\e[36m PATH\e[0m %s\n", exec->cmdpath);
	printf("\e[36m ARGS\e[0m\n");
	while (*tab)
		printf("\t%s\n", *tab++);
	while (io)
	{
		printf("\e[36m IO\e[0m\n");
		printf("\t\e[35m fd   \e[0m %i\n", io->fd);
		if (io->fd_h >= 0)
			printf("\t\e[35m heredoc\e[0m %i\n", io->fd_h);
		printf("\t\e[35m oflag\e[0m %i\n", io->oflag);
		printf("\t\e[35m file \e[0m %s\n", io->filename);
		io = io->next;
	}
	printf("\e[33m \t ### END ###\e[0m\n");
}
