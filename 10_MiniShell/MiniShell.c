/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniShell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:05:03 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/07 17:17:14 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

/* Global for Signals */

pid_t	g_pid;

t_msh	*free_msh(t_msh *msh)
{
	(void)msh;
	return (NULL);
}

void	msh_error(t_msh *msh, char *msg)
{
	(void)msh;
	printf("\e[31mEXIT_FAILURE\e[0m\n");
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

/*
**	TODO List
** - check free : line, tok, ast, exec
**
*/

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	t_msh	msh;

	g_pid = 0;
	msh.env_left = 5;
	msh.env_size = utils_env_size(env) + msh.env_left;
	msh.env = utils_env_copy(env, msh.env_size);
	msh.line = NULL;
	msh.tok = NULL;
	msh.ast = NULL;
	msh.ret[0] = '1';
	msh.ret[1] = '2';
	msh.ret[2] = '1';
	msh.ret[3] = '\0';

	// signal(SIGINT, handle_sigint);
	// signal(SIGQUIT, SIG_IGN);		// Ignore SIGQUIT
	signal_handling();
	printf("Welcome! Exit by pressing CTRL-D.\n");
	// set_path(&msh);
	msh.cwd = ft_strdup(msh_getenv(env, "PWD", 3));
	printf("\e[36mCWD\e[0m:%s\n", msh.cwd);
	while(1)
	{
		msh.line = readline("\e[32mmsh>\e[0m");
		if (!msh.line)
			break;
		else if (*msh.line)					// ADD to history if not empty
		{
			add_history(msh.line);
			lexer(&msh);
			parser(&msh);
			we_word_expansion(&msh);
			launcher(&msh);
		}
	}
	printf("\e[31m \nBye Bye!\e[0m\n");
}
