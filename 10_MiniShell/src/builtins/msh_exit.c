/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:32:42 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/07 09:56:01 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "utils.h"

// TODO: one HEADER with all MSGs
// #define	MSG_EXIT			"msh: exit: "
// #define	MSG_EXIT_USE		": numeric argument required\n"
// #define	MSG_EXIT_ARGS		"too many arguments\n"

int	msh_exit(t_exec *exec)
{
	(void)exec;
	// int		ret;
	// char	*val;
	// char	*ptr;

	// write(1, "exit\n", 5);
	// ret = ret_atoi(msh);
	// if (exec->argv[1])
	// {
	// 	val = exec->argv[1];
	// 	ptr = exec->argv[1];
	// 	while (*ptr && (*ptr >= '0' && *ptr <= '9'))
	// 		ptr++;
	// 	if (*ptr)
	// 		return (msh_print_error(MSG_EXIT, val, MSG_EXIT_USE, 0xFF));
	// 	ret = (ft_atoi(val) & 0xFF);
	// }
	// if (exec->argv[2])
	// 	return (msh_print_error(MSG_EXIT, MSG_EXIT_ARGS, NULL, 0xFF));
	// free_msh(msh);
	// exit(ret);
	exit(EXIT_SUCCESS);
}
