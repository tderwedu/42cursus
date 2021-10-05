/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::	*/
<<<<<<< HEAD
/*	MSG_CD.c											:+:	  :+:	:+:	*/
=======
/*	msh_cd.c											:+:	  :+:	:+:	*/
>>>>>>> 7fba0d37e81594fe3547fdcd7d0ff558dac266a7
/*													+:+ +:+		 +:+	 */
/*	By: tderwedu <tderwedu@student.s19.be>		 +#+  +:+		+#+		*/
/*												+#+#+#+#+#+	+#+			*/
/*	Created: 2021/09/28 10:05:51 by tderwedu		  #+#	#+#			 */
/*	Updated: 2021/10/01 14:25:24 by tderwedu		 ###	########.fr		*/
/*																			*/
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

<<<<<<< HEAD
typedef struct stat		t_stat;

//TODO: on single HEADER to rule them all
// #define	MSG_CD			"msh: cd: "
// #define	MSG_CD_USE		": invalid option\ncd: usage: cd [dir]\n"
// #define	MSG_HOME		"HOME not set\n"
// #define	MSG_OLDPWD		"OLDPWD not set\n"
// #define	MSG_ELOOP		": Too many levels of symbolic links\n"
// #define	MSG_ENOENT		": No such file or directory\n"
// #define	MSG_ENAME2LONG	": File name too long\n"
// #define MSG_ENOTDIR		": Not a directory\n"
// #define EXIT_FAIL		1

