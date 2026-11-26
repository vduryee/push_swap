/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 14:47:16 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/26 11:19:53 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "helpers.h"

int	has_whitespace(char **tab)
{
	int		i;
	char	*s;

	i = 1;
	while (tab[i])
	{
		s = tab[i];
		while (*s >= '0' && *s <= '9')
			s++;
		while (*s)
		{
			if (*s == 32 || (*s >= 9 && *s <= 13))
				return (i);
			s++;
		}
		i++;
	}
	return (0);
}

int is_space_only(char *s)
{
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			return (0);
		s++;
	}
	return (1);
}

size_t	count_words(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_tab(char **tab)
{
	size_t	i;

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
