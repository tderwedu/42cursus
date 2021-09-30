/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:10:52 by tderwedu          #+#    #+#             */
/*   Updated: 2021/09/30 15:56:50 by tderwedu         ###   ########.fr       */
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

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;

//int argc, char **argv, char **env
int	main(void)
{
	// DIR			*dirp;
	// t_dirent	*info;
	char	*pwd;
	char	cwd[MAXPATHLEN];
	t_stat	stat_pwd;
	t_stat	stat_cwd;
	t_stat	stat_cur;

	// dirp = opendir(".");
	// errno = 0;
	// info = readdir(dirp);
	
	pwd = getenv("PWD");
	getcwd(cwd, MAXPATHLEN);
	printf("\n");
	printf("GETCWD:%s\n", cwd);
	printf("PWD   :%s\n", pwd);
	if (stat(pwd, &stat_pwd))
		perror("stat PWD ");
	if (stat(pwd, &stat_cwd))
		perror("stat CWD ");
	if (stat(".", &stat_cur))
		perror("stat CWD ");
	S_ISLNK(stat_cur.st_mode); // TO know if symlink!!
	printf("\n");
	printf("GETCWD:inode: %llu\n", stat_cwd.st_ino);
	printf("PWD   :inode: %llu\n", stat_pwd.st_ino);
	printf("PWD   :inode: %llu\n", stat_cur.st_ino);
	printf("=====================\n");
	char	*test = "/new";
	if (stat(test, &stat_cur))
		perror("stat CWD ");
	if (chdir(test))
	{
		printf("errno: %i\n", errno);
		perror("chdir");
	}
	getcwd(cwd, MAXPATHLEN);
	printf("\n");
	printf("GETCWD:%s\n", cwd);
}