int	MSG_CD_export(t_msh *msh, char *name, char *val)
{
	int		len_val;
	int		len_name;
	char	*var;
	char	**env;

	len_val = ft_strlen(val);
	len_name = ft_strlen(name);
	env = utils_env_param(msh->env, name, len_name);
	if (env)
	{
		var = malloc(sizeof(*var) * (len_name + len_val + 2));
		if (!var)
			return (EXIT_FAILURE);
		ft_memcpy(var, name, len_name);
		var[len_name] = '=';
		ft_memcpy(var + len_name + 1, val, len_val);
		var[len_name + 1 + len_val] = '\0';
		free(*env);
		*env = var;
=======
# define DIRSEP		'/'
typedef struct stat		t_stat;

// #define ELOOP			62			  /* Too many levels of symbolic links */
// #define ENAMETOOLONG	63			  /* File name too long */

int	path_isabsolute(char *str)
{
  if (str == 0 || str[0] == '\0')
	return (0);
  if (str[0] == '/')
	return (1);
  if (str[0] == '.' && (str[1] == '/' || str[1] == '\0'))
	return (1);
  if (str[0] == '.' && str[1] == '.' && (str[2] == '/' || str[2] == '\0'))
	return (1);
  return (0);
}

/*
** Return 1 if PATH corresponds to a directory. 
*/
static int	msh_isdir (char *path)
{
	t_stat	sb;

	return (stat (path, &sb) == 0 && S_ISDIR (sb.st_mode));
}

static inline void	msh_canonpath_backtrack(char **p, char **q, char *base)
{
	(*p) += 2;
	if ((*q) > base)
	{
		while (--(*q)  > base && (*q)[0] != '/')
			;
	}
}
static inline void	msh_canonpath_cpy(char **p, char **q, char *base)
{
	if ((*q)  != base)
		*(*q) ++ = '/';
	while ((*p)[0] && (*p)[0] != '/')
		*(*q) ++ = *(*p)++;
}

/*
** Return the canonical path from PATH:
** - Multiple '/'s are collapsed to a single '/'.
** - Leading './'s and trailing '/.'s are removed.
** - Trailing '/'s are removed.
** - Non-leading '../'s and trailing '..'s are handled by removing
**   portions of the path.
** Variables:
** - base ust past the root directory
** - p points at beginning of path element we're considering.
** - q points just past the last kept directory.
**/
char	*msh_canonpath(char *path)
{
	char	*result;
	char	*base;
	char	*p;
	char	*q;

	result = ft_strdup(path);
	if (!result)
		return (NULL);
	base = result + (result[0] == '/') + (result[1] == '/');
	p = base;
	q = base;
	while (p[0])
	{
		if (p[0] == '/')
			p++;
		else if(p[0] == '.' && (p[1] == '/' || p[1] == '\0'))
			p++;
		else if (p[0] == '.' && p[1] == '.' && (p[2] == '/' || p[2] == '\0'))
			msh_canonpath_backtrack(&p, &q, base);
		else
			msh_canonpath_cpy(&p, &q, base);
	}
	q[0] = '\0';
	return (result);
}

int  msh_cd(t_msh *msh, int argc, char **argv, char **env)
{
	char	*dst;
	t_vec	*buff;

	/* Opt handling */
	if (ft_strcmp(argv[1], "-") < 0)
	{
		write(2, "msh: cd: ", 9);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, ": invalid option\ncd: usage: cd [dir]\n", 37);
		return (EXIT_FAILURE);
	}
	/* Get dst*/
	if (!argv[1])
	{
		dst = utils_env_get_param(env, "HOME", 4);
		if (!dst)
		{
				write(2, "msh: cd: HOME not set\n", 22);
				return (EXIT_FAILURE);
		}
>>>>>>> 7fba0d37e81594fe3547fdcd7d0ff558dac266a7
	}
	return (EXIT_SUCCESS);
}

int	msh_chdir(t_msh *msh, char *path, int update)
{
	errno = 0;
	if (chdir(path))
		return (msh_print_error(MSG_CD, strerror(errno), NULL, EXIT_FAILURE));
	if (MSG_CD_export(msh, "OLDPWD", msh->cwd))
		return (EXIT_FAILURE);
	if (MSG_CD_export(msh, "PWD", path))
		return (EXIT_FAILURE);
	free(msh->cwd);
	if (!update)
		msh->cwd = path;
	else
	{
<<<<<<< HEAD
		free(path);
		msh->cwd = getcwd(NULL, 0);
	}
	return (EXIT_SUCCESS);
}

char	*get_absolute_path(char *cwd, char *dst)
{
	int		len_cwd;
	int		len_dst;
	int		sep;
	char	*path;
	char	*canon_path;

	if (dst[0] == '/')
		path = ft_strdup(dst);
	else
	{
		len_cwd = ft_strlen(cwd);
		len_dst = ft_strlen(dst);
		sep = (len_cwd > 2 || (len_cwd == 2 && cwd[1] != '/'));
		path = malloc(sizeof(*path) * (len_cwd + sep + len_dst + 1));
		if (!path)
			return (NULL);
		ft_memcpy(path, cwd, len_cwd);
		if (sep)
			path[len_cwd] = '/';
		ft_memcpy(path + len_cwd + sep, dst, len_dst);
		path[len_cwd + sep + len_dst] = '\0';
	}
	canon_path = msh_canonpath(path);
	free(path);
	return (canon_path);
}

/*
** msh_check_path:
** Check if PATH is a valid path.
*/
int	msh_check_path(char *dst, char *path)
{
	t_stat	st;

	errno = 0;
	if (stat(path, &st))
=======
		dst = utils_env_get_param(env, "OLDPWD", 4);
		if (!dst)
		{
				write(2, "msh: cd: OLDPWD not set\n", 24);
				return (EXIT_FAILURE);
		}
	}
	else
		dst = argv[1];

	// concatenate: ABS = CWD + DST
	// Canonicalize CAN = canolize(ABS)
	// Check if PATH exist
	//	y-> use canonical CAN
	//	n-> try with ABS
	// Change directory: chdir()
	// Update PWD:
	//	- CAN: set PWD=CAn
	//	- ABS: uset getCWD
	
	if (dst > MAXPATHLEN)
>>>>>>> 7fba0d37e81594fe3547fdcd7d0ff558dac266a7
	{
		if (errno == ENOENT || errno == ELOOP)
			return (0);
		else if (errno == ENAMETOOLONG)
			return (msh_print_error(MSG_CD, dst, MSG_ENAME2LONG, EXIT_FAILURE));
		else if (!S_ISDIR (st.st_mode))
			return (msh_print_error(MSG_CD, dst, MSG_ENOTDIR, EXIT_FAILURE));
		else
			return (msh_print_error(MSG_CD, strerror(errno), NULL, EXIT_FAILURE));
	}
<<<<<<< HEAD
	if (ft_strlen(dst) > MAXPATHLEN)
		return (msh_print_error(MSG_CD, dst, MSG_ENAME2LONG, EXIT_FAILURE));
	return (0);
}

