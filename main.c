/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:23:48 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/16 11:28:21 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ops.h"
#include <stdio.h>
#include <stdlib.h>

int main(/*int ac, char **av*/)
{
	int i = 13;
	int	*ta = malloc(sizeof(int *) * 14);
	int	*tb = malloc(sizeof(int *) * 14);

	// ta[14] = 1231;
	ta[13] = 90;
	ta[12] = -896123;
	ta[11] = 134561;
	ta[10] = -6754;
	ta[9] = 23;
	ta[8] = 1242;
	ta[7] = -157;
	ta[6] = 1000321;
	ta[5] = -2147483648;
	ta[4] = 2147483647;
	ta[3] = 907812;
	ta[2] = -4421;
	ta[1] = 3231;
	ta[0] = 6666666;
	t_stack a = {ta, 10, 14};
	t_stack b = {tb, 0, 14};
	t_counter count = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	ft_normalize(&a);
	printf("-----------------------\n");
	while (i > -1)
	{
		printf("%d", a.values[i]);
		printf("\t%d\n", b.values[i]);
		i--;
	}
	printf("-----------------------\n");
	printf("sa: %d, sb: %d, pa: %d, pb: %d, ra: %d, rb: %d, rra: %d, rrb: %d, \nss: %d, rr: %d, rrr: %d", 
			count.sa, count.sb, count.pa, count.pb, count.ra, count.rb, count.rra, count.rrb, count.ss, count.rr, count.rrr);
	return 42;
}
