/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:23:48 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/13 12:25:50 by vduryee          ###   ########.fr       */
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

	// rotate(&a);
	// push(&a, &b);
	// rev_rotate(&a);
	// push(&a, &b);
	// rev_rotate(&a);
	// push(&a, &b);
	push(&a, &b);
	push(&a, &b);
	// drev_rotate(&a, &b);

	rev_rotate(&a);
	while (i > -1)
	{
		printf("%d", a.values[i]);
		printf("\t%d\n", b.values[i]);
		i--;
	}
	return 42;
}
