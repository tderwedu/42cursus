/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ast.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:50:56 by tderwedu          #+#    #+#             */
/*   Updated: 2021/09/21 16:14:52 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_AST_H
# define PARSER_AST_H

# include <fcntl.h>
# include "parser_cst.h"

typedef	struct s_io			t_io;
typedef struct s_cmd		t_cmd;
typedef struct s_parset_ast	t_parset_ast;

struct s_io_redir
{
	int		fd;
	int		oflag;
	char	*filename;
	t_io	*next;
};

struct s_cmd
{
	char	*name;
	char	**argv;
	char	**env;
	t_io	*redir;
	int		pipe_in;
	int		pipe_out;
	t_cmd	*next;
};

struct s_parset_ast
{
	t_cst	*cst;
	int		type;
	void	*ast;
	int		pipe_in;
};

void	msh_parser_ast(char **env, t_cst *cst);

#endif