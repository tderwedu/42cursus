/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_shadow_effect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:33:06 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/03 23:34:57 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int	rc_shadow_effect(int color, double dist)
{
	int	r;
	int	g;
	int	b;
	
	r = (color >> 16) & 0xff;
	g = (color >> 8) & 0xff;
	b = (color) & 0xff;
	if (dist < 2.0)
	{
		// dist += 15.0;
		r = ((int)(r + 32.0 - 16.0 * dist) & 0xff);
		g = ((int)(g + 16.0  - 8.0 * dist) & 0xff);
		// b = ((int)(b + 0.0 / dist) & 0xff);
		ft_printf("%i | %i | %i\n", r, g ,b);
	}
	else
	{
		dist -= 1.0;
		r = ((int)(r / dist) & 0xff);
		g = ((int)(g / dist) & 0xff);
		b = ((int)(b / dist) & 0xff);
	}
	return ((r << 16) | (g << 8) | b);
}

// int	rc_shadow_effect(int color, double dist)
// {
// 	int	r;
// 	int	g;
// 	int	b;
	
// 	r = (color >> 16) & 0xff;
// 	g = (color >> 8) & 0xff;
// 	b = (color) & 0xff;
// 	dist += 3.0;
// 	// if (dist > 2.5)
// 	// {
// 		r = ((int)(r / dist) & 0xff);
// 		g = ((int)(g / dist) & 0xff);
// 		b = ((int)(b / dist) & 0xff);
// 	// }
// 	return ((r << 16) | (g << 8) | b);
// }

// int	rc_shadow_effect(int color, double dist)
// {
// 	int	r;
// 	int	g;
// 	int	b;
	
// 	r = (color >> 16) & 0xff;
// 	g = (color >> 8) & 0xff;
// 	b = (color) & 0xff;
// 	dist -= 1.0;
// 	if (dist > 1.0)
// 	{
// 		r = ((int)(r / dist) & 0xff);
// 		g = ((int)(g / dist) & 0xff);
// 		b = ((int)(b / dist) & 0xff);
// 	}
// 	return ((r << 16) | (g << 8) | b);
// }
