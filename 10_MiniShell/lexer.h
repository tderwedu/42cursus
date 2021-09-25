/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:29:08 by tderwedu          #+#    #+#             */
/*   Updated: 2021/09/25 13:08:48 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdio.h>
# include "libft.h"
# include "minishell.h"

// TODO: one definition
# define ERR_MALLOC		"Malloc error."
# define ERR_QUOTES_ODD	"msh: error odd number of quotes."

# define PIPE		10
# define GREAT		11
# define LESS		12
# define DGREAT		13
# define DLESS		14
# define WORD		15
# define IO_NUMBER	16

typedef struct s_tok	t_tok;

enum	e_separators
{
	CHR_BLANK = ' ',
	CHR_LESS = '<',
	CHR_DQUOTE = '\"',
	CHR_QOUTE = '\'',
	CHR_GREAT = '>',
	CHR_PIPE = '|'
};

struct s_tok
{
	char	*lex;
	int		type;
	t_tok	*next;
};

typedef struct s_lexer
{
	t_msh	*msh;
	int		i;
	int		i_p;
	t_tok	*head;
	t_tok	*last;
	char	*line;
}				t_lexer;

/*
** FILE: lexer1.c
*/

void	msh_lexer(t_msh *msh);
void	lexer_handle_blank(t_lexer *lex);
void	lexer_handle_quote(t_lexer *lex);
int		lexer_check_io_nbr(t_lexer *lex);
void	lexer_handle_io(t_lexer *lex);

/*
** FILE: lexer2.c
*/

void	lexer_handle_pipe(t_lexer *lex);
void	lexer_new_token(t_lexer *lex, int type);
void	lexer_free(t_lexer *lex);
void	lexer_error(t_lexer *lex, char *msg);
void	lexer_print_tokens(t_tok *token);

#endif
