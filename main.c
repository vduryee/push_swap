/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:23:48 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/19 12:32:11 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "ops.h"
#include "helpers.h"
#include "algo_sort.h"

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

int main(int ac, char **av)
{
	t_data 	d;
	int	i = 0;

	if (ac <= 2)
	{
		write (2, "Error\n", 6);
		return (0);
	}
	d.init = ft_init(&d, ac, av);
	if (!d.init)
		write (2, "Init\n", 5);
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
	return (0);
}
