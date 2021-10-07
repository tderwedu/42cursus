/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:25:07 by namenega          #+#    #+#             */
/*   Updated: 2021/10/07 09:39:01 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

// Choose between ERR and MSG
# define MSG_MSH		"msh: "
# define MSG_CD			"msh: cd: "
# define MSG_EXECVE		"msh: execve: "
# define MSG_EXPORT		"msh: export: `"
# define ERR_MALLOC		"Malloc error."
# define ERR_NO_CMD		"msh: %s: command not found\n"		// TODO: replace with msh_print_error
# define ERR_QUOTES		"msh: error odd number of quotes."
# define ERR_SYNTAX		"Syntax Error near: %s\n"			// TODO: replace with msh_print_error
# define MSG_CD_USE		": invalid option\ncd: usage: cd [dir]\n"
# define MSG_ELOOP		": Too many levels of symbolic links\n"
# define MSG_ENAME2LONG	": File name too long\n"
# define MSG_EXIT		"msh: exit: "
# define MSG_EXIT_ARGS	"too many arguments\n"
# define MSG_EXIT_USE	": numeric argument required\n"
# define MSG_ENOENT		": No such file or directory\n"
# define MSG_ENOTDIR	": Not a directory\n"
# define MSG_HOME		"HOME not set\n"
# define MSG_IDENTIFIER	"': not a valid identifier\n"
# define MSG_NOTFOUND	": command not found\n"
# define MSG_OLDPWD		"OLDPWD not set\n"

#endif
