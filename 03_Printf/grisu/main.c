/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:22:19 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/24 09:35:56 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../grisu.h"
#include <stdio.h>

void ft_clearBuff(char *buff)
{
	int i;

	i = -1;
	while(++i < 100)
		buff[i] = '\0';
}

int		main(void)
{
	char	str[100];
	double	val;
	int		k;
	int		len;
	
	len = 0;
	k = 0;
	ft_clearBuff(str);
		
	printf("\n\n###############################################################\n\n");

	val = 0.1;
	printf("  val: %.18e\n", val);
	printf("   val: %f\n", val);
	ft_grisu(val, str);
	ft_grisu2(val, str, &len, &k);
	ft_clearBuff(str);
	val = 0.3;
	printf("  val: %.18e\n", val);
	printf("   val: %f\n", val);
	ft_grisu(val, str);
	ft_grisu2(val, str, &len, &k);
	ft_clearBuff(str);
	val = 1.25;
	printf("  val: %.18e\n", val);
	printf("   val: %f\n", val);
	ft_grisu(val, str);
	ft_grisu2(val, str, &len, &k);
	ft_clearBuff(str);
	val = 1.3;
	printf("  val: %.18e\n", val);
	printf("   val: %f\n", val);
	ft_grisu(val, str);
	ft_grisu2(val, str, &len, &k);
	val = -1.25;
	printf("  val: %.18e\n", val);
	printf("   val: %f\n", val);
	ft_grisu(val, str);
	ft_grisu2(val, str, &len, &k);
	ft_clearBuff(str);
	val = 1.2557899621475;
	printf("  val: %.18e\n", val);
	printf("   val: %f\n", val);
	ft_grisu(val, str);
	ft_grisu2(val, str, &len, &k);
	ft_clearBuff(str);
	val = -1.2557899621475;
	printf("  val: %.18e\n", val);
	printf("   val: %f\n", val);
	ft_grisu(val, str);
	ft_grisu2(val, str, &len, &k);
	ft_clearBuff(str);
	val = 50000000;
	printf("  val: %.18e\n", val);
	printf("   val: %f\n", val);
	ft_grisu(val, str);
	ft_grisu2(val, str, &len, &k);
	ft_clearBuff(str);
	val = 547963257157715875669465852.0145;
	printf("  val: %.18e\n", val);
	printf("   val: %f\n", val);
	ft_grisu(val, str);
	ft_grisu2(val, str, &len, &k);
	ft_clearBuff(str);
}
