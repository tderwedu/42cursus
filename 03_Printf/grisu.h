/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grisu.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:47:56 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/17 21:37:36 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRISU_H
# define GRISU_H

# include <stdint.h>

# define SIGN_MASK	0x8000000000000000
# define EXPO_MASK	0x7FF0000000000000
# define MANT_MASK	0x000FFFFFFFFFFFFF
# define HIDDEN_BIT	0x0010000000000000
# define D1_LOG2_10 0.30102999566398114
# define EXPO_BIAS	0x433
# define EXPO_SIZE	11
# define MANT_SIZE	52
# define FP_Q		64
# define ALPHA		-35
# define GAMMA		-32

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
**	MATH
*/

double			ft_ceil(double x);
double			ft_floor(double x);

/*
**	t_fp struct
*/

t_fp			ft_double2fp(double d);
double			ft_fp2d(t_fp fp);
uint64_t		ft_d2i_64(double d);
t_fp			ft_minus_fp(t_fp x, t_fp y);
t_fp			ft_multiply_fp(t_fp x, t_fp y);
t_fp			ft_normalize_fp(t_fp fp, int hb);

/*
**	Grisu
*/

void			ft_grisu(double v, char *buff);
void			ft_grisu2(double v, char *buff, int *length, int *k);
t_fp			ft_cachedpower(int k);
int				ft_kcomp(int e, int alpha, int gamma);

void			ft_digit_gen_no_div(t_fp fp, char* buff);
void			ft_digit_gen(t_fp w_p, t_fp delta, char* buff, int* len, int* k);
void			ft_normalized_boundaries(double v, t_fp *m_m, t_fp *m_p);

#endif
