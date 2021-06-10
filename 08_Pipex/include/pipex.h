/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:56:02 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/10 12:04:18 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"

# include <stdio.h>	//TODO:remove

typedef struct s_prog
{
	int		*fd_in;
	int		*fd_out;
	char	*file_in;
	char	*file_out;
	char	*cmd;
	char	**env;
	char	**dir;
}				t_prog;

/*
** 	utils
*/

void	free_array(char **arr);
char	*ft_path_join(char const *dir, char const *file);

/*
** 	pipex_error.c
*/

void	error_pipex(char **dir, char *str);
void	error_prog(t_prog *prog, char *path, char **argv, char *str);

/*
** 	pipex_utils.c
*/

char	**get_dir(char **env);
char	*get_path(char **dir, char *exe);

/*
** 	pipex_run_prog.c
*/

void	pipe_in(t_prog *prog);
void	pipe_in(t_prog *prog);
void	run_prog(t_prog *prog);

#endif
