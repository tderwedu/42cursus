/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expansion.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:33:45 by tderwedu          #+#    #+#             */
/*   Updated: 2021/09/21 17:12:21 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORD_EXPANSION_H
# define WORD_EXPANSION_H

# include "parser.h"
# include "libft.h"

typedef struct s_word_exp
{
	t_cst	*cst;
	int		quoted;
	
}				t_word_exp;

#endif