int	msh_set_path(t_msh *msh, char *dst)
{
	int		update;
	char	*path;

	path = get_absolute_path(msh->cwd, dst);
	if (msh_check_path(dst, path))
		return (EXIT_FAILURE);
	update = (errno == ELOOP);
	if (errno == ENOENT || errno == ELOOP)
	{
		free(msh->cwd);
		msh->cwd = getcwd(NULL, 0);
		path = get_absolute_path(msh->cwd, dst);
		if (msh_check_path(dst, path))
			return (EXIT_FAILURE);
		if (errno == ENOENT)
			return (msh_print_error(MSG_CD, dst, MSG_ENOENT, EXIT_FAILURE));
		else if (errno == ELOOP)
			return (msh_print_error(MSG_CD, dst, MSG_ELOOP, EXIT_FAILURE));
	}
	return (msh_chdir(msh, path, update));
}

int	msh_cd(t_msh *msh, t_exec *exec)
{
	char	*path;

	if (!exec->tab[1])
	{
		path = utils_env_get_param(exec->env, "HOME", 4);
		if (!path)
			return (msh_print_error(MSG_CD, MSG_HOME, NULL, EXIT_FAILURE));
		return (msh_set_path(msh, path));
	}
	else if (exec->tab[1][0] == '-' && exec->tab[1][1] == '\0')
	{
		path = utils_env_get_param(exec->env, "OLDPWD", 4);
		if (!path)
			return (msh_print_error(MSG_CD, MSG_OLDPWD, NULL, EXIT_FAILURE));
		return (msh_set_path(msh, path));
	}
	else if (exec->tab[1][0] == '-')
		return (msh_print_error(MSG_CD, exec->tab[1], MSG_CD_USE, EXIT_FAILURE));
	else
		return (msh_set_path(msh, exec->tab[1]));
}
=======
	/* Error Handling*/
	buff = ft_vec_new(2 * (MAXPATHLEN + 1));
	if (!buff)
		msh_error(msh, ERR_MALLOC);
	ft_strcpy();

}

char	*msh_chdir(t_msh *msh, char *dst)
{
	if (!msh->cwd)
		msh->cwd = get_cwd(NULL, 0);
}


// char	*msh_canonpath(char *path)
// {
// 	char	*result;
// 	char	*base;
// 	char	*p;
// 	char	*q;

// 	result = strdup(path);
// 	if (!result)
// 		return (NULL);
// 	base = result + 1;
// 	if (result[1] == '/')
// 		base++;
// 	p = base;
// 	q = base;
// 	while (p[0])
// 	{
// 		if (p[0] == '/')
// 			p++;
// 		else if(p[0] == '.' && (p[1] == '/' || p[1] == '\0'))
// 			p++;
// 		else if (p[0] == '.' && p[1] == '.' && (p[2] == '/' || p[2] == '\0'))
// 		{
// 			p += 2;
// 			if (q > base)
// 			{
// 				while (--q > base && q[0] != '/')
// 					;
// 			}
// 		}
// 		else
// 		{
// 			if (q != base)
// 				*q++ = '/';
// 			while (p[0] && p[0] != '/')
// 				*q++ = *p++;
// 		}
// 	}
// 	q[0] = '\0';
// 	return (result);
// }
>>>>>>> 7fba0d37e81594fe3547fdcd7d0ff558dac266a7
