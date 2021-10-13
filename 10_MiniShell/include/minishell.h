/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:45:02 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/13 10:12:08 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include <readline/readline.h>
# include <readline/history.h>

# include <signal.h>
# include <sys/stat.h>
# include <sys/types.h>

# include "parser.h"
# include "launcher.h"
# include "error_messages.h"

typedef struct s_hd		t_hd;
typedef struct s_tok	t_tok;
typedef struct s_ast	t_ast;
typedef struct s_msh	t_msh;

struct s_msh
{
	char	*line;
	t_tok	*tok;
	t_ast	*ast;
	t_hd	*hd_lst;
	char	**env;
	size_t	env_size;
	size_t	env_left;
	char	*cwd;
	char	ret[4];
};

/* FILE: src/minishell.c */

t_msh	*free_msh(t_msh *msh);
void	clean_msh(t_msh *msh);

/* ================================ Signals ================================ */

/* FILE: src/signals/signals.c */

void	signal_handling(void);
void	handle_sigint(int sig);
void	handle_sigquit(int sig);

#endif
