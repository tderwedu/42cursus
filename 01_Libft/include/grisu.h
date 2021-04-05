/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grisu.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:47:56 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/05 21:51:50 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRISU_H
# define GRISU_H

# include "libft.h"

t_fp			ft_cachedpower(int k);
int				ft_kcomp(int e, int alpha);
void			ft_digit_gen_no_div(t_fp fp, char *buff, int prec);

#endif
