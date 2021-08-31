/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:29:08 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/31 17:35:39 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "libft.h"

# define PIPE 10
# define GREAT 11
# define LESS 12
# define DGREAT 13
# define DLESS 14
# define WORD 15
# define IO_NUMBER 16

typedef struct	s_tok t_tok;

enum	e_separators
{
	CHR_PIPE = '|',
	CHR_QOUTE = '\'',
	CHR_DQUOTE = '\"',
	CHR_ESCAPE = '\\',
	CHR_TAB = '\t',
	CHR_GREAT = '>',
	CHR_LESS = '<',
	CHR_NULL = 0,
	CHR_OTHER = -1,
};

struct	s_tok
{
	char	*lexeme;
	int		type;
	t_tok	*next;
};


#endif
