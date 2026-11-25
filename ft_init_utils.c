/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 14:47:16 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/25 15:05:08 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "helpers.h"

int	has_whitespace(const char *s)
{
	while (*s)
	{
		if ((*s == 32) || (*s >= 9 && *s <= 13))
			return (1);
		s++;
	}
	return (0);
}

size_t count_words(char **tab)
{
	size_t i;
	
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void free_tab(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
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
