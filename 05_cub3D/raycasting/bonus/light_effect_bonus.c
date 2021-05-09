/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_effect_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 10:32:33 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/09 10:34:21 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int	rc_shadow_effect(int color, double dist)
{
	t_ui	r;
	t_ui	g;
	t_ui	b;
	
	r = (color >> 16) & 0xff;
	g = (color >> 8) & 0xff;
	b = (color) & 0xff;
	if (dist < 2.0)
	{
		r = (r + 32 - (t_ui)(16.0 * dist));
		if (r > 255)
			r = 255;
		g = (g + 16 - (t_ui)(08.0 * dist));
		if (g > 255)
			g = 255;
	}
	else
	{
		dist -= 1.0;
		r = ((t_ui)(r / dist) & 0xff);
		g = ((t_ui)(g / dist) & 0xff);
		b = ((t_ui)(b / dist) & 0xff);
	}
	return ((r << 16) | (g << 8) | b);
}

// int	rc_shadow_effect(int color, double dist)
// {
// 	t_ui	r;
// 	t_ui	g;
// 	t_ui	b;
	
// 	r = (color >> 16) & 0xff;
// 	g = (color >> 8) & 0xff;
// 	b = (color) & 0xff;
// 	dist += 3.0;
// 	r = ((t_ui)(r / dist) & 0xff);
// 	g = ((t_ui)(g / dist) & 0xff);
// 	b = ((t_ui)(b / dist) & 0xff);
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
