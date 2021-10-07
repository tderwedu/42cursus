/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:24:00 by namenega          #+#    #+#             */
/*   Updated: 2021/10/07 09:40:49 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

extern pid_t	g_sig;

//CTRL C need to stop process
//CTRL D need to stop process but print readline buffer already registered.

static void	read_heredoc(int pipefd[2], char *line, char *eof)
{
	while (1)
	{
		line = readline("heredoc> ");
		if (!line || !ft_strcmp(line, eof))
			break ;
		write(pipefd[1], line, ft_strlen(line));
		write(pipefd[1], "\n", 1);
	}
}

int	heredoc(t_msh *msh, t_ast *ast)
{
	pid_t	pid;
	int		pipefd[2];
	char	*line;
	char	*eof;
	int		ret;

	(void)msh;
	line = NULL;
	eof = ast->right->lex;
	if (pipe(pipefd) == -1)
		return (0);					//!Error msg need to change : pipe error.
	pid = fork();
	if (pid < 0)
		return (0);					//!Error msg need to change : fork error.
	if (pid == 0)
	{
		g_sig = 1;
		signal(SIGINT, SIG_DFL);
		read_heredoc(pipefd, line, eof);
		free(line);
		close(pipefd[1]);
		close(pipefd[0]);
		exit(0);					//! Error need to change
	}
	else
	{
		waitpid(pid, &ret, 0);
		close(pipefd[1]);
		ret = WEXITSTATUS(ret);
		if (ret != EXIT_SUCCESS)
		{
			close(pipefd[0]);
			return (-1);
		}
	}
	// printf("PIPE[0]:%i\n", pipefd[0]);
	// printf("PIPE[1]:%i\n", pipefd[1]);
	return (pipefd[0]);
}
