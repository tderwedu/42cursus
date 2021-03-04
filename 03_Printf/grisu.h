/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grisu.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:47:56 by tderwedu          #+#    #+#             */
/*   Updated: 2021/03/04 11:00:28 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRISU_H
# define GRISU_H

# include <stdint.h>
# include "mini_libft.h"

# define SIGN_MASK	0X8000000000000000
# define EXPO_MASK	0X7FF0000000000000
# define MANT_MASK	0X000FFFFFFFFFFFFF
# define HIDDEN_BIT	0X0010000000000000
# define D1_LOG2_10	0.30102999566398114
# define EXPO_BIAS	0X433
# define EXPO_SIZE	11
# define MANT_SIZE	52
# define INF_NAN	0X3CC
# define FP_Q		64
# define ALPHA		-63
# define GAMMA		-60

typedef union	u_d2i_64
{
	double		d;
	uint64_t	i;
}				t_d2i_64;

typedef struct	s_fp
{
	int			sign;
	int			exp;
	uint64_t	man;
}				t_fp;

/*
**	t_fp struct
*/

t_fp			ft_double2fp(double d);
double			ft_fp2double(t_fp fp);
uint64_t		ft_double2int_64(double d);
t_fp			ft_minus_fp(t_fp x, t_fp y);
t_fp			ft_multiply_fp(t_fp x, t_fp y);
t_fp			ft_normalize_fp(t_fp fp, int hb);

/*
**	Grisu
*/

t_fp			ft_cachedpower(int k);
int				ft_kcomp(int e, int alpha);
void			ft_digit_gen_no_div(t_fp fp, char *buff, int prec);

#endif
