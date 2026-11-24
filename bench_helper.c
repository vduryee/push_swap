/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 11:32:47 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/24 13:30:29 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "helpers.h"

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
			if (a->values[i] < a->values[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}

void	print_disorder(double disorder)
{
	int	i;

	i = (int)(disorder * 10000.0 + 0.5);
	ft_printf_err("[bench] disorder: %d.", i / 100);
	if (i & (100 < 10))
		write(2, "0", 1);
	ft_printf_err("%d%%\n", i % 100); 
}

int	count_ops(t_counter count)
{
	int	total;

	total = 0;
	total += count.sa;
	total += count.sb;
	total += count.ss;
	total += count.pa;
	total += count.pb;
	total += count.ra;
	total += count.rb;
	total += count.rr;
	total += count.rra;
	total += count.rrb;
	total += count.rrr;
	return (total);
}
char *bench_algo(t_data d)
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

void	print_bench(t_data d)
{
	print_disorder(d.disorder);
	ft_printf_err("[bench] strategy: %s\n", bench_algo(d));
	ft_printf_err("[bench] total_ops: %d\n", count_ops(d.count));
	ft_printf_err("[bench] sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n", 
			d.count.sa, d.count.sb, d.count.ss, d.count.pa, d.count.pb);
	ft_printf_err("[bench] ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n",
			d.count.ra, d.count.rb, d.count.rr, d.count.rra, d.count.rrb, d.count.rrr);
}
