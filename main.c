/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:23:48 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/25 17:38:58 by alegaspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "helpers.h"
#include "ops.h"
#include "algo_sort.h"

static void	handle_algo(t_data *d)
{
	if (d->algo == 1)
		insert_sort(d);
	else if (d->algo == 2)
		butterfly_sort(d);
	// else if (d.algo == 3)
	// 	radix_sort(&d);
	else if (d->algo == 0 || d->algo == -1)
		adaptive_sort(d);
}

int	main(int ac, char **av)
{
	t_data	d;
	
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
		if (d.disorder)
		{
			handle_algo(&d);
			if (d.bench)
				print_bench(d);
		}
	}
	free(d.a.values);
	free(d.b.values);
	return (0);
}
