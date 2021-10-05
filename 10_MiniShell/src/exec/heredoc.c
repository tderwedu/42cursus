/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:24:00 by namenega          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/10/05 11:36:29 by namenega         ###   ########.fr       */
=======
/*   Updated: 2021/10/01 16:33:23 by namenega         ###   ########.fr       */
>>>>>>> 7fba0d37e81594fe3547fdcd7d0ff558dac266a7
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

//CTRL C need to stop process
//CTRL D need to stop process but print readline buffer already registered.

<<<<<<< HEAD
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
=======
static void	read_heredoc(char *line, t_exec *exec)
{
	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(line, exec->io->filename))
			break ;
		write(1, line, ft_strlen(line));
		write(1, "\n" ,1);
	}
}

void	heredoc(t_exec *exec)
>>>>>>> 7fba0d37e81594fe3547fdcd7d0ff558dac266a7
{
	pid_t	pid;
	int		pipefd[2];
	char	*line;
<<<<<<< HEAD
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
		signal(SIGINT, SIG_DFL);
		read_heredoc(pipefd, line, eof);
=======
	int		ret;

	if (pipe(pipefd) == -1)
		return ;					//!Error msg need to change : pipe error.
	pid = fork();
	if (pid < 0)
		return ;					//!Error msg need to change : fork error.
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		read_heredoc(line, exec);
		// while (1)
		// {
		// 	line = readline("> ");
		// 	if (!line || !ft_strcmp(line, exec->io->filename))
		// 		break ;
		// 	write(1, line, ft_strlen(line));
		// 	write(1, "\n" ,1);
		// }
>>>>>>> 7fba0d37e81594fe3547fdcd7d0ff558dac266a7
		free(line);
		close(pipefd[1]);
		close(pipefd[0]);
		exit(0);					//! Error need to change
	}
	else
	{
		waitpid(pid, &ret, 0);
		close(pipefd[1]);
<<<<<<< HEAD
		ret = WEXITSTATUS(ret);
		if (ret != EXIT_SUCCESS)
		{
			close(pipefd[0]);
			return (-1);
		}
	}
	printf("PIPE[0]:%i\n", pipefd[0]);
	printf("PIPE[1]:%i\n", pipefd[1]);
	return (pipefd[0]);
=======
		if (ret == EXIT_SUCCESS)
			close(pipefd[0]);
	}
>>>>>>> 7fba0d37e81594fe3547fdcd7d0ff558dac266a7
}
