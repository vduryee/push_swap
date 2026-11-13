/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:23:48 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/13 15:58:04 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"
#include "ops.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 4;
	int	*ta = malloc(sizeof(int *) * 5);
	int	*tb = malloc(sizeof(int *) * 5);

	ta[4] = -2;
	ta[3] = 907812;
	ta[2] = -4421;
	ta[1] = 3231;
	ta[0] = 6666666;
	t_stack a = {ta, 5, 5};
	t_stack b = {tb, 0, 5};
	t_counter count = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	// rotate(&a);
	// push(&a, &b);
	// rev_rotate(&a);
	// push(&a, &b);
	// rev_rotate(&a);
	// push(&a, &b);
	push(&a, &b, &count, 'a');
	// push(&a, &b);
	// drev_rotate(&a, &b);
	// rev_rotate(&a);
	swap(&a, &count, 'a');
	swap(&a, &count, 'a');
	swap(&a, &count, 'a');
	swap(&a, &count, 'a');
	swap(&a, &count, 'a');
	rotate(&a, &count, 'a');
	rotate(&a, &count, 'a');
	rotate(&a, &count, 'a');
	rotate(&a, &count, 'a');
	drotate(&a, &b, &count);
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
