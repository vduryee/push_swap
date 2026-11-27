/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_more_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 10:30:57 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/27 11:10:30 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "helpers.h"

int	fill_stack(t_stack *a, size_t n, char **args)
{
	size_t	i;
	size_t	j;
	int		save;

	i = 0;
	while (n > i)
	{
		if (!conv_int(args[i], &save))
			return (0);
		j = 0;
		while (i > j)
		{
			if (a->values[n - 1 - j] == save)
				return (0);
			j++;
		}
		a->values[n - 1 - i] = save;
		i++;
	}
	a->size = n;
	return (1);
}

int	algo_first_flag(t_data *d, int ac, char **av)
{
	int	fst;

	fst = 1;
	d->algo = algo_selector(av[1]);
	d->bench = 0;
	if (d->algo != -1)
	{
		fst = 2;
		if ((ac > 2) && bench_check(av[2]))
		{
			d->bench = 1;
			fst = 3;
		}
	}
	else
		d->algo = 0;
	return (fst);
}

int	bench_first_flag(t_data *d, int ac, char **av)
{
	int	fst;

	fst = 2;
	d->algo = 0;
	d->bench = 1;
	if ((ac > 2) && algo_selector(av[2]) != -1)
	{
		d->algo = algo_selector(av[2]);
		fst = 3;
	}
	return (fst);
}
