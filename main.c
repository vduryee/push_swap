/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:23:48 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/17 23:22:09 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "ops.h"
#include "helpers.h"
#include <stdio.h>

double	compute_disorder(t_stack *a)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i > (a->size - 1))
	{
		j = i + 1;
		while (j > (a->size - 1))
		{
			total_pairs++;
			if a[i] > a[j]
				mistakes++;
		}
		return (mistakes / total_pairs);
	}
}

void	bench(t_stack a, t_counter count, char **av)
{
	printf("[bench] disorder :\n", /*compute_disorder(&a)*/);
	printf("[bench] strategy :\n", av[1]);
	printf("[bench] total_ops :\n", /*count_ops(&count)*/);
	printf("[bench] sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n", 
			count.sa, count.sb, count.ss, count.pa, count.pb);
	printf("[bench] ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n",
			count.ra, count.rb, count.rr, count.rra, count.rrb, count.rrr);
}

int main(int ac, char **av)
{
	ft_initialize(ac, av);
	ft_normalize(&a);
	printf("-----------------------\n");
	i = ac - 2;
	while (i > -1)
	{
		printf("%d", a.values[i]);
		printf("\t%d\n", b.values[i]);
		i--;
	}
	printf("-----------------------\n");
	bench(a, count, av[1]);
	return 42;
}
