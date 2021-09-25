/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:29:05 by tderwedu          #+#    #+#             */
/*   Updated: 2021/09/25 13:09:19 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	msh_lexer(t_msh *msh)
{
	char	*line;
	t_lexer	lex;

	line = msh->line;
	if (!line || !*line)
		return (NULL);
	lex = (t_lexer){msh, 0, 0, NULL, NULL, line};
	while (line[lex.i])
	{
		if (line[lex.i] == CHR_BLANK)
			lexer_handle_blank(&lex);
		else if (line[lex.i] == CHR_DQUOTE || line[lex.i] == CHR_QOUTE)
			lexer_handle_quote(&lex);
		else if (line[lex.i] == CHR_LESS || line[lex.i] == CHR_GREAT)
			lexer_handle_io(&lex);
		else if (line[lex.i] == CHR_PIPE)
			lexer_handle_pipe(&lex);
		else
			lex.i++;
	}
	lexer_new_token(&lex, WORD);
	msh->head = lex.head;
}

void	lexer_handle_blank(t_lexer *lex)
{
	lexer_new_token(lex, WORD);
	lex->i++;
	lex->i_p = lex->i;
}

void	lexer_handle_quote(t_lexer *lex)
{
	char	quote;

	quote = lex->line[lex->i];
	lex->i++;
	while (lex->line[lex->i] && lex->line[lex->i] != quote)
		lex->i++;
	if (lex->line[lex->i] != quote)
		lexer_error(lex, ERR_QUOTES_ODD);
	lex->i++;
}

int	lexer_check_io_nbr(t_lexer *lex)
{
	int	i_p;

	i_p = lex->i_p;
	while (i_p < lex->i_p)
	{
		if (lex->line[i_p] < '0' || lex->line[i_p] > '9')
			return (0);
		i_p++;
	}
	return (1);
}

void	lexer_handle_io(t_lexer *lex)
{
	char	type;

	if (lexer_check_io_nbr(lex))
		lexer_new_token(lex, IO_NUMBER);
	else
		lexer_new_token(lex, WORD);
	if (lex->line[lex->i] == CHR_LESS)
		type = LESS;
	else
		type = GREAT;
	if (lex->line[lex->i + 1] == lex->line[lex->i])
	{
		type += 2;
		lex->i++;
	}
	lex->i++;
	lexer_new_token(lex, type);
}
