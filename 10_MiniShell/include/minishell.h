/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:45:02 by tderwedu          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/10/05 16:53:26 by tderwedu         ###   ########.fr       */
=======
/*   Updated: 2021/10/01 17:52:03 by tderwedu         ###   ########.fr       */
>>>>>>> 7fba0d37e81594fe3547fdcd7d0ff558dac266a7
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
# include "exec.h"
# include "error_messages.h"

/* TODO: all ERR in ine header */
/*# define ERR_NO_CMD	"msh: %s: command not found\n"*/

typedef struct s_tok	t_tok;
typedef struct s_ast	t_ast;
typedef struct s_msh	t_msh;

struct s_msh
{
	char	**env;
	char	**path;
	char	*line;
	t_tok	*tok;
	t_ast	*ast;
	char	ret[4];
	size_t	env_size;
	size_t	env_left;
	char	*cwd;
};

void	msh_free(t_msh *msh);
<<<<<<< HEAD
=======

void	set_path(t_msh *msh);
char	*get_bin(t_msh *msh, char *name);
>>>>>>> 7fba0d37e81594fe3547fdcd7d0ff558dac266a7

#endif
