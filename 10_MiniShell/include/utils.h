/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 13:01:30 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/13 10:05:19 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include "libft.h"
# include "parser.h"
# include "minishell.h"
# include "error_messages.h"

typedef struct s_tok	t_tok;
typedef struct s_ast	t_ast;
typedef struct s_msh	t_msh;

/* FILE: utils.c */

int		ret_atoi(t_msh *msh);
void	ret_itoa(t_msh *msh, int ret);

/* FILE: utils_env.c */

void	sort_env(char **env);
char	**free_tab(char **env);
size_t	size_tab(char **env);
char	*utils_env_get_ifs(char **env);
char	*env_check_name(char *str);
char	*msh_getenv(char **env, char *var, int len);
char	*env_go_2_val(char *var);
char	**grow_tab(char **env, size_t size);
char	**get_env_addr(char **env, char *var, int len);
char	**get_env_next_addr(t_msh *msh);

/* FILE = function  name */

int		print_error(char *s1, char *s2, char *s3, int ret);
char	*msh_canonpath(char *path);
char	*path_join(char *dir, char *file);
int		check_quotes(t_msh *msh);

#endif
