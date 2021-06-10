/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:25:59 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/10 12:03:47 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"



int	main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	int		wstatus;
	pid_t	pid;
	char	**dir;
	t_prog	prog;

	if (argc != 5)
		return (0);
	dir = get_dir(env);
	if (!dir)
		return (EXIT_FAILURE);
	if (pipe(p_fd) == -1)
		error_pipex(dir, "pipe");
	// dprintf(2, "\nfd[0]: %i | fd[1]: %i \n", p_fd[0], p_fd[1]);
	pid = fork();
	if (pid == -1)
		error_pipex(dir, "fork");
	else if (pid == 0)
	{
		prog = (t_prog){NULL, p_fd, argv[1], NULL, argv[2], env, dir};
		run_prog(&prog);
	}
	else
	{
		if (close(p_fd[1]) == -1)
			error_pipex(dir, "close");
		pid = wait(&wstatus);
		if (!WIFEXITED(wstatus))
			error_pipex(dir, "execve");
		prog = (t_prog){p_fd, NULL, NULL, argv[4], argv[3], env, dir};
		run_prog(&prog);
	}
}
