/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:13:49 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/07 17:01:18 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/errno.h>
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

typedef struct dirent t_dirent;

typedef int (*t_fct)(t_exec *exec);
typedef struct s_builtin
{
	char	*name;
	t_fct	fct;
}					t_builtin;

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
	int		pipe_in[2];
	int		pipe_out[2];
	t_io	*io;
	t_fct	fct;
	char	*cmdpath;
	int		argc;
	char	**argv;
};

typedef struct s_cmd
{
	t_msh	*msh;
	t_exec	*exec;
	t_io	*tail;
	int		i;
}				t_cmd;

/* ================================= Launcher =============================== */

/* FILE: src/exec/launcher.c */

void	launcher(t_msh *msh);
void	error_exec(t_exec *exec, int ret);
void	error_exec_errno(t_exec *exec, char *msg);

/* FILE: src/exec/launch_simple.c */

void	launch_simple_cmd(t_exec *exec);

/* FILE: src/exec/launch_pipe.c */

void	launch_pipe_seq(t_exec *exec);
void	no_pipe(int	pipe[2]);
void	close_pipe(int pipe[2]);
void	switch_pipe(int pipe_in[2], int pipe_out[2]);

/* FILE: src/exec/redirection.c */

void	apply_redir(t_exec *exec, int save);
void	redir_io_lst(t_exec *exec, t_io *io, int save);
void	reverse_redir(t_exec *exec);

/* ================================= Launcher =============================== */

/* FILE: src/exec/prep_cmd.c */

void	prep_next_cmd(t_msh *msh, t_ast *ast, t_exec *exec);
void	cmd_add_word(t_cmd *cmd, t_ast *ast);
void	cmd_ast_traversal(t_msh *msh, t_cmd *cmd, t_ast *ast);
void	cmd_add_io(t_msh *msh, t_cmd *cmd, t_ast *ast);

/* FILE: src/exec/prep_cmd_utils.c */

int		cmd_word_count(t_ast *ast);
t_io	*free_io(t_io *node);
t_exec	*free_exec(t_exec *exec);
void	error_cmd(t_cmd *cmd, char *msg);
void	print_exec(t_exec *exec);

/* ================================= Builtins =============================== */

/* FILES: src/builtins/ */

int		msh_cd(t_exec *exec);
int		msh_pwd(t_exec *exec);
int		msh_env(t_exec *exec);
int		msh_exit(t_exec *exec);
int		msh_echo(t_exec *exec);
int		msh_unset(t_exec *exec);
int		msh_export(t_exec *exec);

/* ================================= Utils ================================= */

/* FILES: src/launcher/ */

t_fct	is_builtin(char *name);
char	*get_cmd_path(t_exec *exec, char *cmd);
int		heredoc(t_msh *msh, t_ast *ast);

#endif
