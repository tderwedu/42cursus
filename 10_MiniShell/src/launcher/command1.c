/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:57:07 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/06 17:58:06 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	cmd_get(t_msh *msh, t_ast *ast, t_exec *exec)
{
	t_cmd	cmd;

	exec->size = cmd_word_count(ast);
	exec->tab = malloc(sizeof(char**) * (exec->size + 1));
	if (!exec->tab)
		return ;
	exec->tab[exec->size] = NULL;
	exec->io = NULL;
	cmd.msh = msh;
	cmd.exec = exec;
	cmd.tail = NULL;
	cmd.i = 0;
	if (ast)
		cmd_ast_traversal(msh, &cmd, ast);
}

void	cmd_ast_traversal(t_msh *msh, t_cmd *cmd, t_ast *ast)
{
	if (ast->type == AST_WORD)
	{
		cmd->exec->tab[cmd->i++] = ast->lex;
		ast->lex = NULL;
	}
	else if (ast->type == AST_IO_REDIR)
		cmd_add_io(msh, cmd, ast);
	if (ast->left)
		cmd_ast_traversal(msh, cmd, ast->left);
	if (ast->right)
		cmd_ast_traversal(msh, cmd, ast->right);
}

static inline void	cmd_add_io_fd(t_msh *msh, t_ast *io_redir, t_io *new)
{
	if (io_redir->left && io_redir->left->type == AST_IO_NBR)
		new->fd = ft_atoi(io_redir->left->lex);
	else if (io_redir->lex[0] == '>')
		new->fd = 1;
	else
		new->fd = 0;
	// TODO: HEREDOC
	if (io_redir->lex[0] == '>' && io_redir->lex[1] == '>')
	{
		new->fd_h = heredoc(msh, io_redir);
	}
	else
		new->fd_h = -1;
}

static inline void	cmd_add_io_flag(t_ast *io_redir, t_io *new)
{
	if (io_redir->lex[0] == '<' && io_redir->lex[1] == '\0')
		new->oflag = (O_RDONLY);
	else if (io_redir->lex[0] == '>' && io_redir->lex[1] == '\0')
		new->oflag = (O_WRONLY | O_CREAT | O_TRUNC);
	else if (io_redir->lex[0] == '>' && io_redir->lex[1] == '>')
		new->oflag = (O_WRONLY | O_CREAT | O_APPEND);
	else
		new->oflag = -1;
}

void	cmd_add_io(t_msh *msh, t_cmd *cmd, t_ast *io_redir)
{
	t_io	*new;

	new = malloc(sizeof(*new));
	if (!new)
		cmd_error(cmd, ERR_MALLOC);
	new->filename = io_redir->right->lex;
	io_redir->right->lex = NULL;
	cmd_add_io_fd(msh, io_redir, new);
	cmd_add_io_flag(io_redir, new);
	new->next = NULL;
	if (!cmd->tail)
		cmd->exec->io = new;
	else
		cmd->tail->next = new;
	cmd->tail = new;
}
