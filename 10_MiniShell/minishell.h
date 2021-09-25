/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:45:02 by tderwedu          #+#    #+#             */
/*   Updated: 2021/09/25 12:49:44 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_msh	t_msh;

# include "lexer.h"
# include "parser.h"
# include "word_expansion.h"

typedef struct s_msh
{
	char	**env;
	char	*line;
	t_tok	*head;
	t_cst	*root;
	char	*ret;
}				t_msh;

#endif
