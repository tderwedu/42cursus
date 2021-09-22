/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:32:26 by tderwedu          #+#    #+#             */
/*   Updated: 2021/09/22 17:02:57 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "word_expansion.h"

# define ERR_MALLOC		"Malloc error."

void	msh_error(t_cst *root, char *msg)
{
	(void)root;
	(void)msg;
}

int	get_param_name(char *str, char **name)
{
	char	*ptr;

	*name = NULL;
	ptr = str;
	if ((*ptr >= 'A' && *str <= 'Z') || (*ptr >= 'a' && *ptr <= 'z')
		|| *ptr == '_')
		ptr++;
	else
		return (0);
	while (*ptr && ((*ptr >= 'A' && *ptr <= 'Z')
			|| (*ptr >= 'a' && *ptr <= 'z') || *ptr == '_'))
		ptr++;
	*name = ft_substr(str, 0, ptr - str);
	if (!name)
		return (1);
	return (0);
}

char	*get_env_value(char **env, char *name)
{
	int		len;

	if (!env || !name)
		return (NULL);
	len = ft_strlen(name);
	while (*env)
	{
		if (!ft_strncmp(*env, name, len) && (*env)[len] == '=')
			return (*env + len + 1);
		env++;
	}
	return (NULL);
}

void	msh_get_param_value(t_we *we, t_pe *pe)
{
	char	*name;

	pe->len_lex = ft_strlen(pe->lex);
	if (get_param_name(pe->ptr_1 + 1, &name))
		msh_error(we->root, ERR_MALLOC);
	if (name)
	{
		pe->param = get_env_value(we->env, name);
		pe->ptr_2 = pe->ptr_1 + ft_strlen(name) + 1;
		free(name);
		pe->len_param = 0;
		if (pe->param)
			pe->len_param = ft_strlen(pe->param);
	}
	else
	{
		if (*(pe->ptr_1 + 1) == '"' || *(pe->ptr_1 + 1) == '\'')
			pe->ptr_2 = pe->ptr_1 + 1;
		else
		{
			pe->ptr_1++;
			pe->ptr_2 = pe->ptr_1;
		}
	}
}

char	*msh_substitute_param(t_we *we, char *ptr)
{
	t_pe	pe;
	char	*new;
	char	*new_ptr;

	pe = (t_pe){we->node->lexeme, ptr, NULL, NULL, 0, 0};
	msh_get_param_value(we, &pe);
	new = malloc(sizeof(*new) * (pe.len_lex + pe.len_param));
	if (!new)
		msh_error(we->root, ERR_MALLOC);
	new_ptr = new;
	ft_memcpy(new, pe.lex, pe.ptr_1 - pe.lex);
	new_ptr += (pe.ptr_1 - pe.lex);
	if (pe.param)
	{
		ft_memcpy(new_ptr, pe.param, pe.len_param);
		new_ptr += pe.len_param;
	}
	ft_memcpy(new_ptr, pe.ptr_2, pe.len_lex - (pe.ptr_2 - pe.lex));
	*(new_ptr + pe.len_lex - (pe.ptr_2 - pe.lex))= '\0';
	free(we->node->lexeme);
	we->node->lexeme = new;
	return (new_ptr - 1);
}

void	msh_param_expansion(t_we *we)
{
	char	*ptr;
	int		quoted;

	quoted = 0;
	ptr = we->node->lexeme;
	while (*ptr)
	{
		if (*ptr == '$' && !quoted)
			ptr = msh_substitute_param(we, ptr);
		else if (*ptr == '\'')
			quoted = !quoted;
		ptr++;
	}
}

// void	msh_field_splitting(char **env, t_cst *cst)
// {
// 	const char	*ifs;

// 	ifs = get_env_value(env, "IFS");
// 	if (!ifs)
// 		ifs = " \t\n";
	
// }

void	msh_cst_traversal(t_we *we)
{
	t_cst	*right_branch;
	t_cst	*left_branch;

	left_branch = we->node->left;
	right_branch = we->node->right;
	if (we->node->lexeme)
	{
		msh_param_expansion(we);
		// msh_quote_removal(cst);
	}
	if (left_branch)
	{
		we->node = left_branch;
		msh_cst_traversal(we);
	}
	if (right_branch)
	{
		we->node = right_branch;
		msh_cst_traversal(we);
	}
}

void	msh_word_expansion(char **env, t_cst *cst)
{
	t_we	we;
	if (!cst)
		return ;
	we = (t_we){env, cst, cst, 0};
	msh_cst_traversal(&we);
}
