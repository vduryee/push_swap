/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:23:48 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/23 15:13:16 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "helpers.h"
#include "ops.h"
#include "algo_sort.h"

static void handle_algo (t_data *d)
{
	if (d->algo == 1)
		insert_sort(d);
	else if (d->algo == 2)
		butterfly_sort(&d->a, &d->b, &d->count);
	// else if (d.algo == 3)
	// 	radix_sort(&d);
	// else if (d.algo == 0)
	// 	adaptive_sort(&d);
}

int main(int ac, char **av)
{
	t_data 	d;
	int	i = 0;

	if (ac <= 1)
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
		handle_algo(&d);
		//for debug purposes
		i = ac - 4;
		ft_printf("\n----------------------\n\n");
		while (i > -1)
		{
			ft_printf("%d\t", d.a.values[i]);
			ft_printf("%d\n", d.b.values[i]);
			i--;
		}
		//remove until next comment above before push
		if (d.bench)
			print_bench(d);
	}
	return (0);
}
