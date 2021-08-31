/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:25:18 by tderwedu          #+#    #+#             */
/*   Updated: 2021/08/19 17:29:42 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	printf("IFS=%s\n", getenv("IFS"));
}
