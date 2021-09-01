/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:03:32 by tderwedu          #+#    #+#             */
/*   Updated: 2021/09/01 10:46:44 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	cst_print_tree(t_cst *tree)
{
	if (!tree)
		return ;
	char **type = {"CST_PIPE_SEQ", "CST_CMD_LIST", "CST_IO_REDIR",	"CST_IO_NBR",
					"CST_IO_FILE", "CST_IO_HERE", "CST_WORD"};
	printf("  type: %s", type[tree->type]);
	if (tree->lexeme)
		printf("lexeme: %s", tree->lexeme);
	else
		printf("lexeme: -");
	printf("LEFT BRANCH");
	cst_print_tree(tree->left);
	printf("RIGHT BRANCH");
	cst_print_tree(tree->right);
}

void	cst_delete_tree(t_cst *tree)
{
	if (!tree)
		return ;
	if (tree->lexeme)
		free(tree->lexeme);
	cst_delete_tree(tree->left);
	cst_delete_tree(tree->right);
	free(tree);
}

t_cst*	parse_new_node(t_parser *vars, int type, t_tok *node)
{
	t_cst	*new;

	new = malloc(sizeof(*new));
	if (!new)
		error_parser(vars);
	new->type = type;
	if (node)
	{
		new->lexeme = node->lexeme;
		node->lexeme = NULL;
	}
	else
		new->lexeme = NULL;
	new->left = NULL;
	new->right = NULL;
	return new;
}

t_cst*	parse_io_file(t_parser *vars)
{
	t_cst	*io_file;
	t_cst	*filename;

	if (vars->tmp->type != CST_IO_REDIR)
		error_parser(vars);
	if (!vars->node)
		return NULL;
	if ((vars->node->type - GREAT) <= DGREAT)
	{
		io_file = parse_new_node(vars, CST_IO_FILE, vars->node);
		if (!vars->node || vars->node->type != WORD)
		{
			cst_delete_tree(io_file);
			return NULL;
		}
		vars->tmp->right = io_file;
		filename = parse_new_node(vars, CST_WORD, vars->node);
		io_file->left = filename;
	}
	return io_file;
}

t_cst*	parse_io_here(t_parser *vars)
{
	t_cst	*io_here;
	t_cst	*filename;

	if (vars->tmp->type != CST_IO_REDIR)
		error_parser(vars);
	if (!vars->node)
		return NULL;
	if (vars->node->type == DLESS)
	{
		io_here = parse_new_node(vars, CST_IO_HERE, vars->node);
		if (!vars->node || vars->node->type != WORD)
		{
			cst_delete_tree(io_here);
			return NULL;
		}
		vars->tmp->right = io_here;
		filename = parse_new_node(vars, CST_WORD, vars->node);
		io_here->left = filename;
	}
	return io_here;
}

t_cst*	parse_io_redir(t_parser *vars)
{
	t_tok	*token;
	t_cst	*io_redir;

	token = vars->node;
	if (!vars->node)
		return NULL;
	io_redir = parse_new_node(vars, CST_IO_REDIR, NULL);
	vars->tmp = io_redir;
	if (vars->node->type == IO_NUMBER)
		io_redir->left = parse_new_node(vars, CST_IO_NBR, vars->node);
	if ((token->type - GREAT) <= DLESS)
		io_redir->right = parse_io_file(vars);
	else if (token->type == DLESS)
		io_redir->right = parse_io_here(vars);
	vars->tmp = NULL;
	if (!io_redir->right)
	{
		cst_delete_tree(io_redir);
		vars->node = token;
		return NULL;
	}
	return io_redir;
}

t_cst*	parse_cmd_list(t_parser *vars)
{
	t_cst	*cmd_list;
	t_cst	*node;

	if (!vars->node)
		return NULL;
	if (vars->node->type == WORD)
		node = parse_new_node(vars, CST_WORD, vars->node);
	else
		node = parse_io_redir(vars);
	if (node)
	{
		cmd_list = parse_new_node(vars, CST_CMD_LIST, NULL);
		cmd_list->left = node;
		vars->node = vars->node->next;
		cmd_list->right = parse_cmd_list(vars);
	}
	return cmd_list;
}

t_cst*	parse_pipe_seq(t_parser *vars)
{
	t_cst	*pipe_seq;
	t_cst	*cmd_list;

	cmd_list = parse_cmd_list(vars);
	if (!cmd_list || !vars->node)
		return cmd_list;
	if (vars->node->type != PIPE)
	{
		cst_delete_tree(cmd_list);
		return NULL;
	}
	vars->tmp = cmd_list;
	pipe_seq = parse_new_node(vars, CST_PIPE_SEQ, NULL);
	vars->tmp = NULL;
	pipe_seq->left = cmd_list;
	pipe_seq->right = parse_cmd_list(vars);
	if (!pipe_seq->right)
	{
		cst_delete_tree(pipe_seq);
		return NULL;
	}
	return pipe_seq;
}

t_cst*	msh_parser(t_tok *tokens)
{
	t_cst		*cst;
	t_parser	vars;

	if (!tokens)
		return NULL;
	vars = (t_parser){tokens, tokens, NULL};
	cst = parse_pipe_seq(&vars);
	if (!cst || vars.node)
    {
		printf("Syntax Error near: %s\n", vars.node->lexeme);
		return NULL;
    }
	return cst;
}
