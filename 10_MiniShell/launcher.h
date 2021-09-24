/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:41:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/09/24 17:23:30 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAUNCHER_H
# define LAUNCHER_H

#include "lexer.h"
#include "parser.h"
#include "word_expansion.h"
#include "minishell.h"

# define ERR_MALLOC		"Malloc error." // TODO: One Header for all msg

typedef struct s_io	t_io;

typedef struct s_exec
{
	int		*pipe_in[2];
	int		*pipe_out[2];
	int		argc;
	char	**argv;
	char	**env;
	t_cst	*cmd_root;
}				t_exec;

typedef struct s_io
{
	int		fd;
	char	*filename;
	int		oflag;
	t_io	*next;
}				t_io;

void	launcher(t_msh *msh);

#endif