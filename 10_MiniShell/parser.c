/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:03:32 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/31 18:39:17 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int msh_parse(t_tok *tokens, t_cst **cst)
{
	
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

t_cst*	cst_new_node(t_parser *vars, int type, t_tok *node)
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
	
}

t_cst*	parse_io_here(t_parser *vars)
{
	t_cst	*node;

	node = NULL;
	if ((vars->node->type - GREAT) <= DGREAT)
	{
	}
}

t_cst*	parse_io_redir(t_parser *vars)
{
	t_tok	*token;
	t_cst	*node;

	token = vars->node;
	node = cst_new_node(vars, CST_IO_REDIR, NULL);
	node->left = NULL;
	node->right = NULL;
	vars->tmp = node;
	if (vars->node->type == IO_NUMBER)
		node->left = cst_new_node(vars, CST_IO_NBR, vars->node);
	if ((token->type - GREAT) <= DLESS)
		node->right = parse_io_file(vars);
	else if (token->type == DLESS)
		node->right = parse_io_here(vars);
	vars->tmp = NULL;
	if (!node->right)
	{
		cst_delete_tree(node);
		vars->node = token;
		return NULL;
	}
	vars->tmp = NULL;
	return node;
}

t_cst*	parse_cmd_list(t_parser *vars)
{
	t_cst	*new;
	t_cst	*ret;

	ret = NULL;
	new = NULL;
	if (vars->node->type == WORD)
		ret = cst_new_node(vars, CST_WORD, vars->node);
	else
		ret = parse_io_redir(vars);
	if (ret)
	{
		new = cst_new_node(vars, CST_CMD_LIST, NULL);
		new->left = ret;
		vars->node = vars->node->next;
		new->right = parse_cmd_list(vars);
	}
	return new;
}
