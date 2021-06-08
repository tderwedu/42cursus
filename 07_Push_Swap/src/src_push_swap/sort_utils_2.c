/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:59:39 by tderwedu          #+#    #+#             */
/*   Updated: 2021/06/08 11:42:24 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_ordered(t_stk *stk, int size)
{
	t_link	*ptr;

	ptr = stk->stk_b;
	while (--size)
	{
		if (ptr->val > ptr->next->val)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
