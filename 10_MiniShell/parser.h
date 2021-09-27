/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:02:27 by tderwedu          #+#    #+#             */
/*   Updated: 2021/09/27 10:37:34 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"
# include "lexer.h"

// TODO: all ERR in ine header
# define ERR_SYNTAX	"Syntax Error near: %s\n"

enum	e_cst
{
	CST_PIPE_SEQ,
	CST_CMD_LIST,
	CST_IO_REDIR,
	CST_IO_NBR,
	CST_IO_FILE,
	CST_IO_HERE,
	CST_WORD
};

typedef struct s_cst	t_cst;

struct s_cst
{
	int		type;
	char	*lex;
	t_cst	*left;
	t_cst	*right;
};

typedef struct s_parser
{
	t_msh	*msh;
	t_tok	*head;
	t_tok	*node;
	t_cst	*tmp;
}			t_parser;

/*
** FILE: parser1.c
*/

void	parser(t_msh *msh);
t_cst	*parser_new_node(t_parser *vars, int type, t_tok *node);

/*
** FILE: parser1.c
*/

t_cst	*parser_pipe_seq(t_parser *vars);
t_cst	*parser_cmd_list(t_parser *vars);
t_cst	*parser_io_redir(t_parser *vars);
t_cst	*parser_io_file(t_parser *vars);
t_cst	*parser_io_here(t_parser *vars);

/*
** FILE: parser1.c
*/

void	parser_free(t_cst *tree);
void	parser_error(t_parser *vars, char *msg, char *opt);
void	parser_print(t_cst *tree);

#endif
