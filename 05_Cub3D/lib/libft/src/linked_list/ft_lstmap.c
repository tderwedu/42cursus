/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:39:57 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/17 14:39:11 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *))
{
	t_list	*newlist;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	newlist = ft_lstnew(f(lst->content));
	if (!newlist)
		return (NULL);
	start = newlist;
	lst = lst->next;
	while (lst)
	{
		newlist->next = malloc(sizeof(t_list));
		if (!newlist->next)
		{
			ft_lstclear(&start, d);
			return (NULL);
		}
		newlist = newlist->next;
		newlist->content = f(lst->content);
		lst = lst->next;
	}
	newlist->next = NULL;
	return (start);
}
