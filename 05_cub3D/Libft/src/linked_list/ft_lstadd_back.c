/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:37:09 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/16 12:22:08 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
	if (lst && newlst)
	{
		if (*lst)
			ft_lstlast(*lst)->next = newlst;
		else
			*lst = newlst;
	}
	newlst->next = NULL;
}
