/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:45:02 by tderwedu          #+#    #+#             */
/*   Updated: 2021/09/24 17:04:32 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_msh	t_msh;

# include "lexer.h"
# include "parser.h"
# include "word_expansion.h"
# include "launcher.h"

typedef struct s_msh
{
	char	**env;
	char	*line;
	t_tok	*tokens;
	t_cst	*root;
	char	*ret;
}				t_msh;

#endif