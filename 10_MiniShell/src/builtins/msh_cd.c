/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:05:51 by tderwedu          #+#    #+#             */
/*   Updated: 2021/09/30 15:57:43 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include "utils.h"


// #define ELOOP           62              /* Too many levels of symbolic links */
// #define ENAMETOOLONG    63              /* File name too long */

int	msh_cd(t_msh *msh, int argc, char **argv, char **env)
{
	int		len_t;
	int		len_h;
	int		len_a;
	char	*dst;
	char	*ptr;

	if (!argv[1])
	{
		dst = utils_env_get_param(env, "HOME", 4);
		if (!dst)
		{
			write(2, "msh: cd: HOME not set\n", 22);
			return (EXIT_FAILURE);
		}
	}
	else if (argv[1][0]== '-' && argv[1][1] == '\0')
	{
		dst = utils_env_get_param(env, "OLDPWD", 4);
		if (!dst)
		{
			write(2, "msh: cd: OLDPWD not set\n", 24);
			return (EXIT_FAILURE);
		}
	}
	else if (ft_strcmp(argv[1], "-") < 0)
	{
		write(2, "msh: cd: ", 9);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, ": invalid option\ncd: usage: cd [dir]\n", 37);
		return (EXIT_FAILURE);
	}
	else if (ft_strlen(argv[1]) > MAXPATHLEN)
	{
		write(2, "msh: cd: ", 9);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, ": File name too long\n", 21);
	}

	
	
}