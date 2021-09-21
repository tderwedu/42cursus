/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:32:26 by tderwedu          #+#    #+#             */
/*   Updated: 2021/09/21 17:12:24 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "word_expansion.h"

char	*msh_get_param_name(char *str)	//TODO: proper ERROR handling!!
{
	char	*chr_s;
	char	*name;

	if (!str)
		return (NULL);
	chr_s = str;
	if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')
		|| *str == '_')
		str++;
	else
		return (NULL);
	while (*str && ((*str >= 'A' && *str <= 'Z')
			|| (*str >= 'a' && *str <= 'z') || *str == '_'))
		str++;
	name = ft_substr(chr_s, chr_s, str - chr_s);
	if (!name)
		exit(1);
	return (name);
}

char	*get_env_value(char **env, char *var)	//TODO: proper ERROR handling!!
{
	char	*entry;
	int		len;

	if (!env || !var)
		return (NULL);
	len = ft_strlen(var);
	if (!len)
		return (NULL);
	entry = *env++;
	while (entry)
	{
		if (!ft_strncmp(entry, var, len))
			return (entry + len + 1);
	}
	return (NULL);
}

void	msh_param_expansion(char **env, t_cst *cst)
{
	char	*ptr;

	ptr = cst->lexeme;
	while (*ptr)
	{
		
		if (*ptr == '$')
		{
			msh_get_param_name(++ptr);

		}
	}
}

void	msh_field_splitting(char **env, t_cst *cst)
{
	const char	*ifs;

	ifs = get_env_value(env, "IFS");
	if (!ifs)
		ifs = " \t\n";
	
}

void	msh_word_expansion(char **env, t_cst *cst)
{
	t_cst	*right_branch;
	t_cst	*left_branch;

	right_branch = cst->right;
	left_branch = cst->left;
	if (cst->lexeme)
	{
		msh_param_expansion(env, cst);
		msh_quote_removal(cst);
	}
	msh_word_expansion(env, right_branch);
	msh_word_expansion(env, left_branch);
}