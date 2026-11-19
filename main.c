/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:23:48 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/19 11:38:48 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "ops.h"
#include "helpers.h"
#include "algo_sort.h"
#include <stdio.h>

double	compute_disorder(t_stack *a)
{
	size_t	mistakes;
	size_t	total_pairs;
	size_t	i;
	size_t	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i + 1 < (a->size))
	{
		j = i + 1;
		while (j < a->size)
		{
			total_pairs++;
			if (a->values[i] > a->values[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0);
	return (mistakes / total_pairs);
}

static char *bench_algo(t_data d)
{
	char	*str;

	if (d.algo == 1)
		str = "Simple / O(n²)";
	else if (d.algo == 2)
		str = "Medium / O(n\u221An)";
	else if (d.algo == 3)
		str = "Complex / O(n log n)";
	else
		str = "Adaptive / O(n\u221An)";
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

static void	print_bench(t_data d)
{
	print_disorder(d.disorder);
	ft_printf("[bench] strategy: %s\n", bench_algo(d));
	// ft_printf("[bench] total_ops:\n", /*count_ops(&count)*/);
	ft_printf("[bench] sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n", 
			d.count.sa, d.count.sb, d.count.ss, d.count.pa, d.count.pb);
	ft_printf("[bench] ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n",
			d.count.ra, d.count.rb, d.count.rr, d.count.rra, d.count.rrb, d.count.rrr);
}

int main(int ac, char **av)
{
	t_data 	d;
	int	i = 0;

	if (ac <= 2)
	{
		write (2, "Error\n", 6);
		return 0;
	}
	d.init = ft_init(&d, ac, av);
	if (!d.init)
		write (2, "Init\n", 6);
	else
	{
		ft_normalize(&d.a);
		d.disorder = compute_disorder(&d.a);
		butterfly_sort(&d.a, &d.b, &d.count);
		i = d.b.size - 1;
		ft_printf("\n----------------------\n\n");
		while (i > -1)
		{
			ft_printf("%d\t", d.a.values[i]);
			ft_printf("%d\n", d.b.values[i]);
			i--;
		}
		// handle_algo(d);
		if (d.bench)
			print_bench(d);
	}
	return 42;
}
