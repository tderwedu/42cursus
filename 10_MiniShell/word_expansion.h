/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expansion.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:33:45 by tderwedu          #+#    #+#             */
/*   Updated: 2021/09/23 16:16:09 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORD_EXPANSION_H
# define WORD_EXPANSION_H

# include "libft.h"
# include "parser.h"
# include "vector.h"
// # include "msh_error.h"

# define ERR_MALLOC		"Malloc error."

# define TYPE_IO	0
# define TYPE_CMD	1

enum	e_we_st
{
	WE_ST_FREE,
	WE_ST_SQUOTE,
	WE_ST_DQUOTE
};


# define STATE_FREE		0
# define STATE_SQUOTE	1
# define STATE_DQUOTE	2

typedef struct s_we
{
	char	**env;
	t_cst	*root;
	t_cst	*node;
	int		type;
}				t_we;

typedef struct s_pe
{
	char	*lex;
	char	*lex_1;
	char	*lex_2;
	char	*new;
	char	*new_1;
	char	*new_2;
	char	*param;
	int		len_lex;
	int		len_param;
	int		state;
}				t_pe;

void	msh_word_expansion(char **env, t_cst *cst);

#endif
