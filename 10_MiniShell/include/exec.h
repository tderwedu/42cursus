/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:13:49 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/06 17:56:43 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <fcntl.h>
# include "utils.h"
# include "parser.h"
# include "minishell.h"
# include "error_messages.h"

/* TODO: all ERR in ine header */
// # define ERR_MALLOC		"Malloc error."

typedef struct s_io		t_io;
typedef struct s_exec	t_exec;
typedef struct s_tok	t_tok;
typedef struct s_ast	t_ast;
typedef struct s_msh	t_msh;

struct s_io
{
	int		fd;
	int		fd_h;
	int		fd_d;
	int		oflag;
	char	*filename;
	t_io	*next;
};

struct s_exec
{
	t_msh	*msh;
	pid_t	pid;
	int		pipe_in[2];
	int		pipe_out[2];
	t_io	*io;
	char	*cmdpath;
	int		size;
	char	**tab;
	char	**env;
};

typedef struct s_cmd
{
	t_msh	*msh;
	t_exec	*exec;
	t_io	*tail;
	int		i;
}				t_cmd;

/* ================================= Command =============================== */

/* FILE: src/exec/command1.c */

void	cmd_get(t_msh *msh, t_ast *ast, t_exec *exec);
void	cmd_add_word(t_cmd *cmd, t_ast *ast);
void	cmd_ast_traversal(t_msh *msh, t_cmd *cmd, t_ast *ast);
void	cmd_add_io(t_msh *msh, t_cmd *cmd, t_ast *ast);

/* FILE: src/exec/command2.c */

int		cmd_word_count(t_ast *ast);
void	free_exec(t_exec *exec);
void	cmd_error(t_cmd *cmd, char *msg);
void	print_exec(t_exec *exec);

/* FILE: src/exec/heredoc.c */

int		heredoc(t_msh *msh, t_ast *ast);

// TODO: reORGANIZE

void	set_path(t_msh *msh);
char	*get_bin(t_msh *msh, char *name);

/* ================================= Builtins =============================== */

/* FILES: src/builtins/ */

int		msh_cd(t_exec *exec);
int		msh_pwd(t_exec *exec);
int		msh_env(t_exec *exec);
int		msh_exit(t_exec *exec);
int		msh_echo(t_exec *exec);
int		msh_unset(t_exec *exec);
int		msh_export(t_exec *exec);

/* ================================= tmp =============================== */


typedef int (*t_fct)(t_exec *exec);
typedef struct s_builtin
{
	char	*name;
	t_fct	fct;
}					t_builtin;

t_fct	is_builtin(char *name);

void	msh_launch(t_msh *msh);

void	do_redir(t_exec *exec);
void	undo_redir(t_exec *exec);
void	redir_io_lst(t_exec *exec);

#endif
