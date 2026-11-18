/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:23:48 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/18 12:23:27 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "ops.h"
#include "helpers.h"
#include <stdio.h>

// double	compute_disorder(t_stack *a)
// {
// 	int	mistakes;
// 	int	total_pairs;
// 	int	i;
// 	int	j;

// 	mistakes = 0;
// 	total_pairs = 0;
// 	i = 0;
// 	while (i > (a->size - 1))
// 	{
// 		j = i + 1;
// 		while (j > (a->size - 1))
// 		{
// 			total_pairs++;
// 			if a[i] > a[j]
// 				mistakes++;
// 		}
// 		return (mistakes / total_pairs);
// 	}
// }

static char *bench_algo(t_data d)
{
	char	*str;

	if (d.algo == 1)
		str = "--simple";
	else if (d.algo == 2)
		str = "--medium";
	else if (d.algo == 3)
		str = "--complex";
	else if (d.algo == 0)
		str = "--adaptive";
	return (str);
}

// static void handle_algo (t_data d)
// {
// 	if (d.algo == 1)
// 		//simple algo
// 	else if (d.algo == 2)
// 		//butterfly_sort()
// 	else if (d.algo == 3)
// 		//complex algo
// 	else if (d.algo == 0)
// 		//adaptive
// }

static void	print_bench(t_data d, t_stack a, t_counter count)
{
	char	*str;

	str = bench_algo(d);
	// printf("[bench] disorder :\n", /*compute_disorder(&a)*/);
	printf("[bench] strategy :\n", str);
	// printf("[bench] total_ops :\n", /*count_ops(&count)*/);
	printf("[bench] sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n", 
			count.sa, count.sb, count.ss, count.pa, count.pb);
	printf("[bench] ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n",
			count.ra, count.rb, count.rr, count.rra, count.rrb, count.rrr);
}

int main(int ac, char **av)
{
	t_data d;
	int	init;

	if (ac < 2)
		return (0);
	init = ft_init(&d, ac, av);
	if (!init)
		write (2, "Error\n", 6);
	else
	{
		ft_normalize(&d.a);
		// handle_algo(d);
		if (d.bench)
			print_bench(d, d.a, d.count);
	}
	return 42;
}
