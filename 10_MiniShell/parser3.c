/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:54:35 by tderwedu          #+#    #+#             */
/*   Updated: 2021/09/27 10:40:38 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parser_free(t_cst *tree)
{
	t_cst	*left;
	t_cst	*right;

	if (!tree)
		return ;
	left = tree->left;
	right = tree->right;
	if (tree->lex)
		free(tree->lex);
	free(tree);
	if (left)
		cst_delete_tree(tree->left);
	if (right)
		cst_delete_tree(tree->right);
}

void	parser_error(t_parser *vars, char *msg, char *opt)
{
	if (vars->tmp)
		parser_free(vars->tmp);
	if (opt)
	{
		printf("Syntax Error near: %s\n", opt);
		lexer_free(vars->head);
		msh_error(vars->msh, NULL);
	}
	lexer_free(vars->head);
	msh_error(vars->msh, msg);
}

static void	parser_print_2(t_cst *tree, char **types, char **tabs, int tab)
{
	if (!tree)
		return ;
	if (tab > 9)
		tab = 9;
	printf("%s\033[36m%s\033[0m ", tabs[tab], types[tree->type]);
	if (tree->lex)
		printf("\033[33m>\033[0m%s\033[33m<\033[0m", tree->lex);
	printf("\n");
	if (tree->left)
	{
		printf("%sLEFT BRANCH\n", tabs[tab]);
		parser_print_2(tree->left, types, tab, tab + 1);
	}
	if (tree->right)
	{
		printf("%sRIGHT BRANCH\n", tabs[tab]);
		parser_print_2(tree->right, types, tab, tab + 1);
	}
}

void	cst_print(t_cst *tree)
{
	char	*types[5];
	char	*tabs[10];

	types[0] = "CST_PIPE_SEQ";
	types[1] = "CST_CMD_LIST";
	types[2] = "CST_IO_REDIR";
	types[3] = "CST_IO_NBR";
	types[4] = "CST_WORD";
	tabs[0] = " ";
	tabs[1] = "\t";
	tabs[2] = "\t\t";
	tabs[3] = "\t\t\t";
	tabs[4] = "\t\t\t\t";
	tabs[5] = "\t\t\t\t\t";
	tabs[6] = "\t\t\t\t\t\t";
	tabs[7] = "\t\t\t\t\t\t\t";
	tabs[8] = "\t\t\t\t\t\t\t\t";
	tabs[9] = "\t\t\t\t\t\t\t\t\t";
	parser_print_2(tree, types, tabs, 0);
}
