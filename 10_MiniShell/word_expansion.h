/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expansion.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:33:45 by tderwedu          #+#    #+#             */
/*   Updated: 2021/09/22 16:34:31 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORD_EXPANSION_H
# define WORD_EXPANSION_H

# include "parser.h"
# include "libft.h"
// # include "msh_error.h"

typedef struct s_we
{
	char	**env;
	t_cst	*root;
	t_cst	*node;
	int		state;
}				t_we;

typedef struct s_pe
{
	char	*lex;
	char	*ptr_1;
	char	*ptr_2;
	char	*param;
	int		len_lex;
	int		len_param;
}				t_pe;

void	msh_word_expansion(char **env, t_cst *cst);

#endif
