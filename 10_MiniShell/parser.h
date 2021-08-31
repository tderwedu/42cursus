/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:02:27 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/31 17:41:08 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"

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

typedef struct	s_cst t_cst;

struct s_cst
{
	int		type;
	char	*lexeme;
	t_cst	*left;
	t_cst	*right;
};

typedef struct s_parser
{
	t_tok	*first;
	t_tok	*node;
	t_cst	*root;
	t_cst	*tmp;
}			t_parser;

int		msh_parse(t_tok *tokens, t_cst **cst);
void	error_parser(t_parser *vars);

#endif
