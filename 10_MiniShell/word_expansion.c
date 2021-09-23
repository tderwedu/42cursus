/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:32:26 by tderwedu          #+#    #+#             */
/*   Updated: 2021/09/23 17:09:03 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "word_expansion.h"

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
	while (*ptr && ((*ptr >= 'A' && *ptr <= 'Z') || (*ptr >= 'a' && *ptr <= 'z')
			|| (*ptr >= '0' && *ptr <= '9') || *ptr == '_'))
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

char	*msh_get_ifs(char **env)
{
	char	*ifs;

	ifs = get_env_value(env, "IFS");
	printf("ENV : IFS: >%s< \n", ifs);
	if (!ifs)
		ifs = " \t\n";
	return (ifs);
}

void	msh_add_word(t_we *we, t_vec *vec)
{
	char	*lex;
	t_cst	*new;

	*vec->ptr = '\0';
	lex = ft_strdup(vec->str);
	if (!lex)
		msh_error(we->root, ERR_MALLOC);
	if (we->node->lex)
	{
		new = malloc(sizeof(*new));
		if (!new)
		{
			free(lex);
			//TODO: free old !!!
			//TODO: free vec !!!
			msh_error(we->root, ERR_MALLOC);
		}
		new->type = CST_WORD;
		new->lex = lex;
		new->right = NULL;
		new->left = we->node->left;
		we->node->left = new;
		we->node = new;
		*vec->str = '\0';
		vec->ptr = vec->str;
	}
	else
		we->node->lex = lex;
}

void	msh_param_substitution(t_we *we, char *param, t_vec *vec, int state)
{
	int		len;
	int		splitting;
	char	*ifs;

	len = ft_strlen(param);
	splitting = (we->type == TYPE_CMD && state == WE_ST_FREE);
	while ((vec->end - vec->ptr) <= len)
		ft_grow_vec(vec);
	ifs = msh_get_ifs(we->env);
	while (*param)
	{
		if (splitting && ft_strchr(ifs, *param))
		{
			if (*vec->str != '\0')
				msh_add_word(we, vec);
			else
				param++;
			}
		else
			*vec->ptr++ = *param++;
	}
}

char	*msh_param_expansion(t_we *we, char *ptr, t_vec *vec, int state)
{
	char	*name;
	char	*param;

	if (get_param_name(ptr + 1, &name))
		msh_error(we->root, ERR_MALLOC);
	if (name)
	{
		param = get_env_value(we->env, name);
		ptr = ptr + ft_strlen(name);
		free(name);
		if (param)
			msh_param_substitution(we, param, vec, state);
	}
	else if (!(*(ptr + 1) == '\"' || *(ptr + 1) == '\''))
		*vec->ptr++ = *ptr;
	return ptr;
}

void	msh_lexeme_formating(t_we *we)
{
	char	*old;
	char	*ptr;
	t_vec	*vec;
	int		state;

	vec = ft_new_vec(VEC_DFLT_SIZE);	// TODO: verify that size > len(lex) !!!
	old = we->node->lex;
	ptr = we->node->lex;
	we->node->lex = NULL;
	if (!ptr)
		return ;
	state = WE_ST_FREE;
	while (*ptr)
	{
		if (*ptr == '$' && state != WE_ST_SQUOTE)
			ptr = msh_param_expansion(we, ptr, vec, state);
		else if (*ptr == '\'' && state == WE_ST_FREE)
			state = WE_ST_SQUOTE;
		else if (*ptr == '\'' && state == WE_ST_SQUOTE)
			state = WE_ST_FREE;
		else if (*ptr == '\"' && state == WE_ST_FREE)
			state = WE_ST_DQUOTE;
		else if (*ptr == '\"' && state == WE_ST_DQUOTE)
			state = WE_ST_FREE;
		else
			*vec->ptr++ = *ptr;
		ptr++;
	}
	free(old);
	if (*vec->str)
	{
		ptr = ft_strdup(vec->str);
		ft_free_vec(vec);
		if (!ptr)
			msh_error(we->root, ERR_MALLOC);
		we->node->lex = ptr;
	}
	else
	ft_free_vec(vec);
}

void	msh_cst_traversal(t_we *we)
{
	t_cst	*right_branch;
	t_cst	*left_branch;

	left_branch = we->node->left;
	right_branch = we->node->right;
	if (we->node->type == CST_IO_REDIR)
		we->type = TYPE_IO;
	if (we->node->lex)
	{
		msh_lexeme_formating(we);
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
	we->type = TYPE_CMD;
}

// Need to add to the WE struct
// - old
// - vec
// Need to check no ERROR when NEW vec or GROW vec

void	msh_word_expansion(char **env, t_cst *cst)
{
	t_we	we;
	if (!cst)
		return ;
	we = (t_we){env, cst, cst, TYPE_CMD};
	msh_cst_traversal(&we);
}

// void	msh_get_param_value(t_we *we, t_pe *pe)
// {
// 	char	*name;

// 	pe->len_lex = ft_strlen(pe->lex);
// 	if (get_param_name(pe->lex_1 + 1, &name))
// 		msh_error(we->root, ERR_MALLOC);
// 	if (name)
// 	{
// 		pe->param = get_env_value(we->env, name);
// 		pe->lex_2 = pe->lex_1 + ft_strlen(name) + 1;
// 		free(name);
// 		pe->len_param = 0;
// 		if (pe->param)
// 			pe->len_param = ft_strlen(pe->param);
// 	}
// 	else
// 	{
// 		if (*(pe->lex_1 + 1) == '"' || *(pe->lex_1 + 1) == '\'')
// 			pe->lex_2 = pe->lex_1 + 1;
// 		else
// 		{
// 			pe->lex_1++;
// 			pe->lex_2 = pe->lex_1;
// 		}
// 	}
// }

// char	*msh_substitute_param(t_we *we, t_pe *pe)
// {
// 	msh_get_param_value(we, pe);
// 	pe->new = malloc(sizeof(*pe->new) * (pe->len_lex + pe->len_param));
// 	if (!pe->new)
// 		msh_error(we->root, ERR_MALLOC);
// 	ft_memcpy(pe->new, pe->lex, pe->lex_1 - pe->lex);
// 	pe->new_1 = pe->new + (pe->lex_1 - pe->lex);
// 	if (pe->param)
// 		ft_memcpy(pe->new_1, pe->param, pe->len_param);
// 	pe->new_2 = pe->new_1 + pe->len_param;
// 	ft_memcpy(pe->new_2, pe->lex_2, pe->len_lex - (pe->lex_2 - pe->lex));
// 	*(pe->new_2 + pe->len_lex - (pe->lex_2 - pe->lex))= '\0';
// 	free(we->node->lex);
// 	we->node->lex = pe->new;
// 	*pe = (t_pe){pe->new, pe->new_1, pe->new_2, NULL, NULL, NULL,
// 			NULL, 0, 0, pe->state};
// 	return (pe->lex_2 - 1);
// }

// void	msh_param_expansion(t_we *we)
// {
// 	t_pe	pe;

// 	pe = (t_pe){we->node->lex, we->node->lex, NULL, NULL, NULL, NULL,
// 			NULL, 0, 0, WE_ST_FREE};
// 	while (*pe.lex_1)
// 	{
// 		if (*pe.lex_1 == '$' && pe.state != WE_ST_SQUOTE)
// 			pe.lex_1 = msh_substitute_param(we, &pe);
// 		else if (*pe.lex_1 == '\'' && pe.state == WE_ST_FREE)
// 			pe.state = WE_ST_SQUOTE;
// 		else if (*pe.lex_1 == '\'' && pe.state == WE_ST_SQUOTE)
// 			pe.state = WE_ST_FREE;
// 		else if (*pe.lex_1 == '\"' && pe.state == WE_ST_FREE)
// 			pe.state = WE_ST_DQUOTE;
// 		else if (*pe.lex_1 == '\"' && pe.state == WE_ST_DQUOTE)
// 			pe.state = WE_ST_FREE;
// 		pe.lex_1++;
// 	}
// }
