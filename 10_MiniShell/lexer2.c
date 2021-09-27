/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:28:27 by tderwedu          #+#    #+#             */
/*   Updated: 2021/09/27 10:29:36 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	lexer_handle_pipe(t_lexer *lex)
{
	lexer_new_token(lex, WORD);
	lex->i++;
	lexer_new_token(lex, PIPE);
}

void	lexer_new_token(t_lexer *lex, int type)
{
	t_tok	*new;
	char	*lexeme;

	if (lex->i_p == lex->i)
		return ;
	new = malloc(sizeof(*new));
	if (!new)
		lexer_error(lex, ERR_MALLOC);
	lexeme = ft_substr(lex->line, lex->i_p, lex->i - lex->i_p);
	lex->i_p = lex->i;
	if (!lexeme)
	{
		free(new);
		lexer_error(lex, ERR_MALLOC);
	}
	*new = (t_tok){lexeme, type, NULL};
	if (!lex->head)
	{
		lex->head = new;
		lex->last = new;
		return ;
	}
	lex->last->next = new;
	lex->last = new;
}

void	lexer_free(t_lexer *lex)
{
	t_tok	*node;
	t_tok	*next;

	node = lex->head;
	next = lex->head->next;
	free(node->lex);
	free(node);
	while (next)
	{
		node = next;
		next = node->next;
		free(node->lex);
		free(node);
	}
}

void	lexer_error(t_lexer *lex, char *msg)
{
	lexer_free(lex);
	msh_error(lex->msh, msg);
}

void	lexer_print(t_tok *token)
{
	char	**arr_type;

	arr_type[0] = "PIPE";
	arr_type[1] = "GREAT";
	arr_type[2] = "LESS";
	arr_type[3] = "DGREAT";
	arr_type[4] = "DLESS";
	arr_type[5] = "WORD";
	arr_type[6] = "IO_NUMBER";
	printf("\033[33m\t### TOKEN LIST ### \033[0m \n");
	while (token)
	{
		printf(" /----------------------\\ \n");
		printf("   type : %s \n", arr_type[token->type - 10]);
		printf(" lexeme : \033[33m>\033[0m%s\033[33m<\033[0m \n", token->lex);
		printf(" \\----------------------/ \n");
		token = token->next;
	}
	printf("\033[33m\t### END ### \033[0m \n");
}
