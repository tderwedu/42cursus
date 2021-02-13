/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:39:57 by tderwedu          #+#    #+#             */
/*   Updated: 2021/01/18 22:45:04 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *))
{
	t_list	*newlist;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	if (!(newlist = ft_lstnew(f(lst->content))))
		return (NULL);
	start = newlist;
	while ((lst = lst->next))
	{
		if (!(newlist->next = malloc(sizeof(t_list))))
		{
			ft_lstclear(&start, d);
			return (NULL);
		}
		newlist = newlist->next;
		newlist->content = f(lst->content);
	}
	newlist->next = NULL;
	return (start);
}
