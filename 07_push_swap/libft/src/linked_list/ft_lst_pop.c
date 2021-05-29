/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:03:35 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/11 14:34:11 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_pop(t_list *lst, void (*del)(void *))
{
	t_list	*next;

	if (lst)
	{
		next = lst->next;
		if (del)
			del(lst->content);
		free(lst);
		return (next);
	}
	return (NULL);
}
